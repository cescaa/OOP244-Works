#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds
{ // g++ -Wall -std=c++11 -g -o ws w9Tester.cpp HtmlText.cpp Text.cpp

   // Created using a file name. If the name is not null, it will store it dynamically in the memory and read it from the disk into a dynamically allocated memory (using read()).

   class Text
   {
      char *m_filename; // Holds name of file dynamically
      char *m_content;  // Holds content of file dynamically

      // returns the length of the file on the disk.
      // returns zero if file does not exist or content is empty
      int getFileLength() const;

   protected:
      // Provides read-only access to the content of the text for the derived classes of Text.
      // Not defined if the index goes out of bounds.
      const char &operator[](int index) const;

   public:
      Text(const char *filename = nullptr);
      Text(const Text &other);
      ~Text();

      // read current content of file
      // allocates memory to the size of the file on the disk + 1
      // Read the contents of file character by character into the newly allocated memory and terminates it with null
      void read();

      // Insert the content of the Text class into the ostream if m_content is not null.
      virtual void write(std::ostream &os) const;

      // Overload the insertion operator for a Text object into ostream.
      friend std::ostream &operator<<(std::ostream &os, const Text &text);

      Text &operator=(const Text &other);

      char *getContent() const;
   };
}
#endif // !SDDS_PERSON_H__
