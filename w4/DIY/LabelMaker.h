#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"

namespace sdds
{
  // The LabelMaker class creates a dynamic array of Labels and gets their content from the user one by one and prints them all at once.

  class LabelMaker
  {
    Label *m_labels;
    int m_noOfLabels;

  public:
    // creates a dynamic array of Labels to the size of noOfLabels
    LabelMaker(int noOfLabels);

    // Gets the contents of the Labels as demonstrated in the Execution sample
    void readLabels();

    // prints
    void printLabels();

    // Deallocates the memory when LabelMaker goes out of scope.
    ~LabelMaker();
  };
}

#endif /* LABELMAKER_H */