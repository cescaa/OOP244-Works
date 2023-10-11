#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
namespace sdds
{

   class Bill
   {

      char m_title[37];
      Item *m_items;
      int m_noOfItems;
      int m_itemsAdded;

      // TO-DO: sets  Bill object to empty state: m_title to empty Cstring and m_items to nullptr
      void setEmpty();

      // TO-DO: returns true if m_title is not empty,  m_items is not null, and all Items in the m_items array are valid
      bool isValid() const;

   public:
      // TO-DO: if arguments are INVALID, set Bill to  empty state

      /*  If the incoming arguments are VALID:
            - Set m_noOfItems to the incoming corresponding argument and sets m_itemsAdded to zero.

            - Copy the string pointed by the "title" argument into m_title, up to 36 chars

            - Dynamically allocate an array of Items pointed by m_items;  length is m_noOfItems.
            (make sure all dynamically allocated Items are set to empty) */
      void init(const char *title, int noOfItems);

      // TO-DO: If m_itemsAdded is less than length of m_items array, set next available Item obj to incoming argument values.
      // Add one to m_itemsAdded and return true
      // Else, do nothing, return false
      bool add(const char *item_name, double price, bool taxed);

      // TO-DO: Adds all taxes of items; returns sum
      double totalTax() const;

      // TO-DO: Adds prices of items; returns sum
      double totalPrice() const;

      // TO-DO: Prints Bill title depending on validity
      void Title() const;

      // TO-DO: Prints footer
      void footer() const;

      // TO-DO: Print the title(), m_items elements, footer()
      void display() const;

      // TO-DO: deallocates m_items arrays and sets pointers to null
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
