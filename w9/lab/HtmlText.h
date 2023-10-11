#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include <iostream>
#include "Text.h"
namespace sdds
{
   // g++ -Wall -std=c++11 -g -o ws w9Tester.cpp HtmlText.cpp Text.cpp
   class HtmlText : public Text
   {

      char *m_title; // Holds title of the HTML conversion.

   public:
      HtmlText(const char *filename = nullptr, const char *title = nullptr);
      HtmlText(const HtmlText &other);
      ~HtmlText();
      HtmlText &operator=(const HtmlText &other);

      void write(std::ostream &os) const override;
   };
}
#endif // !SDDS_HTMLTEXT_H__
