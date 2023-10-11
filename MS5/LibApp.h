#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Publication.h"
#include "Lib.h"
#include "Menu.h"
using namespace std;
namespace sdds
{
	class LibApp
	{
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char m_filename[256];
		Publication *m_pubs[SDDS_LIBRARY_CAPACITY];
		int NOLP; // Nuum of loaded pubs
		int LLRN; // last lib ref
		Menu m_pubTypeMenu;
		bool confirm(const char *message);
		void load();
		void save();		 // prints: "Saving Data"<NEWLINE>
		int search(int); // prints: "Searching for publication"<NEWLINE>

		void returnPub();

	public:
		LibApp();
		LibApp(const char *filename);
		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();
		~LibApp();
		Publication *getPub(int libRef);
	};
}
#endif // !SDDS_LIBAPP_H
