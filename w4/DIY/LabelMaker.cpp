/*/////////////////////////////////////////////////////////////////////////
Workshop - 4 (DIY)
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>
#include "LabelMaker.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
  // creates a dynamic array of Labels to the size of noOfLabels
  LabelMaker::LabelMaker(int noOfLabels)
  {
    m_noOfLabels = noOfLabels;
    m_labels = nullptr;
    m_labels = new Label[noOfLabels];
  }

  // Gets the contents of the Labels as demonstrated in the Execution sample
  void LabelMaker::readLabels()
  {
    cout << "Enter " << m_noOfLabels << " labels:" << endl;
    for (int i = 0; i < m_noOfLabels; i++)
    {
      cout << "Enter label number ";
      cout << i + 1 << endl
           << "> ";
      m_labels[i].Label::readLabel();
    }
  }

  // prints
  void LabelMaker::printLabels()
  {
    for (int i = 0; i < m_noOfLabels; i++)
    {
      m_labels[i].printLabel();
      cout << endl;
    }
  }

  // Deallocates the memory when LabelMaker goes out of scope.
  LabelMaker::~LabelMaker()
  {
    delete[] m_labels;
    m_labels = nullptr;
  }
}