/** \file SerOut.cc
 * Telemetry transmitter
 */
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include "SerOut.h"
#include "nortlib.h"
#include "nl_assert.h"


serout_data_client *serout_data_client::DCp = 0;
const char *serout_data_client::tm_port = "/dev/ser1";
int serout_data_client::baud = 115200;

void set_serout_port(const char *port) {
  serout_data_client::tm_port = port;
}

void set_serout_baud(int baudrate) {
  serout_data_client::baud = baudrate;
}

serout_data_client::serout_data_client(int bufsize_in, int fast,
      int non_block) :
      data_client(bufsize_in, fast, non_block) {
  ser_fd = open( tm_port, O_WRONLY|O_CREAT, 0664 );
  if ( ser_fd < 0 ) {
    nl_error( 3,
      "Error %d opening telemetry port %s: %s", errno, tm_port,
      strerror(errno)
    );
  } else {
    struct termios termios_p;

    if ( tcgetattr( ser_fd, &termios_p) ) {
      if (errno == ENOTTY) {
        nl_error(1, "%s is not a serial port", tm_port);
      } else {
        nl_error( 2, "Error on tcgetattr: %s", strerror(errno) );
      }
    } else {
      termios_p.c_iflag = 0;
      termios_p.c_lflag &= ~(ECHO|ICANON|ISIG|ECHOE|ECHOK|ECHONL);
      termios_p.c_cflag = CLOCAL|CREAD|CS8;
      termios_p.c_cflag &= ~HUPCL;
      termios_p.c_oflag &= ~(OPOST|ONLCR);
      termios_p.c_ispeed = termios_p.c_ospeed = baud;
      if ( tcsetattr(ser_fd, TCSANOW, &termios_p) )
        nl_error( 2, "Error on tcsetattr: %s", strerror(errno) );
    }
  }

  DCp = this;

  row_len = tm_info.tm.nbminf;
  row_buf = (row_buf_t *)nl_new_memory(row_len);
  row_offset = row_len;
  Synch = 0;
}

void serout_data_client::init_synch(uint16_t synchval) {
  Synch = synchval;
}

/**
 * @param MFCtr
 * @param raw The raw homerow data without the leading MFCtr or
 *    trailing Synch
 * @param Synch
 */
void serout_data_client::send_row(unsigned short MFCtr,
                                  const unsigned char *raw) {
  if (flush_row()) return; // abandon data
  memcpy(&(row_buf->row[0]), &MFCtr, 2);
  memcpy(&(row_buf->row[2]), raw, tm_info.tm.nbminf-4);
  memcpy(&(row_buf->row[row_len-2]), &Synch, 2);
  row_offset = 0;
  if (flush_row()) return;
}

/**
 * @return non-zero if the row did not empty completely
 */
int serout_data_client::flush_row() {
  if (row_offset < row_len) {
    int nb = row_len - row_offset;
    int rv = write(ser_fd, &row_buf->row[row_offset], nb);
    if (rv < 0) {
      nl_error(3, "Error %d from write", errno);
    } else if (rv < nb) {
      row_offset += rv;
      return 1;
    } else {
      row_offset = row_len;
    }
  }
  return 0;
}
