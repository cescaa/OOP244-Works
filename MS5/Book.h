#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Lib.h"
// #include "Date.h"
#include "Publication.h"
using namespace std;
namespace sdds
{
  class Book : public Publication
  {
    char *authorName; // DAM
  public:
    // A book is created empty by default, in a safe empty state.
    Book();

    // The rule of three
    Book(const Book &other);
    Book &operator=(const Book &other);
    ~Book();

    // OVERRIDESSSSSS

    void display() const
    {
	    cout << authorName << endl;
    }

    char type() const override;
    ostream &write(ostream &os) const override;
    istream &read(istream &istr) override;
    void set(int member_id) override;
    operator bool() override;
  };
}
#endif