#include "TM_lowpass.h"

TM_lowpass::TM_lowpass(double rolloff_period, double sample_rate) {
  double pi = 3.14159265358979324;
  double RC = rolloff_period/(2*pi);
  double T = sample_rate/2;
  double a1 = (1+2*RC/T);
  a2 = (1-2*RC/T)/a1;
  b1 = b2 = 1/a1;
  filled = false;
}

double TM_lowpass::operator()(double sample) {
  if (!filled) {
    xi = sample;
    yi = xi * (b1+b2-1) / a2;
    filled = true;
  }
  yi = b1*sample + b2*xi - a2*yi;
  xi = sample;
  return yi;
}

