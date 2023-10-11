#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include <iostream>
#include "MotorVehicle.h"
using namespace std;

namespace sdds
{
  class Truck : public MotorVehicle
  {
    double maxCapacity;
    double load;

  public:
    Truck();
    Truck(const char *p_licePlate, int p_year, double p_maxCapacity, const char *p_location);

    bool addCargo(double cargo);
    bool unloadCargo();
    ostream &write(ostream &os) const; // can i put const
    istream &read(istream &in);
  };

  // insert a Truck into a stream
  ostream &operator<<(ostream &os, const Truck &obj);

  // extract from stream
  istream &operator>>(istream &in, Truck &obj);
}
#endif