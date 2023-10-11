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
#include "cstring.h"
#include "Bill.h"

using namespace std;

namespace sdds
{
  // TO-DO: sets  Bill object to empty state: m_title to empty Cstring and m_items to nullptr
  void Bill::setEmpty() // PRIVATE
  {
    char safeChar = '\0';
    char *p = &safeChar;
    m_title[0] = *p;
    m_items = nullptr;
  }

  // TO-DO: returns true if m_title is not empty,  m_items is not null, and all Items in the m_items array are valid
  bool Bill::isValid() const // PRIVATE
  {
    if (m_title[0] != '\0' && m_items != nullptr)
    {
      for (int i = 0; i < m_noOfItems; i++)
      {
        if (!m_items[i].isValid())
        {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  // TO-DO: if arguments are INVALID, set Bill to  empty state

  /*  If the incoming arguments are VALID:
        - Set m_noOfItems to the incoming corresponding argument and sets m_itemsAdded to zero.

        - Copy the string pointed by the "title" argument into m_title, up to 36 chars

        - Dynamically allocate an array of Items pointed by m_items;  length is m_noOfItems.
        (make sure all dynamically allocated Items are set to empty) */
  void Bill::init(const char *title, int noOfItems)
  {
    if (title[0] != '\0' && noOfItems >= 0)
    {
      m_noOfItems = noOfItems;
      m_itemsAdded = 0;
      strnCpy(m_title, title, 36);
      m_title[strLen(m_title)] = '\0';

      m_items = nullptr;
      m_items = new Item[m_noOfItems];

      for (int i = 0; i < m_noOfItems; i++)
      {
        m_items[i].setEmpty();
      }
    }
    else
    {
      setEmpty();
    }
  }

  // TO-DO: If m_itemsAdded is less than length of m_items array, set next available Item obj to argument values.
  // Add one to m_itemsAdded and return true
  // Else, do nothing, return false
  bool Bill::add(const char *item_name, double price, bool taxed)
  {
    bool result = false;
    if (m_itemsAdded < m_noOfItems)
    {
      // if (item_name != nullptr && price >= 0.0)
      //{

      m_items[m_itemsAdded].set(item_name, price, taxed);
      m_itemsAdded++;
      result = true;
      //}
    }
    else
    {

      result = false;
    }
    return result;
  }

  // TO-DO: Adds all taxes of items; returns sum
  double Bill::totalTax() const // PRIVATE
  {
    double taxSum = 0.0;
    for (int i = 0; i < m_noOfItems; i++)
    {
      taxSum += m_items[i].tax();
    }
    return taxSum;
  }

  // TO-DO: Adds prices of items; returns sum
  double Bill::totalPrice() const // PRIVATE
  {
    double priceSum = 0.0;
    for (int i = 0; i < m_noOfItems; i++)
    {
      priceSum += m_items[i].price();
    }
    return priceSum;
  }

  // TO-DO: Prints Bill title depending on validity
  void Bill::Title() const // PRIVATE
  {
    cout << "+--------------------------------------+" << endl;
    if (isValid() == true)
    {
      cout << "| ";
      cout.fill(' ');
      cout.width(36);
      cout.unsetf(ios::adjustfield);
      cout.setf(ios::left);
      cout << m_title << " |" << endl;
    }
    else
    {
      cout << "| Invalid Bill                         |" << endl;
    }
    cout << "+----------------------+---------+-----+" << endl;
    cout << "| Item Name            | Price   + Tax |" << endl;
    cout << "+----------------------+---------+-----+" << endl;
  }

  // TO-DO: Prints footer
  void Bill::footer() const // PRIVATE
  {
    cout << "+----------------------+---------+-----+" << endl;
    if (isValid() == true)
    {
      cout << "|                Total Tax: ";
      cout.fill(' ');
      cout.width(10);
      cout.setf(ios::right);
      cout.precision(2);
      cout.setf(ios::fixed);
      cout << totalTax() << " |" << endl;

      cout << "|              Total Price: ";
      cout.fill(' ');
      cout.width(10);
      cout.setf(ios::right);
      cout << totalPrice() << " |" << endl;

      cout << "|          Total After Tax: ";
      cout.fill(' ');
      cout.width(10);
      cout.setf(ios::right);
      cout << totalTax() + totalPrice() << " |" << endl;
    }
    else
    {
      cout << "| Invalid Bill                         |" << endl;
    }
    cout << "+--------------------------------------+" << endl;
  }

  // TO-DO: Print the title(), m_items elements, footer()
  void Bill::display() const
  {
    Title();
    for (int i = 0; i < m_noOfItems; i++)
    {
      m_items[i].display();
    }
    footer();
  }

  // TO-DO: deallocates m_items arrays and sets pointers to null
  void Bill::deallocate()
  {
    delete[] m_items;
    m_items = nullptr;
  }
}