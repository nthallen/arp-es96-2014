#include <stdio.h>
#include <math.h>
#include "model_atmos.h"

void model_atmos::tblrow(double km, double K,
      double hPa, double lnhPa) {
  table.push_back(model_atmos::model_row(km,K,hPa,lnhPa));
}

model_atmos::model_atmos() {
  tblrow(-0.5,291.4,1074.77,6.97986);
  tblrow( 0.0,288.1,1013.25,6.92092);
  tblrow( 0.5,284.9,954.61,6.86130);
  tblrow( 1.0,281.7,898.76,6.80102);
  tblrow( 1.5,278.4,845.59,6.74003);
  tblrow( 2.0,275.2,795.01,6.67835);
  tblrow( 2.5,271.9,746.91,6.61594);
  tblrow( 3.0,268.7,701.21,6.55281);
  tblrow( 3.5,265.4,657.80,6.48890);
  tblrow( 4.0,262.2,616.60,6.42422);
  tblrow( 4.5,258.9,577.52,6.35874);
  tblrow( 5.0,255.7,540.48,6.29246);
  tblrow( 5.5,252.4,505.39,6.22533);
  tblrow( 6.0,249.2,472.17,6.15734);
  tblrow( 6.5,245.9,440.75,6.08848);
  tblrow( 7.0,242.7,411.05,6.01871);
  tblrow( 7.5,239.5,382.99,5.94801);
  tblrow( 8.0,236.2,356.51,5.87636);
  tblrow( 8.5,233.0,331.54,5.80375);
  tblrow( 9.0,229.7,308.00,5.73010);
  tblrow( 9.5,226.5,285.84,5.65543);
  tblrow( 10.0,223.3,264.99,5.57969);
  tblrow( 10.5,220.0,245.40,5.50289);
  tblrow( 11.0,216.8,226.99,5.42491);
  tblrow( 11.5,216.6,209.84,5.34635);
  tblrow( 12.0,216.6,193.99,5.26781);
  tblrow( 12.5,216.6,179.33,5.18923);
  tblrow( 13.0,216.6,165.79,5.11072);
  tblrow( 13.5,216.6,153.27,5.03220);
  tblrow( 14.0,216.6,141.70,4.95371);
  tblrow( 14.5,216.6,131.00,4.87520);
  tblrow( 15.0,216.6,121.11,4.79670);
  tblrow( 15.5,216.6,111.97,4.71823);
  tblrow( 16.0,216.6,103.52,4.63976);
  tblrow( 16.5,216.6,95.71,4.56132);
  tblrow( 17.0,216.6,88.49,4.48289);
  tblrow( 17.5,216.6,81.82,4.40452);
  tblrow( 18.0,216.6,75.65,4.32612);
  tblrow( 18.5,216.6,69.94,4.24764);
  tblrow( 19.0,216.6,64.67,4.16930);
  tblrow( 19.5,216.6,59.79,4.09084);
  tblrow( 20.0,216.6,55.29,4.01259);
  tblrow( 22.0,218.6,40.47,3.70056);
  tblrow( 24.0,220.6,29.72,3.39182);
  tblrow( 26.0,222.5,21.88,3.08557);
  tblrow( 28.0,224.5,16.16,2.78254);
  tblrow( 30.0,226.5,11.97,2.48240);
  tblrow( 32.0,228.5,8.89,2.18493);
  tblrow( 34.0,233.7,6.63,1.89221);
  tblrow( 36.0,239.3,4.99,1.60643);
  tblrow( 38.0,244.8,3.77,1.32734);
  tblrow( 40.0,250.4,2.87,1.05466);
  tblrow( 42.0,255.9,2.20,0.78846);
  tblrow( 44.0,261.4,1.70,0.52768);
  tblrow( 46.0,266.9,1.31,0.27231);
  tblrow( 48.0,270.6,1.02,0.02274);
  tblrow( 50.0,270.6,0.80,-0.22602);
  tblrow( 52.0,269.0,0.62,-0.47465);
  tblrow( 54.0,263.5,0.48,-0.72712);
  tblrow( 56.0,258.0,0.37,-0.98457);
  tblrow( 58.0,252.5,0.29,-1.24758);
  tblrow( 60.0,247.0,0.22,-1.51595);
  tblrow( 62.0,241.5,0.17,-1.79036);
  tblrow( 64.0,236.0,0.13,-2.07147);
  tblrow( 66.0,230.5,0.09,-2.35820);
  tblrow( 68.0,225.1,0.07,-2.65200);
  tblrow( 70.0,219.6,0.05,-2.95267);
  tblrow( 72.0,214.3,0.04,-3.26100);
  tblrow( 74.0,210.3,0.03,-3.57555);
  tblrow( 76.0,206.4,0.02,-3.89566);
  tblrow( 78.0,202.5,0.01,-4.22195);
  tblrow( 80.0,198.6,0.01,-4.55448);
  tblrow( 82.0,194.7,0.01,-4.89312);
  tblrow( 84.0,190.8,0.01,-5.23854);
  tblrow( 86.0,186.9,0.00,-5.59081);
}

model_atmos::model_row::model_row(double km, double K,
      double hPa, double lnhPa) : km(km), K(K),
      hPa(hPa), lnhPa(lnhPa) {}

bool model_atmos::get_PT(double alt, double &hPa, double &K) {
  int lo = 0, hi = table.size()-1;
  if (alt < table[lo].km ||
      alt > table[hi].km) return false;
  while (hi > lo+1) {
    int mid = (lo+hi)/2;
    if (alt < table[mid].km) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  double ki = (alt-table[lo].km)/(table[hi].km-table[lo].km);
  double lnhPa = table[lo].lnhPa + ki*(table[hi].lnhPa-table[lo].lnhPa);
  K = table[lo].K + ki*(table[hi].K-table[lo].K);
  hPa = exp(lnhPa);
  return true;
}

double model_atmos::get_km(double P, double Punits) {
  P = P * units_hPa / Punits; // convert to hPa to match table
  double lnP = log(P);
  
  int lo = 0, hi = table.size()-1;
  // lnhPa is decreasing, so reverse conditions
  if (lnP > table[lo].lnhPa ||
      lnP < table[hi].lnhPa) return false;
  while (hi > lo+1) {
    int mid = (lo+hi)/2;
    if (lnP > table[mid].lnhPa) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  double ki = (lnP-table[lo].lnhPa)/(table[hi].lnhPa-table[lo].lnhPa);
  double km = table[lo].km + ki*(table[hi].km-table[lo].km);
  return km;
}

model_atmos Atm;

