%INTERFACE <dccc:dccc>

&command
  : Command &on_off_cmd &cmd_on_off *
      { if_dccc.Turf("D%d\n", 2*$2+$3); }
  : Command &open_closed_cmd &cmd_open_closed *
      { if_dccc.Turf("D%d\n", 2*$2+$3); }
  ;
&on_off_cmd <int>
  : LED_A_On_Off { $0 = 0; }
  : Scrub_FH_A_On_Off { $0 = 3; }
  : Z1_HC_A_On_Off { $0 = 4; }
  : Z2_HC_A_On_Off { $0 = 5; }
  : Z5_HC_A_On_Off { $0 = 6; }
  : Pump_On_Off [ $0 = 7; }
  ;

&cmd_on_off <int>
  : On { $0 = 0; }
  : Off { $0 = 1; }
  ;

&open_closed_cmd <int>
  : Vlv_UnScb_A_Open_Close { $0 = 1; }
  : Vlv_Scb_A_Open_Close { $0 = 2; } 
  ;

&cmd_open_closed <int>
  : Open { $0 = 0; }
  : Close { $0 = 1; }
  ;
