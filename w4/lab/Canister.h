#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds
{
   class Canister
   {

      char *m_contentName;
      double m_diameter;      // in centimeters
      double m_height;        // in centimeters
      double m_contentVolume; // in CCs
      bool m_usable;

      // sets  attributes to default values
      //  sets contentName to null, height to 13.0, diameter to 10.0, contentVolume to 0.0 and usable to true
      void setToDefault();

      // Sets contentName of the current Canister.
      /* If Cstr is not null and Canister is usable:
         - delete the current content name
         - allocate memory to length of Cstr (+1)
         - copy the Cstr into the newly allocated memory. */
      // Otherwise, do nothing.
      void setName(const char *Cstr);

      // Returns true is contentVolume is less than 0.00001 CCs
      bool isEmpty() const;

      // Compares ContentName of this Canister with the one received from 'C'.
      // Returns true if both contentNames are NOT null and are same
      bool hasSameContent(const Canister &C) const;

   public:
      // Sets the attributes to default values
      Canister();

      // Sets attributes to default values
      // Sets the Name to the incoming contentName argument.
      Canister(const char *contentName);

      /* Sets the attributes to their default values.

      If the dimensions are within acceptable values:
         - set the m_height and m_diameter to the corresponding argument values
         - set the content volume to 0.
         - set the content name to the corresponding argument value.

      If any dimensions have invalid values, set Canister unusable */
      Canister(double height, double diameter,
               const char *contentName = nullptr);

      // Deallocates the dynamic memory pointed by content name
      ~Canister();

      /* Set Content name of the canister using these rules:
         - returns the reference of the current object (i.e. *this
         - If contentName argument is null, render Canister unusable
         - else if the Canister is empty, set the Name to the argument
         - else if name of Canister is not the same as the contentName arg, Canister is unusable.*/
      Canister &setContent(const char *contentName);

      /*
      - Adds quantity to the content volume of the Canister IF the quantity fits:
      - Otherwise, render Canister unusable
      - returns the reference of the current object

      The rules:
      - If the Canister is usable, quantity is > zero, sum of quantity and volume() is <= to capacity(), add the quantity to content volume
      - Otherwise set usable flag to false.*/
      Canister &pour(double quantity);

      /* Pours content of the Canister argument into the current Canister:

         - Set the content name to the Canister argument using setContent().
         - if the volume() of the argument is greater than the capacity() minus the volume(), reduce the content volume of the argument by (capacity() - volume()) and set the content volume to capacity()
         - else, pour the content volume of the argument using pour() and set the content volume of the argument to 0.0.
         - return the reference of the current object*/
      Canister &pour(Canister &C);

      //  returns the content volume attribute
      double volume() const;

      // Prints Canister
      // Prints all numbers with one digit after decimal point
      std::ostream &display() const;

      // returns the capacity
      double capacity() const;

      /* Clears unusable Canister back to empty:
         - deallocate memory pointed by the content name
         - sets content name to nullptr
         - sets content volume to 0.0
         - set the usable attribute to true */
      void clear();
   };
}

#endif // !SDDS_BOX_H
