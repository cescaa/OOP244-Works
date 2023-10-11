#include <iostream>
#include "cstring.h"
#include "Truck.h"
using namespace std;

namespace sdds
{

  Truck::Truck()
  {
    maxCapacity = 0;
    load = 0;
  }
  // Truck aTruck("T-1111", 2015, 5432, "Toronto HQ");
  Truck::Truck(const char *p_licePlate, int p_year, double p_maxCapacity, const char *p_location) : MotorVehicle(p_licePlate, p_year)
  {
    maxCapacity = p_maxCapacity;
    load = 0; // current cargo

    moveTo(p_location);
  }

  bool Truck::addCargo(double cargo)
  {
    bool cargoAdded = false;
    if (load < maxCapacity)
    {
      double counter = 0;
      while (load != maxCapacity && counter < cargo)
      {
        counter++;
        load += 1;
      }
      cargoAdded = true;
    }

    return cargoAdded;
  }

  bool Truck::unloadCargo()
  {
    bool cargoUnloaded = false;
    if (load != 0)
    {
      load = 0;
      cargoUnloaded = true;
    }
    else
    {
      cargoUnloaded = false;
    }
    return cargoUnloaded;
  }

  ostream &Truck::write(ostream &os) const
  {
    os << "| " << year << " | " << licePlate << " | " << location << " | " << load << "/" << maxCapacity;
    return os;
  }

  istream &Truck::read(istream &in)
  {
    cout << "Built year: ";
    in >> year;
    cout << "License plate: ";
    in >> licePlate;
    cout << "Current location: ";
    in >> location;
    cout << "Capacity: ";
    in >> maxCapacity;
    cout << "Cargo: ";
    in >> load;

    return in;
  }

  ostream &operator<<(ostream &os, const Truck &obj)
  {
    return obj.write(os);
  }

  istream &operator>>(istream &in, Truck &obj)
  {
    return obj.read(in);
  }
};