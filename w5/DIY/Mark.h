#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

// g++ -Wall -std=c++11 -g -o ws
namespace sdds
{
  class Mark
  {
    int markVal;
    void setEmpty();

  public:
    Mark();
    Mark(int val);
    bool markIsValid();
    int getMark()
    {

      return markVal;
    };
    operator int();
    // Mark &operator+=(sdds::Mark &left, int addVal);
    Mark &operator+=(int addVal);
    Mark &operator=(int newMark);
    operator double();
    operator char();
    // int &operator+=(int &left, const Mark &right);
  };

  int &operator+=(int &val, Mark &obj);
}
#endif