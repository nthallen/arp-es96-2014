#ifndef TM_LOWPASS_INCLUDED
#define TM_LOWPASS_INCLUDED

class TM_lowpass {
  public:
    TM_lowpass(double rolloff_period, double sample_rate = 1.0);
    double operator()(double sample);
  private:
    double a2, b1, b2;
    double yi, xi;
    bool filled;
};
#endif
