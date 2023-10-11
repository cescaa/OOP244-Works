#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
using namespace std;
namespace sdds
{
  class Publication : public Streamable
  {
    char *m_title;                         // 255
    char m_shelfId[SDDS_SHELF_ID_LEN + 1]; // 4 + 1
    int m_memberhsip;
    int m_libRef;
    Date m_date;

  public:
    Publication();

    // has streamable destructor ****
    ~Publication();
    virtual void set(int member_id);
    // Sets the membership attribute to either zero or a five-digit integer.

    void setRef(int value);
    // Sets the **libRef** attribute value

    void resetDate();
    // Sets the date to the current date of the system.

    virtual char type() const;
    // Returns the character 'P' to identify this object as a "Publication object"

    bool onLoan() const;
    // Returns true is the publication is checkout (membership is non-zero)

    Date checkoutDate() const;
    // Returns the date attribute

    bool operator==(const char *title) const;
    /* Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)*/

    operator const char *() const;
    // Returns the title attribute

    int getRef() const;
    // Returns the libRef attirbute.

    // OVERRIDEEEEEE /////////
    ostream &write(ostream &os) const override;
    istream &read(istream &istr) override;
    bool conIO(ios &io) const override;
    operator bool() override;
    //~Publication();

    //Rule of 3
    Publication(const Publication& rhs);
    Publication& operator=(const Publication& rhs);
    /*~Publication();*/
  };
 /* std::ostream& operator<<(std::ostream& ostr, const Publication& obj) {
	  return obj.write(ostr);
  }
  std::istream& operator>>(std::istream& istr, Publication& obj)
  {
	  return (obj.read(istr));
  }*/

}
#endif