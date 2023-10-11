#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include <iostream>
#include "LblShape.h"
// #include "LblShape.h"
using namespace std;

namespace sdds
{
  class Line : public LblShape
  {
    int m_length;

  public:
    Line();
    Line(const char *Cstring, int len);
    ~Line();
    void getSpecs(istream &is) override;
    void draw(ostream &os) override;
  };
}
#endif