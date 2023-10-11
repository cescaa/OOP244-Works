#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
using namespace std;

namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu; // Forward declare of Menu class

	// fully private
	class MenuItem
	{
	public:
		char *itemName; // DAM
		friend class Menu;

		// Constructors ~~~
		MenuItem();
		MenuItem(const char *p_itemName);

		// Rule of Three ~~~
		// Delete copy constructor
		MenuItem(const MenuItem &other) = delete;
		// Delete copy assignment operator
		MenuItem &operator=(const MenuItem &other) = delete;

		// Destructor ~~~
		~MenuItem();

		// bool type conversion ~~~
		operator bool() const;

		// const char* type conversion ~~~
		operator const char *() const;

		// displaying the MenuItem ~~~
		void displayMenuItem(std::ostream &os);
	};

	class Menu
	{
		// Rule of Three ~~~
		// Delete copy constructor
		Menu(const Menu &other) = delete;
		// Delete copy assignment operator
		Menu &operator=(const Menu &other) = delete;

		MenuItem *menuTitle;								 // holds title of menu
		MenuItem *menuItems[MAX_MENU_ITEMS]; // An array of MenuItem pointers; init all to nullptr
		int numOfMenuItems;									 // 0 - MAX_MENU_ITEMS
		void setEmpty();

	public:
		Menu();
		Menu(const char *p_menuTitle);
		~Menu();

		void displayMenu(ostream &os);
		unsigned int run();
		unsigned int operator~();
		Menu &operator<<(const char *newItem);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		friend std::ostream &operator<<(std::ostream &cout, const Menu &menuObj);
		const char *operator[](int idx) const;
	};

}

#endif