#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds
{
  class LblShape : public Shape
  {
    // hold the DA label for the Shape
    char *m_label;

  protected:
    const char *label() const; // might be wrong

    LblShape();
    LblShape(const char *label);
    ~LblShape();
    void getSpecs(istream &is) override;
    // set
    // operator&

    // Delete copy constructor
    LblShape(const LblShape &other) = delete;
    // Delete assignment operator
    LblShape &operator=(const LblShape &other) = delete;
  };
}
#endif