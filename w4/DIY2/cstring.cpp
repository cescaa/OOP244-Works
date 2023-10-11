/*/////////////////////////////////////////////////////////////////////////
Workshop - 1 (Part 2 DIY)
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
#include "cstring.h"

using namespace std;

namespace sdds
{
  // Copies the srouce character string into the destination
  void strCpy(char *des, const char *src) // strCpy(str2, "John ");
  {
    int i;
    for (i = 0; *(src + i) != '\0'; i++)
    {
      *(des + i) = src[i];
    }
    *(des + i) = '\0';
  }

  /* Copies the source character string into the destination up to "len" characters. The destination will be null terminated only if the number of the characters copied is less than "len"*/
  void strnCpy(char *des, const char *src, int len)
  {
    int i;
    for (i = 0; i < len; i++)
    {
      *(des + i) = src[i];
    }
    //*(des + i) = '\0';
  }

  // Compares two C-strings
  // returns 0 i thare the same
  // return > 0 if s1 > s2
  // return < 0 if s1 < s2
  int strCmp(const char *s1, const char *s2)
  {
    int i = 0, flag = 0, uniqueChar = 0;
    while ((s1[i] != '\0' && s2[i] != '\0'))
    {
      if (s1[i] != s2[i])
      {
        uniqueChar = i;
        flag = 1;
      }
      i++;
    }

    if (flag == 0)
    {
      return 0;
    }
    else
    {
      if (int(s1[uniqueChar]) > int(s2[uniqueChar]))
      {

        return 1;
      }

      else
      {
        return -1;
      }
    }
  }

  // returns 0 i thare the same
  // return > 0 if s1 > s2
  // return < 0 if s1 < s2
  int strnCmp(const char *s1, const char *s2, int len)
  {
    int i = 0, flag = 0, uniqueChar = 0;
    while (i < len)
    {
      if (s1[i] != s2[i])
      {
        uniqueChar = i;
        flag = 1;
      }
      i++;
    }

    if (flag == 0)
    {
      return 0;
    }
    else
    {
      if (int(s1[uniqueChar]) > int(s2[uniqueChar]))
      {
        // cout << int(s1[uniqueChar]) << endl;
        // cout << int(s2[uniqueChar]) << endl;

        return 1;
      }
      else
      {
        return -1;
      }
    }
  }

  // returns the length of the C-string in characters
  int strLen(const char *s)
  {
    int counter = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
      counter++;
    }
    return counter;
  }

  // returns the address of first occurance of "str2" in "str1"
  // returns nullptr if no match is found
  const char *strStr(const char *str1, const char *str2)
  {
    int str1Matches = 0, flag = 0, result = -1;
    for (int i = 0; str1[i] != '\0'; i++)
    {
      for (int j = 0; str2[j] != '\0'; j++)
      {
        if (str2[j] == str1[i + j])
        {
          str1Matches++;
        }

        if (str1Matches == strLen(str2) && flag == 0)
        {
          result = i;
          flag = 1;
        }
      }
    }
    const char *p = &(str1[result]);
    return (result != -1) ? p : nullptr;
  }

  // Concantinates "src" C-string to the end of "des"
  void strCat(char *des, const char *src)
  {
    int counter = 0;
    for (int i = 0; *(des + i) != '\0'; i++)
    {
      counter++;
    }
    int lastIdx = counter;

    int i, j = 0;
    for (i = lastIdx; src[j] != '\0'; j++)
    {
      des[i + j] = src[j];
    }
    *(des + i + j) = '\0';
  }
}