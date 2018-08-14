/** @file serin.cc
 * @brief Reads telemetry data from a serial port and writes to TMbfr
 */
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/select.h>
#include <stdint.h>
#include <unistd.h>
#include "serin.h"
#include "nortlib.h"
#include "oui.h"
#include "nl_assert.h"
#include "tm.h"

#define RDR_BUFSIZE 16384

static const char *opt_basepath = ".";
static int opt_autostart;
static int opt_regulate;
static char *opt_serdev;
static int opt_baud = 2400;

/** Options we need to support:

        -A : autostart without regulation
        -a : autostart with regulation
        -b baud : set serial baud rate (2400)
        -d path : serial device or simulation file
        -P path : path to log directories

 */
void serin_init( int argc, char **argv ) {
  int c;

  optind = OPTIND_RESET; /* start from the beginning */
  opterr = 0; /* disable default error message */
  while ((c = getopt(argc, argv, opt_string)) != -1) {
    switch (c) {
      case 'A':
        opt_autostart = 1;
        opt_regulate = 0;
        break;
      case 'a':
        opt_autostart = 1;
        opt_regulate = 1;
        break;
      case 'b':
        opt_baud = atoi(optarg);
        break;
      case 'd':
        opt_serdev = optarg;
        break;
      case 'P':
        opt_basepath = optarg;
        break;
      case '?':
        nl_error(MSG_FATAL, "Unrecognized Option -%c", optopt);
    }
  }
}

int main( int argc, char **argv ) {
  oui_init_options( argc, argv );
  nl_error(MSG, "Startup");
  load_tmdac(opt_basepath);
  int nQrows = RDR_BUFSIZE/tmi(nbrow);
  if (nQrows < 2) nQrows = 2;
  serin_t serin(nQrows, nQrows/2, opt_basepath );
  serin.data_generator::init(0);
  seteuid(getuid());
  serin.control_loop();
  nl_error(MSG, "Shutdown");
}

static uint16_t lcm( uint16_t ain, uint16_t bin ) {
  short int t, a, b;
  // first calculate the gcd via the euclidean algorithm
  a = ain;
  b = bin;
  while ( b != 0 ) {
    t = b;
    b = a % b;
    a = t;
  }
  assert(a != 0);
  a = ain/a;
  return a * bin;
}

/**
 * @brief Constructor for serin_t class
 * @param nQrows Passed to data_generator initializer
 * @param low_water Passed to data_generator initializer
 * @path The directory where the SSP scan directory should be created
 */
serin_t::serin_t(int nQrows, int low_water, const char *path) :
    data_generator(nQrows, low_water) {
  it_blocked = 0;
  ot_blocked = 0;
  if ( sem_init( &it_sem, 0, 0) || sem_init( &ot_sem, 0, 0 ) )
    nl_error(MSG_FATAL, "Semaphore initialization failed" );
  int rv = pthread_mutex_init( &dq_mutex, NULL );
  if ( rv )
    nl_error(MSG_FATAL, "Mutex initialization failed: %s",
            strerror(errno));
  // init_tm_type();
  // nl_assert(input_tm_type == TMTYPE_DATA_T3);
  regulated = opt_regulate;
  autostart = opt_autostart;
  locked_by_file = 0;
  locked_by_line = 0;
  synch_lsb = tmi(synch) & 0xFF;
  synch_msb = (tmi(synch) >> 8) & 0xFF;
  // scan_synch_lsb = (~synch_lsb) & 0xFF;
  // scan_synch_msb = (~synch_msb) & 0xFF;
  have_synch = false;
  have_tstamp = false;
  next_minor_frame = 0;
  // scan_active = false;
  // cur_scan = 0;
  // cur_scansize = 0;
  // cur_scanmfc_offset = 0;
  // next_scanmfc = 0;
  uint16_t mfcspermajf = tmi(nrowmajf)/tm_info.nrowminf;
  uint16_t lcmMn = lcm(mfcspermajf,tmi(nsecsper));
  ROLLOVER_MFC = (USHRT_MAX+1L)%lcmMn;

  ser_fd = open( opt_serdev, O_RDONLY|O_NONBLOCK );
  if ( ser_fd < 0 ) {
    nl_error( MSG_FATAL,
      "Error %d opening telemetry port %s: %s", errno, opt_serdev,
      strerror(errno)
    );
  } else {
    if ( tcgetattr( ser_fd, &termios_s) ) {
      if (errno == ENOTTY) {
        nl_error(MSG_WARN, "%s is not a serial port", opt_serdev);
      } else {
        nl_error(MSG_FAIL, "Error on tcgetattr: %s", strerror(errno) );
      }
      is_terminal = false;
    } else {
      termios_s.c_iflag = 0;
      termios_s.c_lflag &= ~(ECHO|ICANON|ISIG|ECHOE|ECHOK|ECHONL);
      termios_s.c_cflag = CLOCAL|CREAD|CS8;
      termios_s.c_oflag &= ~(OPOST|ONLCR);
      termios_s.c_ispeed = termios_s.c_ospeed = opt_baud;
      if ( tcsetattr(ser_fd, TCSANOW, &termios_s) )
        nl_error(MSG_FAIL, "Error on tcsetattr: %s", strerror(errno) );
      update_termios(tmi(nbminf));
      is_terminal = true;
    }
  }
}

static void pt_create( void *(*func)(void *), pthread_t *thread, void *arg ) {
  int rv = pthread_create( thread, NULL, func, arg );
  if ( rv != EOK )
    nl_error(MSG_FATAL,"pthread_create failed: %s", strerror(errno));
}

static void pt_join( pthread_t thread, const char *which ) {
  void *value;
  int rv = pthread_join(thread, &value);
  if ( rv != EOK )
    nl_error(MSG_ERROR, "pthread_join(%d, %s) returned %d: %s",
       thread, which, rv, strerror(rv) );
  else if ( value != 0 )
    nl_error(MSG_ERROR, "pthread_join(%s) returned non-zero value", which );
  else nl_error(MSG_DBG(0), "%s shutdown", which );
}

void serin_t::control_loop() {
  pthread_t ot, it;
  pt_create( ::output_thread, &ot, this );
  pt_create( ::input_thread, &it, this );
  data_generator::operate();
  pt_join( it, "input_thread" );
  pt_join( ot, "output_thread" );
}

void serin_t::lock(const char *by, int line) {
  int rv = pthread_mutex_lock(&dq_mutex);
  if (rv)
    nl_error(MSG_FATAL, "Mutex lock failed: %s",
            strerror(rv));
  locked_by_file = by;
  locked_by_line = line;
}

void serin_t::unlock() {
  int rv = pthread_mutex_unlock(&dq_mutex);
  if (rv)
    nl_error(MSG_FATAL, "Mutex unlock failed: %s",
            strerror(rv));
}

void serin_t::service_row_timer() {
  lock(__FILE__,__LINE__);
  if ( ot_blocked == OT_BLOCKED_TIME ||
       (!started && ot_blocked == OT_BLOCKED_STOPPED)) {
    ot_blocked = 0;
    sem_post(&ot_sem);
  }
  unlock();
}

void serin_t::event(enum dg_event evt) {
  lock(__FILE__,__LINE__);
  switch (evt) {
    case dg_event_start:
      if (ot_blocked == OT_BLOCKED_STOPPED) {
        ot_blocked = 0;
        sem_post(&ot_sem);
      }
      break;
    case dg_event_stop:
      if (ot_blocked == OT_BLOCKED_TIME || ot_blocked == OT_BLOCKED_DATA) {
        ot_blocked = 0;
        sem_post(&ot_sem);
      }
      break;
    case dg_event_quit:
      nl_error(MSG, "Quit event" );
      // dc_quit = true;
      if ( ot_blocked ) {
        ot_blocked = 0;
        sem_post(&ot_sem);
      }
      if ( it_blocked ) {
        it_blocked = 0;
        sem_post(&it_sem);
      }
      break;
    case dg_event_fast:
      if ( ot_blocked == OT_BLOCKED_TIME || ot_blocked == OT_BLOCKED_STOPPED ) {
        ot_blocked = 0;
        sem_post(&ot_sem);
      }
      break;
    default:
      break;
  }
  unlock();
}

void *input_thread(void *Reader_ptr ) {
  serin_t *DGr = (serin_t *)Reader_ptr;
  return DGr->input_thread();
}

void *serin_t::input_thread() {
  /**
   * The input thread is only concerned with the serial port input.
   * The output thread handles the command interface and the output
   * to TMbfr. That means we don't see quit when it happens. We could
   * have the output thread throw a signal, but since we don't have
   * pselect(), there is a race condition associated with that.
   * We could set up a separate quit request to the command server
   * for the input thread. That might work. We could also setup an
   * internal pipe and have the output thread write to the input
   * thread.
   * Or we could just have select timeout after 1 second.
   * I will implement the timeout first, optimize later.
   */
  // char mlf_base[PATH_MAX];
  // snprintf(mlf_base, PATH_MAX, "%s/SSP", opt_basepath );
  // mlf = mlf_init( 3, 60, 1, mlf_base, "dat", NULL );
  // cmd_init();

  fd_set readfds, writefds, exceptfds;
  struct timeval tv;
  while (!quit) {
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_ZERO(&exceptfds);
    FD_SET(ser_fd, &readfds);
    int width = ser_fd+1;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    int rc = select(width, &readfds, &writefds, &exceptfds, &tv);
    // rc==0 means timeout, which we ignore
    if ( rc == 0 ) {
      nl_error(MSG, "Timeout reading from ser_fd");
    } else if ( rc < 0 ) {
      if ( errno != EINTR ) {
        nl_error(MSG_FATAL,
          "serin_t::input_thread(): Unexpected error from select: %d", errno);
      }
    } else if (rc > 0) {
      if (FD_ISSET(ser_fd, &readfds)) {
        process_serin();
      }
    }
  }
  return NULL;
}

void serin_t::process_serin() {
  nl_assert(nc < inbuf_size);
  int rv = read(ser_fd, &inbuf[nc], inbuf_size-nc);
  if (rv < 0 && errno != EAGAIN) {
    nl_error(MSG_FATAL, "Error %d on read from ser_fd", errno);
  } else {
    nc += rv;
    nl_error(MSG_DBG(2), "Recd %d chars. nc=%d", rv, nc);
    while (cp + tmi(nbminf) <= nc ) {
      if (have_synch &&
          inbuf[cp+tmi(nbminf)-2] == synch_lsb &&
          inbuf[cp+tmi(nbminf)-1] == synch_msb ) {
        // We have a TM row
        process_row(&inbuf[cp]);
        cp += tmi(nbminf);
      // } else if (
          // have_synch &&
          // inbuf[cp+tmi(nbminf)-2] == scan_synch_lsb &&
          // inbuf[cp+tmi(nbminf)-1] == scan_synch_msb ) {
        // // We have a scan row
        // nl_error(MSG_DBG(2), "scan_row cp,nc = %d,%d", cp, nc);
        // process_scan_row(&inbuf[cp]);
        // cp += tmi(nbminf);
      } else {
        int i;
        if (have_synch) {
          have_synch = false;
          nl_error(MSG_DBG(0), "Lost synch");
        }
        // We need to resynch
        for (i = cp; !have_synch && i+1 < nc; ++i) {
          if (inbuf[i] == synch_lsb &&
              inbuf[i+1] == synch_msb) {
            // Found TM synch
            have_synch = true;
          // } else if (inbuf[i] == scan_synch_lsb &&
              // inbuf[i+1] == scan_synch_msb) {
            // // Found scan synch
            // have_synch = true;
          }
        }
        if (have_synch) {
          int new_cp;
          // i now points to synch_msb
          // nl_error(MSG_DBG(0), "Found synch");
          // This logic ensures new_cp >= cp
          if (++i-cp >= tmi(nbminf)) {
            new_cp = i-tmi(nbminf);
          } else {
            new_cp = i;
          }
          nl_error(MSG_DBG(0), "Found synch, discarding %d bytes",
              new_cp - cp);
          dump_bytes(MSG_DBG(2), cp, new_cp);
          cp = new_cp;
        } else {
          break;
        }
      }
    }
    if (inbuf_size-nc <= tmi(nbminf) &&
        nc-cp > tmi(nbminf)) {
      int cp1 = nc - tmi(nbminf) + 1;
      nl_error(MSG_WARN,
          "Buffer full, no synch, discarding %d bytes",
          cp1 - cp);
      cp = cp1;
    }
    if (nc-cp < tmi(nbminf)) {
      if (nc > cp && cp > 0) {
        memmove(&inbuf[0], &inbuf[cp], nc-cp);
        nc -= cp;
        cp = 0;
      } else if (nc <= cp) {
        nc = cp = 0;
      }
    }
  }
}

void serin_t::process_row(const unsigned char *row) {
  nl_assert(row != 0);
  uint16_t MFCtr = (row[1]<<8) + row[0];
  if (!have_tstamp) {
    // make tstamp with current time and MFCtr
    commit_tstamp(MFCtr, time(NULL));
    have_tstamp = true;
  } else if (MFCtr < next_minor_frame) {
    if (MFCtr < ROLLOVER_MFC) {
      // Just make a new tstamp: must have restarted
      commit_tstamp(MFCtr, time(NULL));
    } else {
      commit_tstamp( 0, tm_info.t_stmp.secs +
        tmi(nsecsper) *
          ((long)USHRT_MAX - tm_info.t_stmp.mfc_num - ROLLOVER_MFC + 1) /
            tmi(nrowsper) );
    }
  } else if (MFCtr > tm_info.t_stmp.mfc_num &&
        MFCtr-tm_info.t_stmp.mfc_num > TS_MFC_LIMIT) {
    // Advance time_stamp by a calculated number of seconds, mfcs
    uint16_t q = (MFCtr - tm_info.t_stmp.mfc_num)/tmi(nrowsper);
    commit_tstamp(tm_info.t_stmp.mfc_num + q*tmi(nrowsper),
      tm_info.t_stmp.secs + tmi(nsecsper) * q);
  }
  for (;;) {
    unsigned char *dest;
    lock(__FILE__,__LINE__);
    int nr = allocate_rows(&dest);
    if (nr > 0) {
      unlock();
      // copy data into the queue and update indexes
      nl_error(MSG_DBG(1), "Transmitting: MFCtr=%04X", MFCtr);
      dump_bytes(MSG_DBG(2), cp, cp+tmi(nbminf));
      memcpy(dest, &inbuf[cp+2], nbQrow);
      commit_rows(MFCtr, 0, 1);
      break;
    } else {
      it_blocked = IT_BLOCKED_DATA;
      unlock();
      sem_wait(&it_sem);
    }
  }
}

// uint16_t serin_t::mfcbytes(uint16_t mfc) {
//   uint16_t m = mfc>>8;
//   uint16_t l = mfc & 0xFF;
//   uint16_t L1 = tmi(nbminf)-3;
//   return((m*256+l+1)*L1 - (m+1)*sizeof(scan_hdr_t));
// }

// Now I need to set every 32-bit word from first_byte to last_byte
// to NAN32.
// void serin_t::nan_fill(uint16_t first_byte, uint16_t last_byte) {
  // if (last_byte+1 < cur_scansize) {
    // nl_error(MSG_WARN, "Scan %u: lost bytes %u-%u",
      // cur_scan, first_byte, last_byte);
  // } else {
    // nl_error(MSG_WARN, "Scan %u: lost from byte %u to end",
      // cur_scan, first_byte);
  // }
  // uint16_t first_word = first_byte/sizeof(uint32_t);
  // uint16_t last_word = last_byte/sizeof(uint32_t);
  // for (uint16_t wordno = first_word; wordno <= last_word; ++wordno) {
    // scanbuf[wordno] = NAN32;
  // }
  // cur_scan_offset = last_byte+1;
// }

// void serin_t::write_scan_file() {
  // nl_assert(scan_active && cur_scan_offset > 0);
  // if (cur_scan_offset < cur_scansize) {
    // nl_error(MSG_DBG(0), "Scan %u last %u bytes lost", cur_scan,
      // cur_scansize - cur_scan_offset);
    // nan_fill(cur_scan_offset, cur_scansize-1);
  // } else {
    // nl_error(MSG_DBG(1), "End of Scan %u", cur_scan);
  // }
  // mlf_set_index(mlf, cur_scan);
  // int fd = mlf_next_fd(mlf);
  // write(fd, &scanbuf[0], cur_scansize);
  // close(fd);
  // scan_active = false;
  // ci_sendfcmd(2, "PhRTG File SSP %lu\n", cur_scan);
  // nl_error(MSG_DBG(0), "Wrote scan %lu to path %s", cur_scan,
    // mlf->fpath);
// }

// void serin_t::process_scan_row(const unsigned char *row) {
  // uint8_t scanmfc = row[tmi(nbminf)-3];
  // uint16_t gap_start = 0;
  // if (scan_active && scanmfc != next_scanmfc) {
    // // we have lost some data
    // //nl_error(MSG_WARN,"Scan %u: Missed some scan rows");
    // // fill in any missing data with NaNs
    // // How many rows are missing? We'll assume the smallest gap
    // uint16_t first_mfc = next_scanmfc ? (next_scanmfc+cur_scanmfc_offset) :
      // cur_scanmfc_offset+256;
    // uint16_t new_mfc = scanmfc+cur_scanmfc_offset;
    // if (new_mfc < first_mfc) {
      // new_mfc += 256;
      // cur_scanmfc_offset += 256;
    // }
    // uint16_t first_byte = mfcbytes(first_mfc-1);
    // nl_assert(first_byte == cur_scan_offset);
    // uint16_t last_byte = mfcbytes(new_mfc) - 1;
    // if (last_byte >= cur_scansize) {
      // write_scan_file();
    // } else {
      // gap_start = cur_scan_offset;
      // cur_scan_offset = last_byte;
    // }
  // }
  // if (scanmfc == 0) {
    // scan_hdr_t *hdr = (scan_hdr_t *)row;
    // if (scan_active) {
      // if (hdr->scannum == cur_scan) {
        // if (hdr->scansize != cur_scansize) {
          // // One or the other was corrupted? Could check
          // // against NS, NC if we've read them
          // nl_error(MSG_ERROR, "Scansize discrepancy: SN:%u size was %u, now %u",
                // cur_scan, cur_scansize, hdr->scansize);
          // scan_active = false;
          // return;
        // }
        // // We're in the right scan and the right size
        // if (hdr->mfctr_offset == cur_scanmfc_offset+256) {
          // // and we're at the right offset
          // cur_scanmfc_offset = hdr->mfctr_offset;
        // } else {
          // // We either missed 255 mfs or mfctr_offset is corrupted
          // nl_error(MSG_ERROR, "SN:%u: Expected mfctr_offset %u received %u",
            // cur_scan, cur_scanmfc_offset+256, hdr->mfctr_offset);
          // scan_active = false;
          // return;
        // }
      // } else {
        // // We must have missed the end of the previous scan
        // // We may have tried to work around this with gap_start
        // if (gap_start > 0) cur_scan_offset = gap_start;
        // write_scan_file();
      // }
    // }
    // if (!scan_active) {
      // if (hdr->mfctr_offset == 0) {
        // cur_scan = hdr->scannum;
        // cur_scansize = hdr->scansize;
        // nl_error(MSG_DBG(1), "Start of Scan %u: %u", cur_scan, cur_scansize);
        // if (cur_scansize > scanbuf_size*sizeof(uint32_t)) {
          // nl_error(MSG_WARN, "SN:%u: Scansize=%u exceeds maximum", cur_scansize);
          // return; // Abandon scan
        // }
        // cur_scanmfc_offset = 0;
        // cur_scan_offset = tmi(nbminf)-sizeof(scan_hdr_t)-3;
        // memcpy(&scanbuf[0], &row[sizeof(scan_hdr_t)], cur_scan_offset);
        // ssp_scan_hdr_t *ssp_hdr = (ssp_scan_hdr_t *)&scanbuf[0];
        // if (ssp_hdr->NWordsHdr != 6) {
          // nl_error(MSG_WARN, "SN:%u: Expected:NWordsHdr=6 Rec'd:%u",
            // cur_scan, ssp_hdr->NWordsHdr);
        // }
        // uint16_t chk_size =
          // sizeof(uint32_t)*(7+ssp_hdr->NChannels*ssp_hdr->NSamples);
        // if (cur_scansize != chk_size) {
          // nl_error(MSG_WARN, "SN:%u: SSP NS=%u,NC=%u does not match scansize:%u",
            // cur_scan, ssp_hdr->NSamples, ssp_hdr->NChannels, cur_scansize);
        // }
        // scan_active = true;
        // next_scanmfc = 1;
        // return;
      // } else {
        // nl_error(MSG_DBG(1), "!active scanmfc=0 mfctr_offset=%u",
          // hdr->mfctr_offset);
      // }
    // } 
  // }
  // if (scan_active) {
    // unsigned char *scan_ptr = (unsigned char *)&scanbuf[0];
    // unsigned short fragsize = tmi(nbminf)-3;
    // if (cur_scan_offset+fragsize > cur_scansize) {
      // fragsize = cur_scansize-cur_scan_offset;
    // }
    // memcpy(&scan_ptr[cur_scan_offset], row, fragsize);
    // if (gap_start > 0) {
      // nan_fill(gap_start, cur_scan_offset-1);
    // }
    // cur_scan_offset += fragsize;
    // next_scanmfc = (scanmfc+1) & 0xFF;
    // if (cur_scan_offset >= cur_scansize) {
      // write_scan_file();
    // }
  // } else {
    // nl_error(MSG_DBG(1), "Scan row while !active: mfc = %d", scanmfc);
  // }
// }

/**
 * @param lvl The MSG level as specified in nortlib.h
 * @param ttl Text prepended to the first row
 * @param start The offset in inbuf of the first character
 * @param end The offset in inbuf one past the last character
 * Outputs as hex the bytes of inbuf from offset start to end-1,
 * limiting the output to 20 bytes per line
 */
void serin_t::dump_bytes(int lvl, int start, int end) {
  char obuf[80];
  int rowoffset, coloffset;
  if (lvl < nl_debug_level) return;
  rowoffset = start;
  coloffset = 0;
  while (rowoffset+coloffset < end) {
    // Output "XX " at coloffset*3
    uint8_t val = inbuf[rowoffset+coloffset];
    uint8_t nibble = (val>>4)&0xF;
    nibble += (nibble<10) ? '0' : ('A'-10);
    obuf[coloffset*3] = nibble;
    nibble = val&0xF;
    nibble += (nibble<10) ? '0' : ('A'-10);
    obuf[coloffset*3+1] = nibble;
    obuf[coloffset*3+2] = ' ';
    if (++coloffset >= 20) {
      obuf[coloffset*3-1] = '\0';
      nl_error(lvl, "%s", obuf);
      rowoffset += coloffset;
      coloffset = 0;
    }
  }
  if (coloffset > 0) {
    obuf[coloffset*3-1] = '\0';
    nl_error(lvl, "%s", obuf);
  }
}

/**
 * This implementation is copied from the collector class.
 */
void serin_t::commit_tstamp(mfc_t MFCtr, time_t time) {
  tm_info.t_stmp.mfc_num = MFCtr;
  tm_info.t_stmp.secs = time;
  data_generator::commit_tstamp(MFCtr, time);
}

/**
 * Adapted from TwisTorr, Horiba. Adjusts the VMIN termios value
 * based on the specific command.
 */
void serin_t::update_termios(int cur_min) {
  if (is_terminal) {
    if (cur_min < 1) cur_min = 1;
    if (cur_min != termios_s.c_cc[VMIN]) {
      termios_s.c_cc[VMIN] = cur_min;
      if (tcsetattr(ser_fd, TCSANOW, &termios_s)) {
        nl_error(MSG_ERROR, "Error from tcsetattr: %s", strerror(errno));
      }
    }
  }
}

void *output_thread(void *Reader_ptr ) {
  serin_t *DGr = (serin_t *)Reader_ptr;
  return DGr->output_thread();
}

void *serin_t::output_thread() {
  for (;;) {
    lock(__FILE__,__LINE__);
    if ( quit ) {
      unlock();
      break;
    }
    if ( ! started ) {
      ot_blocked = OT_BLOCKED_STOPPED;
      unlock();
      sem_wait(&ot_sem);
    } else {
      if ( regulated ) {
        // timed loop
        for (;;) {
          int nr;
          ot_blocked = OT_BLOCKED_TIME;
          unlock();
          sem_wait(&ot_sem);
          lock(__FILE__,__LINE__);
          int breakout = !started || !regulated || quit;
          unlock();
          if (breakout) break;
          transmit_data(1); // only one row
          nr = allocate_rows(NULL);
          // if (allocate_rows(NULL) >= dq_low_water) {
          // The problem with this is that when the
          // queue is wrapping, the largest contiguous
          // block does not change.
          if ( (nr >= dq_low_water) ||
               (nr > 0 && first <= last) ) {
            lock(__FILE__,__LINE__);
            if ( it_blocked == IT_BLOCKED_DATA ) {
              it_blocked = 0;
              sem_post(&it_sem);
            }
            unlock();
          }
          lock(__FILE__,__LINE__); /* needed in the inner loop */
        }
      } else {
        // untimed loop
        for (;;) {
          int breakout = !started || quit || regulated;
          if ( it_blocked == IT_BLOCKED_DATA ) {
            it_blocked = 0;
            sem_post(&it_sem);
          }
          unlock();
          if (breakout) break;
          transmit_data(0);
          lock(__FILE__,__LINE__);
        }
      }
    }
  }
  // signal parent thread that we are quitting
  return NULL;
}

void tminitfunc() {}
