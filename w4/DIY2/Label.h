#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds
{
  // The label class creates a label by drawing a frame around a one-line text with an unknown size (maximum of 70 chars, must be kept dynamically).
  class Label
  {
    char m_frame[9];
    char *m_content;

  public:
    // constructors
    // Creates an empty label and defaults the frame to "+-+|+-+|"
    Label();

    // Creates an empty label and sets the frame to the frameArg argument.
    Label(const char *frameArg);

    // Creates a Label with the frame set to frameArg and the content of the Label set to the corresponding argument. Keep the content dynamically even though it should never be more than 70 characters.
    Label(const char *frameArg, const char *content);

    // destructor
    ~Label();

    // Reads the label up to 70 characters and stores it in the Label
    void readLabel();

    // prints
    std::ostream &printLabel() const;
  };
}

#endif