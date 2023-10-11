#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Canister.h"
#define PI 3.14159265
using namespace std;

namespace sdds
{
  ////////////////////// DE/CONSTRUCTORS //////////////////////

  // Sets the attributes to default values
  Canister::Canister()
  {
    setToDefault();
  }

  // Sets attributes to default values
  // Sets the Name to the incoming contentName argument.
  Canister::Canister(const char *contentName)
  {

    setToDefault();
    if (contentName != nullptr)
    {
      m_contentName = new char[strLen(contentName) + 1];
      strCpy(m_contentName, contentName);
      // cout << m_contentName << endl;
    }
  }

  /* Sets the attributes to their default values.

  If the dimensions are within acceptable values:
     - set the m_height and m_diameter to the corresponding argument values
     - set the content volume to 0.
     - set the content name to the corresponding argument value.

  If any dimensions have invalid values, set Canister unusable */
  Canister::Canister(double height, double diameter, const char *contentName)
  {

    setToDefault();

    if ((height >= 10.0 && height <= 40.0) && (diameter >= 10.0 && diameter <= 30.0))
    {
      m_height = height;
      m_diameter = diameter;
      m_contentVolume = 0.0;

      if (contentName != nullptr)
      {
        m_contentName = new char[strLen(contentName) + 1];
        strCpy(m_contentName, contentName);
      }
    }
    else
    {
      m_usable = false;
    }
  }

  // Deallocates the dynamic memory pointed by content name
  Canister::~Canister()
  {
    delete[] m_contentName;
  }
  /////////////// DE/CONTRUCTORS *** END *** //////////////////

  //  sets contentName to null, height to 13.0, diameter to 10.0, contentVolume to 0.0 and usable to true
  void Canister::setToDefault()
  {
    m_contentName = nullptr;
    m_height = 13.0;
    m_diameter = 10.0;
    m_contentVolume = 0.0;
    m_usable = true;
  }

  // Sets contentName of the current Canister.
  /* If Cstr is not null and Canister is usable:
     - delete the current content name
     - allocate memory to length of Cstr (+1)
     - copy the Cstr into the newly allocated memory. */
  // Otherwise, do nothing.
  void Canister::setName(const char *Cstr)
  {
    if (Cstr != nullptr && m_usable == true)
    {
      delete[] m_contentName;
      m_contentName = new char[strLen(Cstr) + 1];
      strCpy(m_contentName, Cstr);
    }
  }

  // Returns true is contentVolume is less than 0.00001 CCs
  bool Canister::isEmpty() const
  {
    return m_contentVolume < 0.00001;
  }

  // Compares ContentName of this Canister with the one received from 'C'.
  // Returns true if both contentNames are NOT null and are same
  bool Canister::hasSameContent(const Canister &C) const
  {

    bool result = false;

    if (m_contentName != nullptr && C.m_contentName != nullptr)
    {
      if (strCmp(m_contentName, C.m_contentName) == 0)
      {
        result = true;
      }
    }
    return result;
  }

  /* Set Content name of the canister using these rules:
     - returns the reference of the current object (i.e. *this)
     - If contentName argument is null, render Canister unusable
     - else if the Canister is empty, set the Name to the argument
     - else if name of Canister is not the same as the contentName arg, Canister is unusable.*/
  Canister &Canister::setContent(const char *contentName)
  {

    if (contentName == nullptr)
    {
      m_usable = false;
    }
    if (contentName != nullptr && isEmpty() == true)
    {
      setName(contentName);
    }
    if (hasSameContent(contentName) == false)
    {
      m_usable = false;
    }
    return *this;
  }

  /*
  - Adds quantity to the content volume of the Canister IF the quantity fits:
  - Otherwise, render Canister unusable
  - returns the reference of the current object

  The rules:
  - If the Canister is usable, quantity is > zero, sum of quantity and volume() is <= to capacity(), add the quantity to content volume
  - Otherwise set usable flag to false.*/
  Canister &Canister::pour(double quantity)
  {

    double sum = quantity + volume();
    if (m_usable == true && quantity > 0 && sum <= capacity())
    {
      m_contentVolume += quantity;
    }
    else
    {
      m_usable = false;
    }

    return *this;
  }

  /* Pours content of Canister argument into the current Canister:

     - Set the content name to the Canister argument using setContent().

     - if the volume() of argument is greater than the capacity() minus the volume(),
        - reduce the content volume of the argument by (capacity() - volume())
        - set the content volume to capacity()

     - else, pour the content volume of the argument using pour() and set the content volume of the argument to 0.0.
     - return the reference of the current object*/

  Canister &Canister::pour(Canister &C) // *** typo? ***
  {
    setContent(C.m_contentName);
    double currentLeftover = capacity() - volume();

    if (C.volume() > currentLeftover)
    {
      C.m_contentVolume = C.m_contentVolume - currentLeftover;
      m_contentVolume = capacity();
    }
    else
    {
      pour(C.m_contentVolume);
      C.m_contentVolume = 0.0;
    }
    return *this;
  }

  //  returns the content volume attribute
  double Canister::volume() const
  {
    return m_contentVolume; // in CCs
  }

  // Prints Canister
  // Prints all numbers with one digit after decimal point
  std::ostream &Canister::display() const
  {

    std::cout << std::setprecision(1) << std::fixed;
    char notUsableStr[31] = " of Unusable content, discard!";

    cout << setw(7) << capacity(); // pad
    cout << "cc (" << m_height << "x" << m_diameter << ") Canister";
    if ((m_usable == false && m_contentName == nullptr) || m_usable == false)
    {
      cout << notUsableStr;
    }
    else if (m_usable == true && m_contentName != nullptr)
    {
      cout << " of " << setw(7) << m_contentVolume;
      cout << "cc   " << m_contentName;
    }
    return std::cout;
  }

  // returns the capacity
  double Canister::capacity() const
  {
    return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
  }

  /* Clears unusable Canister back to empty:
     - deallocate memory pointed by the content name
     - sets content name to nullptr
     - sets content volume to 0.0
     - set the usable attribute to true */
  void Canister::clear()
  {
    if (m_usable == false)
    {
      delete[] m_contentName; // note to self: call destructor?
      setToDefault();
    }
  }
}

// g++ -o ws Canister.cpp canisterMain.cpp cstring.cpp
