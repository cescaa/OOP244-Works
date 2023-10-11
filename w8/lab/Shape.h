#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
using namespace std;

namespace sdds
{
  class Shape
  {

  public:
    virtual ~Shape();
    virtual void draw(ostream &os) = 0;
    virtual void getSpecs(istream &is) = 0;
  };

  // overload insertion and extract

  istream &operator>>(istream &is, Shape &obj);

  ostream &operator<<(ostream &os, Shape &obj);
}
#endif