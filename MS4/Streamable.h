#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
using namespace std;

// g++ -Wall -std=c++11 -g -o ws ms3_tester.cpp Streamable.cpp Publication.cpp

namespace sdds
{
  // An Interface is an abstract base class with only pure virtual functions.
  // a pure virtual function is a virtual function that has no implementation in the base class

  class Streamable
  {
  public:
    virtual ostream &write(ostream &os) const = 0;
    virtual istream &read(istream &is) = 0;
    virtual bool conIO(ios &io) const = 0;
    virtual operator bool() = 0;
    virtual ~Streamable();

    friend ostream &operator<<(ostream &os, const Streamable &obj);

    friend istream &operator>>(istream &is, Streamable &obj);
  };
}
#endif