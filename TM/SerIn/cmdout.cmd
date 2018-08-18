%{
  #include "../SWData.h"
%}
%INTERFACE <uplink>

&command
  : Transmit SWStat &SWStat * {
      if_uplink.Turf("W:%02X\n", $3);
    }
  : Transmit Instruments On * {
      if_uplink.Turf("W:130\n");
    }
  : Transmit Instruments Off * {
      if_uplink.Turf("W:131\n");
    }
  ;
