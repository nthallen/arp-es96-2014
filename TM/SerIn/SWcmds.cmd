&SWStat <unsigned char>
  : Pump On { $0 = SWS_PUMP_ON; }
  : Set %d { $0 = $2; }
  : Pump Off { $0 = SWS_PUMP_OFF; }
  : Calibrate { $0 = SWS_CAL_SEQ; }
  : RingDown { $0 = SWS_CAL_RD; }
  : Pump Cycle { $0 = SWS_PUMP_CYCLE; }
  : Time Warp { $0 = SWS_TIME_WARP; }
  ;
