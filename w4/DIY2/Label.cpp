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
#include "Label.h"
#include "cstring.h"

using namespace std;
namespace sdds
{

  Label::Label()
  {

    m_content = nullptr;
    strCpy(m_frame, "+-+|+-+|");
  }

  Label::Label(const char *frameArg)
  {
    m_content = nullptr;
    strCpy(m_frame, frameArg);
  }

  // Creates a Label with frame set to frameArg and the content set to the corresponding argument. Keep the content dynamically even though it should never be more than 70 characters.
  Label::Label(const char *frameArg, const char *content)
  {
    strCpy(m_frame, frameArg);

    // dynamic allocation ~~ WRONG WAY
    // m_content = nullptr;
    // m_content = new char[strLen(content) + 1];
    // strnCpy(m_content, content, 70);
    // m_content[strLen(content) + 1] = '\0';
    int max = 70;
    int len = strLen(content);
    int allocateSize = (len < max) ? len : max;
    m_content = new char[allocateSize + 1];
    strnCpy(m_content, content, allocateSize);
    m_content[allocateSize] = '\0';
  }

  // destructor
  Label::~Label()
  {
    delete[] m_content;
    m_content = nullptr;
  }

  // Reads the label up to 70 characters and stores it in the Label
  void Label::readLabel()
  {
    char userInput[200];
    cin.getline(userInput, sizeof(userInput));

    delete[] m_content;
    int max = 70;
    int len = strLen(userInput);
    int allocateSize = (len < max) ? len : max;
    m_content = new char[allocateSize + 1];
    strnCpy(m_content, userInput, allocateSize);
    m_content[allocateSize] = '\0';
  }

  std::ostream &Label::printLabel() const
  {
    if (m_content != nullptr)
    {
      cout << m_frame[0];
      for (int i = 0; i < (strLen(m_content) + 2); i++)
      {
        cout << m_frame[1];
      }
      cout << m_frame[2] << endl;

      cout << m_frame[7] << std::setw(strLen(m_content) + 3) << m_frame[3] << endl;
      cout << m_frame[7] << " " << m_content << " " << m_frame[3] << endl;
      cout << m_frame[7] << std::setw(strLen(m_content) + 3) << m_frame[3] << endl;

      cout << m_frame[2];
      for (int i = 0; i < (strLen(m_content) + 2); i++)
      {
        cout << m_frame[5];
      }
      cout << m_frame[4] << endl;
    }
    return std::cout;
  }

}
