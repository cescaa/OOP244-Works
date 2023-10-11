#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <limits>
#include "Book.h"
using namespace std;

namespace sdds
{
  Book::Book()
  {
    authorName = nullptr;
  }

  Book::Book(const Book &other) : Publication(other)
  {
    
    if (other.authorName != nullptr)
    {
      authorName = new char[strlen(other.authorName) + 1];
      strcpy(authorName, other.authorName);
    }
    else
    {
           authorName = nullptr;
    }
  }

  Book &Book::operator=(const Book &other)
  {
    if (this != &other)
    {
      // Call the base class's copy assignment operator
      // Publication::operator=(other);
      Publication::operator=(other);
           if (authorName != nullptr) {
                  delete[] authorName;
                  
        }

      if (other.authorName != nullptr)
      {
        authorName = new char[strlen(other.authorName) + 1];
        strcpy(authorName, other.authorName);
      }
      else
      {
             authorName = nullptr;
      }
    }
    return *this;
  }

  Book::~Book()
  {
         if (authorName != nullptr) {
              delete[] authorName;
              authorName = nullptr;
    }
  }

  char Book::type() const
  {
    return 'B';
  }

  // invoke the set of the base class to set the member id
  // reset the date to the current date.
  void Book::set(int member_id)
  {
    Publication::set(member_id);
    Publication::resetDate();
  }

  Book::operator bool() // may have ERROR
  {

    return (authorName != nullptr && authorName[0] != '\0' && Publication::operator bool());
  }

  ostream &Book::write(ostream &os) const
  {
         Publication::write(os);
         if (conIO(os)) 
         {
                if (authorName!=nullptr)
                {
                       char temp[SDDS_AUTHOR_WIDTH + 1] = { 0 };
                       strncpy(temp, authorName, SDDS_AUTHOR_WIDTH);
                       os << " " << setw(SDDS_AUTHOR_WIDTH) << std::left <<
                              std::setfill(' ') << temp << " |";
                }
         }
         else 
         {
                os << "\t";
                os << authorName;
         }
         return os;
  }

  istream &Book::read(istream &istr)
  {
         
         Publication::read(istr);
         if (authorName != NULL) 
                delete[]authorName;
         char nameAuther[256]={0};
         if (conIO(istr) == true)
         {
                istr.ignore(1, '\n');
                cout << "Author: ";
                istr.getline(nameAuther, 256);

         }
         else
         {
                istr.ignore(1, '\t');
                int j = 0;
                for (j = 0; j < SDDS_AUTHOR_WIDTH && istr.peek() != '\n'; j++)
                {
                     char ch;
                     istr.get(ch);
                     nameAuther[j] = ch;
                     if (istr.peek() == '\n' && j != SDDS_AUTHOR_WIDTH - 1)
                     {
                            continue;
                     }
                }
         }
         if (istr.fail())
         {
                authorName = nullptr;
         }
         else
         {
                authorName = new char[strlen(nameAuther) + 1];
                strcpy(authorName, nameAuther);
         }
         return istr;
  }
}

/*
 if (!(strlen(authorName) > 0 || strlen(authorName) <= 256))
    {
      authorName[0] = '\0';
      // Set the istr to a fail state manually
      istr.setstate(std::ios::failbit);
    }
*/