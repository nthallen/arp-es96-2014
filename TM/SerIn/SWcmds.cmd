&SWStat <unsigned char>
  : Scrub Start { $0 = SWS_SCRUB_START; }
  : Set %d { $0 = $2; }
  : Scrub Stop { $0 = SWS_SCRUB_STOP; }
  : Shutdown { $0 = SWS_SHUTDOWN; }
  ;