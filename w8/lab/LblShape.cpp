#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <fstream>
#include "LblShape.h"

namespace sdds
{
  LblShape::LblShape()
  {
    m_label = nullptr;
  }
  LblShape::LblShape(const char *label)
  {
    m_label = nullptr;

    if (label != nullptr)
    {
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
    }
  }
  LblShape::~LblShape()
  {
    delete[] m_label;
  }

  const char *LblShape::label() const
  {
    return m_label;
  }

  void LblShape::getSpecs(istream &is)
  {
    string input;

    getline(is, input, ',');
    // is.ignore(1); // issue

    // m_label = nullptr;
    delete[] m_label;

    m_label = new char[input.length() + 1];
    strcpy(m_label, input.c_str());
    // cout << "LABEL!!! " << m_label << endl;
  }
};