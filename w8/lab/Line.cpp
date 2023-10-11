#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstring>
#include "Line.h"

namespace sdds
{
  // invokes the default constructor of the base class.
  Line::Line() : LblShape()
  {
    m_length = 0;
  }

  // Passes the Cstring to the constructor of the base class
  Line::Line(const char *Cstring, int len) : LblShape(Cstring)
  {
    if (Cstring != nullptr)
    {
      m_length = len;
    }
  }

  Line::~Line()
  {
    // This class has no destructor implemented.
  }

  void Line::getSpecs(istream &is)
  {
    LblShape::getSpecs(is);

    is >> m_length; // bug: m_length is always 0
    is.ignore(std::numeric_limits<streamsize>::max(), '\n');
  }

  void Line::draw(ostream &os)
  {

    if (m_length > 0 && LblShape::label() != nullptr)
    {
      os << LblShape::label() << endl;
      for (int i = 0; i < m_length; i++)
      {
        os << "=";
      }
      // os << endl;
    }
  }
};