#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds
{
  class CalorieList
  {

    char m_title[26];
    Food *m_foods;

    int m_noOfFoods;
    int m_FoodsAdded;

    void setEmpty();
    bool isValid() const;

  public:
    void init(int size);
    bool add(const char *item_name, int calories, int when);
    int totalCals() const;
    void Title() const;
    void footer() const;
    void display() const;
    void deallocate();
  };
}
#endif // !SDDS_TRANSCRIPT_H
