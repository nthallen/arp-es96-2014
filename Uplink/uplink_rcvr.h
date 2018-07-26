#ifndef UPLINK_RCVR_H_INCLUDED
#define UPLINK_RCVR_H_INCLUDED

extern const char *uplink_port;
extern const char *uplink_addr;

#ifdef __cplusplus
#include <SerSelector.h>

class UplinkRcvrSer : public Ser_Sel {
  public:
    UplinkRcvrSer(const char *port, const char *addr);
    ~UplinkRcvrSer();
    int ProcessData(int flag);
    Timeout *GetTimeout();
  private:
    void update_termios();
    unsigned short addr;
    termios termios_s;
    Timeout TO;
};

#endif

#endif
