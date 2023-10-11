#include <iostream>
#include <fstream>
#include "Streamable.h"

using namespace std;

namespace sdds
{
  Streamable::~Streamable()
  {
  }

  ostream &operator<<(ostream &os, const Streamable &obj)
  {
    return obj.write(os);
  }

  istream &operator>>(istream &is, Streamable &obj)
  {
    return obj.read(is);
  }
}