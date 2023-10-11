#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include <iostream>
#include "LblShape.h"

using namespace std;

namespace sdds
{
  class Rectangle : public LblShape
  {
    int m_width;
    int m_height;

  public:
    Rectangle();
    Rectangle(const char *Cstring, int width, int height);
    ~Rectangle();
    void draw(ostream &os) override;
    void getSpecs(istream &is) override;
  };
}
#endif