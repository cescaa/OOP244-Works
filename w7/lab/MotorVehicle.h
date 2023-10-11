#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_
#include <iostream>
using namespace std;

namespace sdds
{
  class MotorVehicle
  {

  protected:
    char licePlate[9];
    char location[64];
    int year;

  public:
    MotorVehicle();
    MotorVehicle(const char *p_licePlate, int p_year);

    void moveTo(const char *address);
    ostream &write(ostream &os) const;
    istream &read(istream &in);
  };

  // insert a MotorVehicle into a stream
  ostream &operator<<(ostream &os, const MotorVehicle &obj);

  // extract from stream
  istream &operator>>(istream &in, MotorVehicle &obj);

}
#endif