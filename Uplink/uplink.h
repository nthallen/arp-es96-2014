#ifndef UPLINK_H_INCLUDED
#define UPLINK_H_INCLUDED

extern const char *uplink_port;
extern const char *uplink_addr0, *uplink_addr1;

#ifdef __cplusplus
#include <SerSelector.h>

class UplinkSer : public Ser_Sel {
  public:
    UplinkSer(const char *port);
    ~UplinkSer();
    int ProcessData(int flag);
    void transmit(unsigned short addr, unsigned short val);
};

class UplinkCmd : public Cmd_Selectee {
  public:
    UplinkCmd(UplinkSer *US, const char *addr0, const char *addr1);
    ~UplinkCmd();
    int ProcessData(int flag);
  private:
    UplinkSer *US;
    unsigned short addr0, addr1;
};

#endif

#endif
