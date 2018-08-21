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
  : Algo P1 &AlgoP1 { SWData.AlgoP1 = $3; }
  : Algo P2 &AlgoP2 { SWData.AlgoP2 = $3; }
  : Algo P3 &AlgoP3 { SWData.AlgoP3 = $3; }
  : Algo P4 &AlgoP4 { SWData.AlgoP4 = $3; }
  ;
&SWStat <unsigned char>
  : Scrub Start { $0 = SWS_SCRUB_START; }
  : Set %d { $0 = $2; }
  : Scrub Stop { $0 = SWS_SCRUB_STOP; }
  : Record { $0 = SWS_RECORD; }
  : Flash Heat On { $0 = SWS_FLASH_HEAT_ON; }
  : Flash Heat Off { $0 = SWS_FLASH_HEAT_OFF; }
  : Flash Heat Done { $0 = SWS_FLASH_HEAT_DONE; }
  : Altitude Off Ground { $0 = SWS_OFF_GROUND; }
  : Altitude Stratosphere { $0 = SWS_STRATOSPHERE; }
  : Altitude Terminate { $0 = SWS_TERMINATE; }
  : Time Warp { $0 = SWS_TIME_WARP; }
  : Shutdown { $0 = SWS_SHUTDOWN; }
  ;
&AlgoP1 <unsigned char>
  : %d { $0 = $1; }
  ;
&AlgoP2 <unsigned char>
  : %d { $0 = $1; }
  ;
&AlgoP3 <unsigned char>
  : %d { $0 = $1; }
  ;
&AlgoP4 <unsigned char>
  : %d { $0 = $1; }
  ;
