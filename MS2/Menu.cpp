#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include <limits>
#include <ctime>
#include "Menu.h"

namespace sdds
{
	MenuItem::MenuItem()
	{
		itemName = nullptr;
	}

	MenuItem::MenuItem(const char *p_itemName)
	{
		if (p_itemName != nullptr)
		{
			int length = strlen(p_itemName); // get length
			itemName = new char[length + 1]; // DAM
			strcpy(itemName, p_itemName);		 // sets content of MenuItem
		}
		else
		{
			itemName = nullptr; // set itemName to null if p_itemName is null
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] itemName;
	}

	MenuItem::operator bool() const
	{
		bool result = false;
		if (itemName != nullptr)
		{
			result = true;
		}
		return result;
	}

	// display the content of the MenuItem
	void MenuItem::displayMenuItem(ostream &os)
	{
		if (itemName != nullptr)
		{
			os << itemName;
		}
	}

	////////////////////////// MENU //////////////////////////

	void Menu::setEmpty()
	{
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i)
		{
			menuItems[i] = nullptr;
		}
		menuTitle = nullptr;
		numOfMenuItems = 0;
	}

	Menu::Menu()
	{
		setEmpty();
	}

	Menu::Menu(const char *p_menuTitle)
	{
		setEmpty();

		if (p_menuTitle != nullptr)
		{
			menuTitle = nullptr;
			menuTitle = new MenuItem(p_menuTitle); // Allocate memory for single MenuItem object to hold menuTitle with p_menuTitle
		}
	}

	Menu::~Menu()
	{
		for (int i = 0; i < numOfMenuItems; ++i)
		{
			delete menuItems[i];
			menuItems[i] = nullptr;
		}
		delete menuTitle;
		menuTitle = nullptr;
	}

	void Menu::displayMenu(ostream &os)
	{
		// code to display title ///
		if (menuTitle != nullptr)
			cout << menuTitle->itemName << endl;
		// display menu contents
		for (int i = 0; i < numOfMenuItems; ++i)
		{
			os << " " << (i + 1) << "- ";
			os << menuItems[i]->itemName << endl; // Display itemName of menuItem at i
		}

		os << " 0- Exit" << endl
			 << "> ";
	}

	unsigned int Menu::run()
	{
		displayMenu(std::cout);

		int userSelect;
		cin >> userSelect;

		while (cin.fail() || userSelect < 0 || userSelect > numOfMenuItems)
		{
			cout << "Invalid Selection, try again: ";

			cin >> userSelect;
		}

		return userSelect;
	}

	unsigned int Menu::operator~()
	{
		return run();
	}

	//  add a MenuItem to the Menu
	// receives a C-style string containing the content of the MenuItem and returns the reference of the Menu object (*this).
	Menu &Menu::operator<<(const char *newItem)
	{
		if (static_cast<unsigned int>(numOfMenuItems) < MAX_MENU_ITEMS)
		{
			MenuItem *menuItemObj = new MenuItem(newItem); // Initialize a new MenuItem with the title
			menuItems[numOfMenuItems] = menuItemObj;			 // Assign the menuItem to the array
			numOfMenuItems++;
		}

		return *this;
	}

	// Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
	Menu::operator int() const
	{
		return numOfMenuItems;
	}

	Menu::operator unsigned int() const
	{
		return numOfMenuItems;
	}

	// Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
	Menu::operator bool() const
	{
		return numOfMenuItems > 0;
	}
	// Overload the insertion operator to print the title of the Menu using cout.
	std::ostream &operator<<(std::ostream &cout, const Menu &menuObj)
	{
		if (menuObj.menuTitle != nullptr)
			cout << menuObj.menuTitle->itemName; // ostream itemName of menuTitle from menuObj
		return cout;
	}

	// If the index passes the number of MenuItems in the Menu, loop back to the beginning.
	const char *Menu::operator[](int idx) const
	{
		if (idx > numOfMenuItems)
		{
			idx = 1;
		}
		const char *constStr = (const char *)menuItems[idx]->itemName; // display itemName from menuItems
		return constStr;
	}

}
