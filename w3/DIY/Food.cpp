#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"

using namespace std;

namespace sdds
{

  void Food::setName(const char *name)
  {
    strnCpy(m_foodName, name, 30);
    m_foodName[30] = '\0';
  }

  void Food::setEmpty()
  {
    m_foodName[0] = '\0';
    m_cal = -1;
    m_time = -1;
    timeString[0] = '\0';
  }

  void Food::getTimeString(int time)
  {
    if (time == 1)
    {
      strCpy(timeString, "Breakfast");
    }
    else if (time == 2)
    {
      strCpy(timeString, "Lunch");
    }
    else if (time == 3)
    {
      strCpy(timeString, "Dinner");
    }
    else if (time == 4)
    {
      strCpy(timeString, "Snack");
    }
  }

  bool Food::isValid() const
  {
    return (m_foodName[0] != '\0' && m_cal != 0 && m_time != 0);
  }

  void Food::set(const char *name, int cal, int time)
  {
    if (name != nullptr && (cal >= 0 && cal <= 3000) && (time >= 1 && time <= 4))
    {
      setName(name);
      m_cal = cal;
      m_time = time;
    }
    else
    {
      setEmpty();
    }
  }

  int Food::getCals() const
  {
    return m_cal;
  }

  void Food::display() const
  {
    if (isValid())
    {

      cout << "| ";
      cout.fill('.');
      cout.width(30);
      cout.setf(ios::left);
      cout << m_foodName;

      cout << " | ";
      cout.fill(' ');
      cout.width(4);
      cout.setf(ios::right);
      cout << m_cal << " | ";

      cout.fill(' ');
      cout.width(10);
      cout.unsetf(ios::adjustfield);
      cout.setf(ios::left);
      cout << timeString << " |" << endl;
    }
    else
    {
      cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
    }
  }
}
