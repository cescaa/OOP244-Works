/*Overload the "*=" operator to multiply a double value to m_data and return the reference of the current object.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class MyDouble
{
  double m_data;

public:
  MyDouble(double val = 0.0)
  {

    m_data = val;
  }

  void prn()
  {

    cout << m_data << endl;
  }

  // your code will go here
};

int main()
{

  MyDouble I(200), J;

  J = I *= 10.3;

  I.prn();

  J.prn();

  return 0;
}

/*
  const MyDouble &operator*=(double m_data)
  {
    return *this;
  }*/