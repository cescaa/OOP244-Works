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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
   FILE *fptr;

   bool openFile(const char filename[])
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   // finds num of employees in file
   int noOfRecords()
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile()
   {
      if (fptr)
         fclose(fptr);
   }

   //////////////// TODO: read functions go here ////////////////
   // accepts reference to an integer
   // reads from file: employee number
   // stores number in the parameter
   bool read(int &m_empNo)
   {
      bool result;
      if (fscanf(fptr, "%d,", &m_empNo) == 1)
      {
         result = true;
      }
      else
      {
         result = false;
      }

      return result;
   }

   // accepts reference to floating point in double precision
   // reads from file: employee salary
   // stores it in the parameter
   bool read(double &m_salary)
   {
      bool result;
      if (fscanf(fptr, "%lf,", &m_salary) == 1)
      {

         result = true;
      }
      else
      {
         result = false;
      }
      return result;
   }

   // accepts address of an array of characters
   // reads from file: name of employee
   // stores name in the parameter
   bool read(char *m_name)
   {
      bool result;
      if (fscanf(fptr, "%[^\n]\n", m_name) == 1)
      {
         result = true;
      }
      else
      {
         result = false;
      }

      return result;
   }

}
