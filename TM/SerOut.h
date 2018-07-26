/** \file serout.h
 * data_client sub class for telemetry
 */
#ifndef SEROUT_H_INCLUDED
#define SEROUT_H_INCLUDED

#include <stdint.h>
#include "DC.h"
#include "mlf.h"

#ifdef __cplusplus

#define EXTRACTION_INIT DC.init_synch(SYNCHVAL);
#define EXTRACTION_ROW send_row(MFCtr, raw);
#define DATA_CLIENT_CLASS serout_data_client

typedef union {
  scan_hdr_t scan_hdr;
  uint8_t row[0];
} row_buf_t;

class serout_data_client : public data_client {
  public:
    serout_data_client(int bufsize_in, int fast = 0, int non_block = 0);
    void init_synch(uint16_t synchval);
    void enqueue_scan(int32_t scannum);
    static serout_data_client *DCp;
    static void set_port(const char *port);
    static const int blocksize = 512;
    static const char *tm_port;
    static const char *base;
    static int baud;
  protected:
    void process_data();
  private:
    int ser_fd;
    uint16_t scan_mfctr, scan_mfctr_offset;
    row_buf_t *row_buf;
    uint16_t row_len, row_offset;
    uint16_t Synch, scan_synch;
    
    int flush_row();
    void send_row(uint16_t MFCtr, const unsigned char *raw);
};

extern "C" {
#endif

/* This is all that is exposed to a C module */
extern void set_serout_port(const char *port);
extern void set_serout_baud(int baudrate);

#ifdef __cplusplus
};
#endif


#endif /* SEROUT_H_INCLUDED */
