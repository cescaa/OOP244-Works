#include <iostream>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;

namespace sdds
{

  void CalorieList::setEmpty()
  {
    m_title[0] = '\0';
    m_foods = nullptr; // Food obj
    // m_noOfFoods = 0;
    // m_FoodsAdded = 0;
  }

  bool CalorieList::isValid() const
  {
    bool result = true;

    if (m_title[0] != '\0' && m_foods != nullptr)
    {

      for (int i = 0; i < m_noOfFoods; i++)
      {
        if (!m_foods[i].isValid())
        {
          return false;
        }
      }
    }
    else
    {
      result = false;
    }

    return result;
  }

  void CalorieList::init(int size)
  {
    if (size > 0)
    {
      // Daily Calorie Consumption
      strnCpy(m_title, "Daily Calorie Consumption", 25);
      m_title[25] = '\0';

      m_noOfFoods = size; // store num of foods in list
      m_FoodsAdded = 0;   // initialize added foods

      m_foods = nullptr;
      m_foods = new Food[m_noOfFoods];

      // ensure all Food objs are set to empty/safe
      for (int i = 0; i < m_noOfFoods; i++)
      {
        m_foods[i].setEmpty();
      }
    }
    else
    {
      setEmpty();
    }
  }

  bool CalorieList::add(const char *item_name, int calories, int when)
  {
    int result;
    if (m_FoodsAdded < m_noOfFoods)
    {
      m_foods[m_FoodsAdded].set(item_name, calories, when);
      m_foods[m_FoodsAdded].getTimeString(when);
      m_FoodsAdded++;
      result = true;
    }
    else
    {
      result = false;
    }
    return result;
  }

  int CalorieList::totalCals() const
  {
    int calSum = 0;
    for (int i = 0; i < m_noOfFoods; i++)
    {
      calSum += m_foods[i].getCals();
    }
    return calSum;
  }

  void CalorieList::Title() const
  {
    cout << "+----------------------------------------------------+" << endl;

    if (isValid() == true)
    {
      cout << "|  ";
      cout.fill(' ');
      cout.width(49);
      cout.unsetf(ios::adjustfield);
      cout.setf(ios::left);
      cout << m_title << " |" << endl;
    }
    else
    {
      cout << "| Invalid Calorie Consumption list                   |" << endl;
    }
    cout << "+--------------------------------+------+------------+" << endl;
    cout << "| Food name                      | Cals | When       |" << endl;
    cout << "+--------------------------------+------+------------+" << endl;
  }

  void CalorieList::footer() const
  {
    cout << "+--------------------------------+------+------------+" << endl;
    if (isValid() == true)
    {
      cout << "|    Total Calories for today: ";
      cout.fill(' ');
      cout.width(8);
      cout.setf(ios::right);
      cout << totalCals() << " |";
      cout << "            |" << endl;
    }
    else
    {
      cout << "|    Invalid Calorie Consumption list                |" << endl;
    }
    cout << "+----------------------------------------------------+" << endl;
  }

  void CalorieList::display() const
  {
    Title();
    for (int i = 0; i < m_noOfFoods; i++)
    {
      m_foods[i].display();
    }
    footer();
  }

  void CalorieList::deallocate()
  {
    delete[] m_foods;
    m_foods = nullptr;
  }
}
