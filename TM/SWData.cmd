%{
  #include "SWData.h"
  #ifdef SERVER
    SWData_t SWData;
  #endif
%}

%INTERFACE <SWData:DG/data>

&command
  : &SWTM * { if_SWData.Turf(); }
  ;
&SWTM
  : SW Status &SWStat { SWData.SWStat = $3; }
  ;
&SWStat <unsigned char>
  : Scrub Start { $0 = SWS_SCRUB_START; }
  : Set %d { $0 = $2; }
  : Scrub Stop { $0 = SWS_SCRUB_STOP; }
  : Shutdown { $0 = SWS_SHUTDOWN; }
  ;
