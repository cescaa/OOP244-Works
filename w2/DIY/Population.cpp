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

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
  int noOfRecs;
  Population *populations;

  void sort()
  {
    int i, j;
    Population temp;
    for (i = noOfRecs - 1; i > 0; i--)
    {
      for (j = 0; j < i; j++)
      {
        if (populations[j].poulation > populations[j + 1].poulation)
        {
          temp = populations[j];
          populations[j] = populations[j + 1];
          populations[j + 1] = temp;
        }
      }
    }
  }

  // load a single record from file into employees attributes
  bool load(Population &populations)
  {
    bool result = false;
    char postalCode[10];

    // read postal code + population data from file
    if (read(postalCode) == true && read(populations.poulation) == true)
    {
      // find the actual length + 1 of the employee name
      int postalLen = strLen(postalCode) + 1;

      // dynamic allocation
      populations.postal = nullptr;
      populations.postal = new char[postalLen];
      strCpy(populations.postal, postalCode);

      populations.postal[postalLen - 1] = '\0';
      result = true;
    }
    else
    {
      result = false;
    }

    return result;
  }

  // load(): loads file data, returns true if loaded
  bool load(const char filename[])
  {
    bool result = false;
    int i = 0;
    int correctLoads = 0;

    // check if file is open
    if (openFile(filename))
    {
      // get num of records
      noOfRecs = noOfRecords();

      // dyanamically allocation of array for all records
      populations = nullptr;
      populations = new Population[noOfRecs];

      // store each record from file into array
      for (i = 0; i < noOfRecs; i++)
      {
        if (load(populations[i]) == true)
        {
          correctLoads++;
        }
      }
      // check each record was stored correctly
      result = (correctLoads == noOfRecs) ? true : false;

      if (correctLoads != noOfRecs)
      {
        cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
      }

      closeFile(); // close file
    }
    else
    {
      cout << "Could not open data file: " << filename << endl;
      result = false;
    }
    return result;
  }

  // display(): prints the report
  void display()
  {
    int populationTotal = 0;

    cout << "Postal Code: population" << endl
         << "-------------------------" << endl;

    // sort by population num
    sort();

    // display each record
    for (int i = 0; i < noOfRecs; i++)
    {
      cout << i + 1 << "- ";
      cout << populations[i].postal << ":  " << populations[i].poulation << endl;

      // add to population total
      populationTotal += populations[i].poulation;
    }
    cout << "-------------------------" << endl;
    cout << "Population of Canada: " << populationTotal << endl;
  }

  // deallocateMemory(): deallocate dynamic memory
  void deallocateMemory()
  {
    for (int i = 0; i < noOfRecs; i++)
    {
      delete[] populations[i].postal;
      populations[i].postal = nullptr;
    }
    delete[] populations;
    populations = nullptr;
  }

}