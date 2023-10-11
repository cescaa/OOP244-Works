#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstring>
#include "Shape.h"
using namespace std;

namespace sdds
{

  Shape::~Shape()
  {
  }

  istream &operator>>(istream &is, Shape &obj)
  {
    obj.getSpecs(is);
    return is;
  }

  ostream &operator<<(ostream &os, Shape &obj)
  {
    obj.draw(os);
    return os;
  }
};