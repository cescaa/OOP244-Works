#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

// g++ -Wall -std=c++11 -g -o ws
namespace sdds
{

   class Account
   {

      int m_number;     // account num
      double m_balance; // account balance

      // invalid account
      void setEmpty();

   public:
      // new/not set account
      Account();

      // valid account
      Account(int number, double balance);

      std::ostream &display() const;

      // operator bool
      // returns true if the account is valid and otherwise false
      operator bool() const;

      // operator int
      // returns the account number
      operator int() const;

      // operator double
      // returns the balance value
      operator double() const;

      // Unary member operator
      // bool operator ~()
      // returns true is the account is new or not set
      bool operator~() const;

      //////////// ~~ Binary member operators ~~  ////////////
      // All binary member operators will NOT TAKE ANY ACTION if the account is invalid.

      // ONE ---
      // overload = opt so a NEW account can be set to an integer:
      // - set the account number to integer.
      // - If integer is invalid, set object to an invalid state
      // - If the account is invalid, then this operator should not perform any action.
      // - current object is returned
      Account &operator=(int accNum);

      // TWO ---
      // set NEW account to another Account object --
      // Move the balance and the account number from one account to another:

      // - the balance of the left account is set to balance of right
      // - balance of the right account will be set to zero
      // - the same will happen to the account number
      // If the left Account operand is not new or the right account operand is not valid, no action should be taken.
      // current object (account) is returned
      Account &operator=(Account &rightAcc);

      // THREE ---
      // overload the +=
      // - double should be added to balance
      // if account is invalid or the double value is negative, no action
      // current object is returned
      Account &operator+=(double num);

      // FOUR ---
      // -= operator to reduce an account balance by a double:
      // - value of the balance should be reduced by the double
      Account &operator-=(double num);

      // FIVE ---
      // << operator to move funds from right account to left.
      // After this operation, balance of the left account is the sum of both and the balance of the right  is 0
      // Funds of an account should not be able to be moved to itself
      Account &operator<<(Account &sourceAcc);

      // SIX ---
      // overload the >> operator to move funds from the left account to the right
      // After operation, balance of the right account is sum of both and the balance of the left account is  0
      // Funds of an account should not be able to be moved to itself
      Account &operator>>(Account &destAcc);
   };
   ///////// Binary helper operators //////////////

   // create a binary stand alone helper + operator:
   // - accepts a constant account reference at left + another constant account reference at right
   // - returns a double value
   // - Double value should be the sum of the balances of the two accounts
   // If any of the two accounts is invalid, then 0 is returned
   double operator+(const Account &rightAcc, const Account &leftAcc);

   // - value of the balance of the right operand should be added to the left operand
   double operator+=(double &num, const Account &rightAcc);

}
#endif // SDDS_ACCOUNT_H_