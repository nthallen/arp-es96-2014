#include "uplink_rcvr.h"
#include "cmdalgo.h"

const char *uplink_port;
const char *uplink_addr;

/**
 * @param port path to the serial port
 * @param addr the 2-digit hex address of the MaCaPs port we are using
 * If addr is 0, we are operating in flight mode where each byte received
 * is treated as a software status command. If an address is specified,
 * then we are operating in ground test mode. In this mode, we can directly
 * connect the GSE uplink port to the flight computer's uplink_rcvr port.
 * uplink_rcvr will check the validity of the data from uplink, and then
 * process the command the same as in flight.
 */
UplinkRcvrSer::UplinkRcvrSer(const char *port, const char *addr) :
          Ser_Sel(port, O_RD|O_NONBLOCK, 80), addr(addr) {
  // Ser_Sel's init will abort if open fails
  // Verify that addr is non-zero and consists of
  // exactly 2 hex digits

  if (addr == 0) {
    this->addr = 0;
    setup(1200, 8, 'N', 1, 1, 1);
  } else {
    if ((!isxdigit(addr[0])) ||
        (!isxdigit(addr[1])) ||
        (addr[2] != '\0'))
      nl_error(3, "Invalid instrument address");
    this->addr = strtoul(addr, 0, 16);
    setup(1200, 8, 'N', 1, 29, 1);
  }

  flush_input();
  if (tcgetattr(fd, &termios_s)) {
    nl_error(2, "Error from tcgetattr: %s", strerror(errno));
  }
  flags = Selector::Sel_Read;
  // Ser_Sel's init sets flags to Sel_Read
}

/**
 * At the moment, just report anything returned
 * from the CSBF equipment
 */
int UplinkRcvrSer::ProcessData(int flag) {
  if (fillbuf()) return 1;
  int n_reported = 0;
  cp = 0;
  while (cp < nc) {
    unsigned short SWStat;
    unsigned short port_addr;
    unsigned int frame_start;
    if (addr) {
      // Implement S00yy xxKS00yy xxKS00yy xxK<cr><lf>
      // yy is val, xx is addr.
      if (not_found('S')) return 0;
      frame_start = cp-1;
      if (not_str("00") ||
          not_hex(SWStat) ||
          not_str(" ") ||
          not_hex(port_addr) ||
          not_str("K") ||
          not_str(&buf[frame_start], 9) ||
          not_str(&buf[frame_start], 9) ||
          not_str("\r\n")) {
        if (cp < nc) {
          consume(cp);
          continue;
        } else {
          // end of input: check for timeout
          consume(frame_start);
          update_termios();
          return 0;
        }
      } else {
        // Frame is OK. Is the address right?
        if (port_addr != addr) {
          report_err("Incorrect port address: Rx:%02X, Exp:%02X", port_addr, addr);
          consume(cp);
          update_termios();
          return 0;
        }
      }
    } else {
      SWStat = buf[cp++];
    }
    ci_sendfcmd(0, 'SWStat Set %d\n', SWStat);
  }
  consume(nc);
  update_termios();
  return 0;
}

/**
 * Adapted from SunTrack. Adjusts the VMIN termios value
 * based on the specific command. This version is incomplete.
 * It adjusts for the request size so we can skip over the RS485 echo,
 * but it does not anticipate any more than the minimal response
 * of 6 characters. We could add command-specific response size
 * as noted in the comments. We could also adjust the VTIME
 * parameter, but it may be redundant, since we have the overriding
 * Selector timeout working for us.
 */
void UplinkRcvrSer::update_termios() {
  // int cur_min = pending->req_sz + pending->min - nc;
  if (nc) {
    if (TO->Expired()) {
      report_err("Timeout");
      nc = cp = 0;
      TO->Clear();
    } else {
      TO->Set(0,200);
    }
  }
  int cur_min = addr ? 29 - nc : 1;
  if (cur_min < 1) cur_min = 1;
  if (cur_min != termios_s.c_cc[VMIN]
      // || pending->time != termios_s.c_cc[VTIME]
        ) {
    termios_s.c_cc[VMIN] = cur_min;
    // termios_s.c_cc[VTIME] = pending->time;
    if (tcsetattr(fd, TCSANOW, &termios_s)) {
      nl_error(2, "Error from tcsetattr: %s", strerror(errno));
    }
  }
  if (TO->Set()) {
    flags |= Selector::Sel_Timeout;
  } else {
    flags &= ~Selector::Sel_Timeout;
  }
}

Timeout *UplinkRcvrSer::GetTimeout() {
  return TO->Set() ? &TO : 0;
}

int main(int argc, char **argv) {
  oui_init_options(argc, argv);
  nl_error(0, "Starting V1.0");
  { Selector S;
    UplinkRcvrSer US(uplink_port, uplink_addr);
    Cmd_Selectee UC;
    S.add_child(&UC);
    S.add_child(&US);
    S.event_loop();
  }
  nl_error(0, "Terminating");
}
