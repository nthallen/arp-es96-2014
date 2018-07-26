#ifndef UPLINK_H_INCLUDED
#define UPLINK_H_INCLUDED

extern const char *uplink_port;
extern const char *uplink_addr;

#ifdef __cplusplus
#include <SerSelector.h>

class UplinkSer : public Ser_Sel {
  public:
    UplinkSer(const char *port, const char *addr);
    ~UplinkSer();
    int ProcessData(int flag);
    void transmit(unsigned short val);
  private:
    const char *addr;
};

class UplinkCmd : public Cmd_Selectee {
  public:
    inline UplinkCmd(UplinkSer *US) : Cmd_Selectee("cmd/uplink"), US(US) {};
    ~UplinkCmd();
    int ProcessData(int flag);
  private:
    UplinkSer *US;
};

#endif

#endif
