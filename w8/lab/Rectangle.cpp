#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstring>
#include "Rectangle.h"

namespace sdds
{
  Rectangle::Rectangle() : LblShape()
  {
    m_width = 0;
    m_height = 0;
  }

  /*  Passes the Cstring to the constructor of the base class and sets the m_width and m_height member variables to the corresponding values received from the argument list. However if the m_height is less than 3 or m_width is less the length of the label() + 2 it will set the Rectangle to an empty state. */
  Rectangle::Rectangle(const char *Cstring, int width, int height) : LblShape(Cstring)
  {
    if (Cstring != nullptr)
    {
      m_width = width;
      m_height = height;
    }

    if (m_height < 3 || static_cast<unsigned int>(m_width) < (strlen(LblShape::label()) + 2))
    {
      m_width = 0;
      m_height = 0;
    }
  }

  Rectangle::~Rectangle()
  {
    // This class has no destructor implemented.
  }

  void Rectangle::getSpecs(istream &is)
  {
    LblShape::getSpecs(is);
    char ch;
    is >> m_width;
    is.get(ch);
    is >> m_height;

    is.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  void Rectangle::draw(ostream &os)
  {
    if (m_height != 0 || m_width != 0)
    {
      os << "+";
      for (int i = 0; i < (m_width - 2); i++)
      {
        os << "-";
      }
      os << "+" << endl;

      // LABEL

      int lenOfLab = strlen(label());
      int spaceLen = (m_width - 2) - lenOfLab;

      os << "|" << LblShape::label();
      for (int i = 0; i < spaceLen; i++)
      {
        os << " ";
      }
      os << "|" << endl;

      // end of label
      for (int i = 0; i < (m_height - 3); i++)
      {
        os << "|";
        for (int i = 0; i < (m_width - 2); i++)
        {
          os << " ";
        }
        os << "|" << endl;
      }
      // end
      os << "+";
      for (int i = 0; i < (m_width - 2); i++)
      {
        os << "-";
      }
      os << "+";
    }
  }
};
