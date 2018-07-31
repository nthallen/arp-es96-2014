%{
  #include "../SWData.h"
%}
%INTERFACE <uplink>

&command
  : Transmit &SWStat * {
      if_uplink.Turf("W:%02X\n", $2);
    }
  ;
