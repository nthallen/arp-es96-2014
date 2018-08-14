#include <Selector.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include "oui.h"
#include "uplink.h"
#include "nl_assert.h"

const char *uplink_port;
const char *uplink_addr;

UplinkCmd::~UplinkCmd() {}

int UplinkCmd::ProcessData(int flag) {
  // check that flags is just set to Selector::Sel_Read
  // Parse W:XX\n or exit on no data
  unsigned short cmd;
  nc = cp = 0;
  fillbuf();
  if (nc == 0) return 1; // Implicit quit command
  cmd = 0; // due to bug in not_hex()
  if (not_str("W:") || not_hex(cmd) || not_str("\n")) {
    report_err("Syntax error at column %d", cp);
  } else {
    if (cmd >= 0x100) {
      report_err("Command %u exceeds byte width", cmd);
    } else {
      US->transmit(cmd);
      report_ok();
    }
  }
  return 0;
}

UplinkSer::UplinkSer(const char *port, const char *addr) :
          Ser_Sel(port, O_RDWR|O_NONBLOCK, 80), addr(addr) {
  // Ser_Sel's init will abort if open fails
  // Verify that addr is non-zero and consists of
  // exactly 2 hex digits

  if (addr == 0)
    nl_error(3, "Must specify instrument address");
  if ((!isxdigit(addr[0])) ||
      (!isxdigit(addr[1])) ||
      (addr[2] != '\0'))
    nl_error(3, "Invalid instrument address");

  setup(1200, 8, 'n', 1, 1, 1);
  flush_input();
  // Ser_Sel's init sets flags to Sel_Read
}

UplinkSer::~UplinkSer() {}

/**
 * At the moment, just report anything returned
 * from the CSBF equipment
 */
int UplinkSer::ProcessData(int flag) {
  if (fillbuf()) return 1;
  int n_reported = 0;
  cp = 0;
  while (cp < nc) {
    while (isspace(buf[cp])) ++cp;
    unsigned start = cp;
    while (cp < nc && cp != '\r' && cp != '\n')
      ++cp;
    if (cp > start && (cp == '\r' || cp == '\n')) {
      buf[cp++] = 0;
      nl_error(0, "%s", &buf[start]);
      n_reported = cp;
    }
  }
  consume(n_reported);
  return 0;
}

void UplinkSer::transmit(unsigned short val) {
  char obuf[35];
  // Implement S00yy xxKS00yy xxKS00yy xxK<cr><lf>
  // yy is val, xx is addr.
  int nchars = snprintf(obuf, 35,
    "S00%02X %sKS00%02X %sKS00%02X %sK\r\n",
      val, addr, val, addr, val, addr);
  nl_assert(nchars == 29);
  nl_error(MSG_DBG(0), "Tx: %s", ascii_escape(obuf));
  nchars = write(fd, obuf, 29);
  if (nchars == -1) {
    nl_error(3, "Error %d (%s) from uplink port",
      errno, strerror(errno));
  } else if (nchars < 29) {
    nl_error(3, "Incomplete write on uplink port: %d of 29",
      nchars);
  }
}

int main(int argc, char **argv) {
  oui_init_options(argc, argv);
  nl_error(0, "Starting V1.0");
  { Selector S;
    UplinkSer US(uplink_port, uplink_addr);
    UplinkCmd UC(&US);
    S.add_child(&UC);
    S.add_child(&US);
    S.event_loop();
  }
  nl_error(0, "Terminating");
}
