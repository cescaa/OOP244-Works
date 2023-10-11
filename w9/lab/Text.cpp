
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "Text.h"

using namespace std;

namespace sdds
{

   int Text::getFileLength() const
   {
      int len = 0;
      ifstream fin(m_filename);
      while (fin)
      {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   // CONSTRUCTOR
   Text::Text(const char *filename)
   {
      m_filename = nullptr;
      m_content = nullptr;

      // DAM
      if (filename != nullptr)
      {
         m_filename = new char[strlen(filename) + 1];
         strcpy(m_filename, filename);
         read(); // store file content into m_content
      }
   }

   // Copy constructor
   Text::Text(const Text &other)
   {
      m_filename = nullptr;
      m_content = nullptr;

      *this = other; // Use the copy assignment operator to perform the deep copy
   }

   Text::~Text()
   {
      delete[] m_filename;
      delete[] m_content;
      m_filename = nullptr;
      m_content = nullptr;
   }

   // CHECK --- Might be buggy
   const char &Text::operator[](int index) const
   {
      /*if (index < 0 || index >= getFileLength())
      {
         return m_content[0];
      }
      else
      {
         return m_content[index];
      } */
      return m_content[index];
   }

   void Text::read()
   {
      int length = getFileLength();

      // allocates memory to the size of the file
      m_content = new char[length + 1];

      ifstream file(m_filename); // make file obj

      int idx = 0;
      char ch;

      while (file.get(ch)) // read each char
      {
         m_content[idx++] = ch;
      }
      m_content[idx] = '\0'; // terminates with null
   }

   void Text::write(std::ostream &os) const
   {

      if (m_content != nullptr)
      {
         os << m_content;
      }
   }

   ostream &operator<<(std::ostream &os, const Text &text)
   {
      text.write(os);
      return os;
   }

   // copy assignment
   Text &Text::operator=(const Text &other)
   {
      if (this != &other)
      {
         if (other.m_filename != nullptr && other.m_content != nullptr)
         {
            delete[] m_filename;
            delete[] m_content;

            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);

            m_content = new char[strlen(other.m_content) + 1];
            strcpy(m_content, other.m_content);
         }
      }
      return *this;
   }

   char *Text::getContent() const
   {
      return m_content;
   }
};

// g++ -Wall -std=c++11 -g -o ws w9Tester.cpp HtmlText.cpp Text.cpp
// g++ -Wall -std=c++11 -g -o ws w9Tester_prof.cpp HtmlText.cpp Text.cpp