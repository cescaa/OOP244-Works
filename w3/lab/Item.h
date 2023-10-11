#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds
{

   class Item
   {
      char m_itemName[21];
      double m_price;
      bool m_taxed;

      // TO-DO: sets itemName to the name argument up to 20 chars
      void setName(const char *name);

   public:
         // TO-DO: sets the Item to a Empty State; set price to 0.0, m_itemName's first char to null
      void setEmpty();

      // TO-DO: returns true if the Item is not set to empty state (done in setEmpty func)
      // func cannot modify owner
      bool isValid() const;

      // TO-DO: Returns m_price
      double price() const;

      // TO-DO: returns m_price X 0.13 (define constant for this), OR returns 0.0 if m_taxed is false
      double tax() const;

      // TO-DO: sets  m_itemName to string pointed by name argument using the setName()
      // sets m_price and m_taxed to corresponding arguments
      void set(const char *name, double price, bool taxed);

      // TO-DO: Prints an item depending on validity
      void display() const;
   };
}

#endif // !SDDS_SUBJECT_H
