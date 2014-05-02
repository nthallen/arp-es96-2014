%{
  #include "address.h"
  #include "subbus.h"
%}

&command
  : Set &ao_chan %lf (Volts) * {
      double N = $3 * 6553.6;
      unsigned short bits;
      if (N > 65535) N = 65535;
      if (N < 0) N = 0.;
      bits  = (unsigned short) N;
      sbwr( $2, bits);
    }
  ;

&ao_chan <unsigned short>
  : Zone 1 Set Point { $0 = Z1_H_St_Address; }
  : Zone 2 Set Point { $0 = Z2_H_St_Address; }
  : Zone 5 Set Point { $0 = Z5_H_St_Address; }
  ;
