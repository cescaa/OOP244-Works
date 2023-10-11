/*/////////////////////////////////////////////////////////////////////////
Workshop - 5 (part 2)
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
#include "Mark.h"
using namespace std;

// Hi Sir,
// I was having issues coding the last function so I asked on StackOverflow
// https://stackoverflow.com/questions/76502554/how-to-fix-ambiguity-error-when-working-with-overloaded-operators-in-c
// However, none of the answers helped, and I still figured it all on on my own,
// but I just wanted to let you know that this is my post and I did not plagerize!

namespace sdds
{

  void Mark::setEmpty()
  {
    markVal = 0;
  };

  // init objs w/o values to 0
  Mark::Mark()
  {
    setEmpty();
  };

  // sets the value of the mark
  // If value is not provided, the value of the mark will be zero.
  Mark::Mark(int val)
  {
    markVal = val;
  };

  // checks if mark is valid
  bool Mark::markIsValid()
  {
    bool result = false;
    if (markVal >= 0 && markVal <= 100)
    {
      result = true;
    }

    return result;
  }

  // Mark casted to an integer (int type)
  // The result would be the value of the mark or zero if the mark is in an invalid state.
  Mark::operator int()
  {
    int result;
    if (markIsValid())
    {
      result = markVal;
    }
    else
    {
      result = 0;
    }
    return (int)result;
  };

  // An integer can be added to the value of the mark using += operator
  // if the mark is invalid, the action is omitted.
  // Reference of the mark is returned after the operation.
  Mark &Mark::operator+=(int addVal)
  {
    if (markIsValid())
    {
      markVal += addVal;
    }

    else
    {
      markVal = 0;
    }
    return *this;
  };

  // Mark can be set to an integer using the assignment operator.
  // If the mark is in an invalid state, the invalid value can be corrected by the assignment
  // Reference of the mark is returned
  Mark &Mark::operator=(int newMark)
  {
    if (markIsValid())
    {
      markVal = newMark;
    }
    else
    {
      markVal = 0;
    }

    return *this;
  };

  // Mark can be casted to a double, the result would be the GPA equivalent of the integer value.
  // Casting an invalid mark will result in a zero value.
  Mark::operator double()
  {
    double GPA; // double?
    if (markIsValid())
    {
      if (markVal >= 80 && markVal <= 100)
      {
        GPA = 4;
      }
      else if (markVal < 80 && markVal >= 70)
      {
        GPA = 3;
      }
      else if (markVal < 70 && markVal >= 60)
      {
        GPA = 2;
      }
      else if (markVal < 60 && markVal >= 50)
      {
        GPA = 1;
      }
      else
      {
        GPA = 0;
      }
    }
    else
    {
      GPA = 0;
    }
    return GPA;
  };

  Mark::operator char()
  {
    char letter;
    if (markIsValid())
    {
      if (markVal >= 80 && markVal <= 100)
      {
        letter = 'A';
      }
      else if (markVal < 80 && markVal >= 70)
      {
        letter = 'B';
      }
      else if (markVal < 70 && markVal >= 60)
      {
        letter = 'C';
      }
      else if (markVal < 60 && markVal >= 50)
      {
        letter = 'D';
      }
      else
      {
        letter = 'F';
      }
    }
    else
    {
      letter = 'X';
    }
    return letter;
  };

  // Mark can be added to an integer, returning the integer after the operation.
  //  Invalid marks will not add any value to the integer.

  int &operator+=(int &val, Mark &obj)
  {
    if (obj.markIsValid())
    {
      val = obj.getMark() + val;
    }
    return val;
  };

}