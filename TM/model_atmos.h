#ifndef MODEL_ATMOS_H_INCLUDED
#define MODEL_ATMOS_H_INCLUDED
#include <vector>

class model_atmos {
  public:
    model_atmos();
    bool get_PT(double kmt, double &hPa, double &K);
    double get_km(double P, double Punits = units_hPa);
    void tblrow(double km, double K, double hPa, double lnhPa);
    struct model_row {
      public:
        model_row(double km, double K, double hPa, double lnhPa);
        double km;
        double K;
        double hPa;
        double lnhPa;
    };
    std::vector<model_row> table;
    static const double units_hPa = 1013.25;
    static const double units_Torr = 760;
    static const double units_atm = 1;
};

extern model_atmos Atm;

#endif
