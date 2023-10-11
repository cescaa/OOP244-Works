#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Menu.h"
namespace sdds
{
   // g++ -Wall -std=c++11 -g -o ws ms2_tester.cpp LibApp.cpp Menu.cpp

   class LibApp
   {

      bool m_changed; // tracks changes

      // main menu of the application
      // Title: "Seneca Libray Application"
      Menu m_mainMenu;

      // used when exiting the program
      // Title: "Changes have been made to the data, what would you like to do?"
      Menu m_exitMenu;

      bool confirm(const char *message);
      void load();   // prints: "Loading Data"<NEWLINE>
      void save();   // prints: "Saving Data"<NEWLINE>
      void search(); // prints: "Searching for publication"<NEWLINE>

      void returnPub(); /*  Calls the search() method.
                            prints "Returning publication"<NEWLINE>
                            prints "Publication returned"<NEWLINE>
                            sets m_changed to true;
                        */
      void newPublication();
      void removePublication();
      void checkOutPub();

   public:
      LibApp();
      void run();
   };
}
#endif // !SDDS_LIBAPP_H
