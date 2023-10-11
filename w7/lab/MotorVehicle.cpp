#include <iostream>
#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;
namespace sdds
{

  MotorVehicle::MotorVehicle()
  {
    strCpy(licePlate, "XXX-XXX");
    strCpy(location, "Factory");
    year = 0;
  }

  MotorVehicle::MotorVehicle(const char *p_licePlate, int p_year)
  {
    strCpy(licePlate, p_licePlate);
    year = p_year;
    strCpy(location, "Factory");
  }

  void MotorVehicle::moveTo(const char *address)
  {
    if (strCmp(location, address) != 0)
    {
      cout << "|" << right << setw(8) << licePlate << "| |"
           << right << setw(20) << location << " ---> ";
      strCpy(location, address);
      cout << left << setw(20) << location << "|" << endl;
    }
  }

  ostream &MotorVehicle::write(ostream &os) const
  {
    os << "| " << year << " | " << licePlate << " | " << location;
    return os;
  }

  istream &MotorVehicle::read(istream &in)
  {
    cout << "Built year: ";
    in >> year;

    cout << "License plate: ";
    in >> licePlate;

    cout << "Current location: ";
    in >> location;

    return in;
  }

  // insertion
  ostream &operator<<(ostream &os, const MotorVehicle &obj)
  {
    return obj.write(os);
  }

  istream &operator>>(istream &in, MotorVehicle &obj)
  {
    return obj.read(in);
  }
};
