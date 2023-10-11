#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
   void Account::setEmpty()
   {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account()
   {
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance)
   {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream &Account::display() const
   {
      if (*this)
      {
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if (~*this)
      {
         cout << "  NEW  |         0.00 ";
      }
      else
      {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   /////////////////////////////////////////////////

   // check if account is valid
   Account::operator bool() const
   {
      bool result = false;
      if (m_number > 9999 && m_number <= 99999)
      {
         result = true;
      }
      else
      {
         result = false;
      }
      return result;
   }

   // return account num
   Account::operator int() const
   {
      return m_number;
   }

   // return balance
   Account::operator double() const
   {
      return m_balance;
   }

   // check if account is new or not set
   bool Account::operator~() const
   {
      bool result = false;
      if (m_number == 0)
      {
         result = true;
      }
      return result;
   }

   // Account number must be 5 digits
   Account &Account::operator=(int accNum)
   {
      if ((~*this)) // call bool?
      {
         if (accNum > 9999 && accNum <= 99999)
         {
            m_number = accNum;
         }
         else
         {

            // set empty
            setEmpty();
         }
      }
      return *this;
   }

   Account &Account::operator=(Account &rightAcc)
   {
      if (~*this && rightAcc)
      {
         m_number = rightAcc.m_number;
         m_balance = rightAcc.m_balance;
         rightAcc.m_number = 0;
         rightAcc.m_balance = 0;
      }

      return *this;
   }

   Account &Account::operator+=(double num)
   {
      if ((*this) && num >= 0)
      {
         m_balance = m_balance + num;
      }
      return *this;
   }

   Account &Account::operator-=(double num)
   {
      if ((*this) && num >= 0 && m_balance >= num)
      {
         m_balance = m_balance - num;
      }
      return *this;
   }

   Account &Account::operator<<(Account &sourceAcc)
   {
      if (&sourceAcc != this && (*this) && (sourceAcc))
      {
         m_balance = m_balance + sourceAcc.m_balance;
         sourceAcc.m_balance = 0;
      }
      return *this;
   }

   Account &Account::operator>>(Account &destAcc)
   {
      if (&destAcc != this && (*this) && (destAcc))
      {
         destAcc.m_balance = m_balance + destAcc.m_balance;
         m_balance = 0;
      }
      return *this;
   }

   double operator+(const Account &rightAcc, const Account &leftAcc)
   {
      double sum = 0;
      if (rightAcc && leftAcc)
      {
         sum = double(rightAcc) + double(leftAcc);
      }
      else
      {
         sum = 0;
      }

      return sum;
   }

   double operator+=(double &num, const Account &rightAcc)
   {
      if (rightAcc && num >= 0)
      {
         num = num + double(rightAcc);
      }

      return num;
   }
}

// g++ -Wall -std=c++11 -g -o ws Account.cpp accountMain.cpp