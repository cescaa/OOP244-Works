/*/////////////////////////////////////////////////////////////////////////
Workshop - 2 (Part 2 DIY)
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

   // reads postal code data from file
   bool read(char *postal)
   {
      bool result;
      if (fscanf(fptr, "%[^,],", postal))
      {

         result = true;
      }
      else
      {
         result = false;
      }
      return result;
   }

   // reads population data from file
   bool read(int &population)
   {
      bool result;
      if (fscanf(fptr, "%d\n", &population) == 1)
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
