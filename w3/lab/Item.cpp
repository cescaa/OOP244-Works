/*/////////////////////////////////////////////////////////////////////////
Workshop - 3 (Part 1)
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
#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds
{

  // TO-DO: sets the Item to a Empty State; set price to 0.0, m_itemName's first char to null
  void Item::setEmpty()
  {
    char safeChar = '\0';
    char *p = &safeChar;
    m_itemName[0] = *p;

    m_price = 0.0;
  }

  // TO-DO: returns true if the Item is not set to empty state (done in setEmpty func)
  // func cannot modify owner
  bool Item::isValid() const
  {
    bool result = false;

    if (m_itemName[0] != '\0' && m_price != 0.0)

    {
      result = true;
    }

    else
    {
      result = false;
    }

    return result;
  }

  // TO-DO: Returns m_price
  double Item::price() const
  {
    return m_price;
  }

  // TO-DO: returns m_price X 0.13 (define constant var for tax), OR returns 0.0 if m_taxed is false
  double Item::tax() const
  {
    const double taxRate = 0.13;
    double taxOfItem;
    if (m_taxed == true)
    {
      taxOfItem = m_price * taxRate;
    }
    else
    {
      taxOfItem = 0.0;
    }
    return taxOfItem;
  }

  // TO-DO: sets itemName to the name argument up to 20 chars
  void Item::setName(const char *name) // PRIVATE
  {

    strnCpy(m_itemName, name, 20);
    m_itemName[20] = '\0';
  }

  // TO-DO: sets  m_itemName to string pointed by name argument using the setName()
  // sets m_price and m_taxed to corresponding arguments
  void Item::set(const char *name, double price, bool taxed)
  {
    if (name != nullptr && price >= 0)
    {
      setName(name);
      m_price = price;
      m_taxed = taxed;
    }
    else
    {
      setEmpty();
    }
  }

  // TO-DO: Prints an item depending on validity
  void Item::display() const
  {
    if (isValid() == true)
    {
      char taxedString[4];
      strCpy(taxedString, (m_taxed == true) ? "Yes" : "No ");

      cout << "| ";
      cout.fill('.');
      cout.width(20);
      cout.unsetf(ios::adjustfield);
      cout.setf(ios::left);
      cout << m_itemName;

      cout << " | ";
      cout.fill(' ');
      cout.width(7);
      cout.setf(ios::right);
      cout.precision(2);
      cout.setf(ios::fixed);
      cout << m_price;

      cout << " | " << taxedString << " |" << endl;
    }
    else
    {
      cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
    }
  }

}