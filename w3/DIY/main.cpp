/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Food.h"
using namespace sdds;
using namespace std;

int main()
{
  Food F;
  F.set("Apples", 100, 1);
  F.display();

  F.set(nullptr, 100, 1);
  F.display();

  F.set("Oranges", 4000, 1);
  F.display();

  F.set("", -1000, 1);
  F.display();

  F.set("Apple", 1000, 0);
  F.display();

  return 0;
}