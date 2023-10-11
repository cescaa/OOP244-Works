/*/////////////////////////////////////////////////////////////////////////
Workshop - 2 (Part 1 LAB)
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "cstring.h" // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds
{

   int noOfEmployees;
   Employee *employees;

   void sort()
   {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--)
      {
         for (j = 0; j < i; j++)
         {
            if (employees[j].m_empNo > employees[j + 1].m_empNo)
            {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }
   // load a single record from file into employees attributes
   bool load(Employee &employees)
   {
      bool ok = false;
      char name[128];

      // read employee num, salary, name data from file
      // store the number + salary read into the attributes of parameter
      if (read(employees.m_empNo) == true && read(employees.m_salary) == true && read(name) == true)
      {
         // find the actual length + 1 of the employee name
         int nameLen = strLen(name) + 1;

         // dynamic allocation
         employees.m_name = nullptr;
         employees.m_name = new char[nameLen];
         strCpy(employees.m_name, name);

         employees.m_name[nameLen - 1] = '\0';

         // return true if ALL successful
         ok = true;
      }
      else
      {
         ok = false;
      }

      return ok;
   }
   // loads all records into employees struct
   bool load()
   {
      bool ok = false;
      int i = 0;
      int correctLoads = 0;

      // check if file is open
      if (openFile(DATAFILE))
      {
         // set the noOfEmployees
         noOfEmployees = noOfRecords();

         // dyanamically allocate of employees into Employee pointer
         employees = nullptr;
         employees = new Employee[noOfEmployees];

         // store each record from file into array
         for (i = 0; i < noOfEmployees; i++)
         {
            load(employees[i]);
            correctLoads++;
         }
         // check each record was stored correctly
         ok = (correctLoads == noOfEmployees) ? true : false;

         closeFile(); // close file
      }
      else
      {
         cout << "Could not open data file: " << DATAFILE << endl;
      }
      return ok;
   }

   // display a single record
   void display(const Employee &employees)
   {
      cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
   }

   // call sort() and display all
   void display()
   {
      cout << "Employee Salary report, sorted by employee number" << endl
           << "no- Empno, Name, Salary" << endl
           << "------------------------------------------------" << endl;

      // sort by employee num
      sort();

      // display each record
      for (int i = 0; i < noOfEmployees; i++)
      {
         cout << i + 1 << "- ";
         display(employees[i]);
      }
   }

   void deallocateMemory()
   {
      for (int i = 0; i < noOfEmployees; i++)
      {
         delete[] employees[i].m_name;
         employees[i].m_name = nullptr;
      }

      delete[] employees;
      employees = nullptr;
   }
}