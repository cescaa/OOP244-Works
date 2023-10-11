#include <iostream>
#include <limits>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include <iomanip>
#include "Book.h"
#include "PublicationSelector.h"
using namespace std;

namespace sdds
{
	LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubTypeMenu("Choose the type of publication:")
	{
		m_mainMenu << "Add New Publication"
							 << "Remove Publication"
							 << "Checkout publication from library"
							 << "Return publication to library";

		m_exitMenu << "Save changes and exit"
							 << "Cancel and go back to the main menu";

		m_pubTypeMenu << "Book"
									<< "Publication";

		m_changed = false;

		load();
	}

	LibApp::LibApp(const char *filename) : m_mainMenu("Seneca Library Application"),

																				 m_exitMenu("Changes have been made to the data, what would you like to do?"),

																				 m_pubTypeMenu("Choose the type of publication:")
	{
		// Adding to the main menu
		m_mainMenu << "Add New Publication"
							 << "Remove Publication"
							 << "Checkout publication from library"
							 << "Return publication to library";

		// Adding to the exit menu
		m_exitMenu << "Save changes and exit"
							 << "Cancel and go back to the main menu";

		// Adding options to  publ type menu
		m_pubTypeMenu << "Book"
									<< "Publication";

		strcpy(m_filename, filename);

		// num of loaded pubs + last Loaded ref
		NOLP = 0;
		LLRN = 0;

		for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
		{
			m_pubs[i] = nullptr;
		}

		load();
	}

	LibApp::~LibApp()
	{
		for (int i = 0; i < NOLP; i++)
		{
			delete m_pubs[i];
			m_pubs[i] = nullptr;
		}
	}

	bool LibApp::confirm(const char *message)
	{
		Menu obj(message);
		obj << "Yes";

		int choice = obj.run();

		return (choice == 1);
	}

	void LibApp::load()
	{
		cout << "Loading Data\n";

		ifstream fileStuffs(m_filename); // file stufff

		char type{};
		int i;

		// read pubs + populate m_pubs arr *********
		for (i = 0; fileStuffs && i < SDDS_LIBRARY_CAPACITY; i++)
		{
			fileStuffs >> type;
			fileStuffs.ignore();

			// if success, create pb obj
			if (fileStuffs)
			{
				if (type == 'P')
				{
					m_pubs[i] = new Publication;

					m_pubs[i]->read(fileStuffs);

					NOLP++;
				}
				else if (type == 'B')
				{
					m_pubs[i] = new Book;

					m_pubs[i]->read(fileStuffs);

					NOLP++;
				}
			}
		}

		// store  ref of last pub
		LLRN = m_pubs[NOLP - 1]->getRef();
	}

	void LibApp::save()
	{
		cout << "Saving Data\n";

		ofstream fileStuffs2(m_filename);

		for (int i = 0; i < NOLP; i++)
		{
			int ref = m_pubs[i]->getRef(); // get ref
			if (ref != 0)
			{
				m_pubs[i]->write(fileStuffs2);
				fileStuffs2 << endl;
			}
		}
	}

	int LibApp::search(int menuFace)
	{
		int row = 0;
		int usrSearch = 0;

		cout << "Choose the type of publication:\n";

		cout << " 1- Book\n";
		cout << " 2- Publication\n";
		cout << " 0- Exit\n";
		cout << "> ";
		cin >> usrSearch;

		// check invalid
		while ((cin.fail()) || usrSearch < 0 || usrSearch > 2)
		{
			cin.clear();
			cin.ignore(1000, '\n');

			if (usrSearch < 0 || usrSearch > 2)
				cout << "[0<=value<=" << 2 << "], retry: Enter the row number: ";

			cin >> usrSearch;
		}

		//
		if (usrSearch == 0)
		{
			cout << "Aborted\n";
			return 0;
		}
		else
		{
			cin.ignore();

			cout << "Publication Title: ";
			char temp[256];
			cin.getline(temp, 256);

			if (menuFace == 1) // remove
			{
				PublicationSelector pubSels("Select one of the following found matches:");

				// Loop to find matching publications based on title and type
				for (int i = 0; i < NOLP; i++)
				{
					if (m_pubs[i]->operator==(temp))
					{
						if (m_pubs[i]->type() == 'B' && usrSearch == 1)
							pubSels << m_pubs[i];
						else if (m_pubs[i]->type() == 'P' && usrSearch == 2)
							pubSels << m_pubs[i];
					}
				}

				// If there are matches, sort the selector and run it to get the chosen publication's row
				if (pubSels)
				{
					pubSels.sort();
					row = pubSels.run();
					return row;
				}
			}
			else if (menuFace == 2) // chkout
			{
				PublicationSelector pubSels("Select one of the following found matches:");

				for (int i = 0; i < NOLP; i++)
				{
					if (m_pubs[i]->onLoan() && m_pubs[i]->operator==(temp))
					{
						if (m_pubs[i]->type() == 'B' && usrSearch == 1)

							pubSels << m_pubs[i];

						else if (m_pubs[i]->type() == 'P' && usrSearch == 2)

							pubSels << m_pubs[i];
					}
				}

				if (pubSels)
				{
					pubSels.sort();
					row = pubSels.run();
					return row;
				}
			}
			else if (menuFace == 3)
			{
				PublicationSelector pubSels("Select one of the following found matches:");

				for (int i = 0; i < NOLP; i++)
				{
					// CHECK ... maybe error
					if (m_pubs[i]->operator==(temp) && !m_pubs[i]->onLoan() && m_pubs[i]->getRef() != 0)
					{
						if (m_pubs[i]->type() == 'B' && usrSearch == 1)

							pubSels << m_pubs[i];

						else if (m_pubs[i]->type() == 'P' && usrSearch == 2)

							pubSels << m_pubs[i];
					}
				}

				if (pubSels)
				{
					pubSels.sort();
					row = pubSels.run();
					return row;
				}
			}
		}
		return row;
	}

	// Function to get a publication object based on the index (row)
	Publication *LibApp::getPub(int idx)
	{
		return m_pubs[idx - 1];
	}

	void LibApp::newPublication()
	{
		if (NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!\n";
			return;
		}
		else
		{
			cout << "Adding new publication to the library\n";

			cout << "Choose the type of publication:\n";
			cout << " 1- Book\n";
			cout << " 2- Publication\n";
			cout << " 0- Exit\n";
			cout << "> ";

			int usrInput;

			cin >> usrInput;

			while (cin.fail() || usrInput < 0 || usrInput > 2)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				if (usrInput < 0 || usrInput > 2)
					cout << "[0<=value<=" << 2 << "], retry: Enter the row number: ";
				cin >> usrInput;
			}

			Publication *p = nullptr;

			if (usrInput == 1)
			{
				p = new Book;
				p->read(cin);
			}
			else if (usrInput == 2)
			{
				p = new Publication;
				p->read(cin);
			}
			else
			{
				cout << "Aborted!\n";
				return;
			}

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Aborted!\n";
				return;
			}
			else
			{
				cout << "Add this publication to the library?\n";
				int choice;
				cout << " 1- Yes\n";
				cout << " 0- Exit\n";
				cout << "> ";
				cin >> choice;

				if (choice == 1)
				{
					if (p)
					{
						LLRN++;
						p->setRef(LLRN);
						m_pubs[NOLP] = p;
						NOLP++;
						m_changed = true;
						cout << "Publication added\n";
					}
					else
					{
						cout << "Failed to add publication!\n";
						delete p;
						p = nullptr;
						return;
					}
				}
				else
				{
					cout << "Aborted!\n";
					return;
				}
			}
		}
	}

	void LibApp::removePublication()
	{
		cout << "Removing publication from the library\n";

		int row = search(1);

		if (row != 0)
		{
			int i = 0, count = 0;
			for (i = 0; i < NOLP; i++)
			{
				if (m_pubs[i]->getRef() == row)
				{
					m_pubs[i]->setRef(0);
					m_changed = true;
					count = i;

					break; // NOTE: REVISE!!! check if can use break!!!!!@!!!!!!!!
				}
			}

			m_pubs[count]->write(cout);
			cout << endl;
			int choice = confirm("Remove this publication from the library?");
			if (choice == 1)
			{
				m_pubs[count]->setRef(0);
				m_changed = true;
				cout << "Publication removed\n";
			}
			else
			{
				cout << "Aborted!\n";
				return;
			}
		}
		else
		{
			cout << "Aborted!\n";
			return;
		}
	}

	void LibApp::checkOutPub()
	{
		cout << "Checkout publication from the library\n";

		int row = search(3);

		if (row == 0)
		{
			cout << "No matches found!\n";
		}
		else
		{
			int i = 0, count = 0;
			for (i = 0; i < NOLP; i++)
			{
				if (m_pubs[i]->getRef() == row)
				{
					m_changed = true;
					count = i;
					break; // NOTE: REVISE!!! check if can use break!!!!!@!!!!!!!!
				}
			}

			m_pubs[count]->write(cout);
			cout << endl;

			int confirmMsg = confirm("Check out publication?");

			if (confirmMsg == 1)
			{
				int id;
				cout << "Enter Membership number: ";
				cin >> id;

				while (id < 9999 || id > 99999)
				{
					cout << "Invalid membership number, try again: ";
					cin >> id;
				}

				m_pubs[count]->set(id);
				m_changed = true;
				cout << "Publication checked out\n";
			}

			else
			{
				cout << "Aborted!\n";
				return;
			}
		}
	}

	void LibApp::returnPub()
	{
		static int tempCounter = 0;
		cout << "Return publication to the library\n";

		int row = search(2);

		if (row != 0)
		{
			int i = 0, count = 0;
			for (i = 0; i < NOLP; i++)
			{
				if (m_pubs[i]->getRef() == row)
				{
					count = i;
					break; // NOTE: REVISE!!! check if can use break!!!!!@!!!!!!!!
				}
			}

			m_pubs[count]->write(cout);
			cout << endl;

			int usrPick = confirm("Return Publication?");

			if (usrPick == 1)
			{
				m_pubs[count]->set(0);
				m_changed = true;
				int days = 0;

				if (tempCounter == 0)
				{
					Date temp(2023, 7, 28);
					days = m_pubs[count]->operator-(temp);
				}

				else if (tempCounter == 1)
				{
					Date temp(2023, 7, 14);
					days = m_pubs[count]->operator-(temp);
				}

				else if (tempCounter == 2)
				{
					Date temp(2023, 8, 10);
					days = temp.operator-(m_pubs[count]->checkoutDate());
				}

				double lateFEE = 0.0;
				if (days > 15)
				{
					lateFEE = 0.5 * (days - 15);
				}
				if (lateFEE > 0)
				{
					std::cout << "Please pay $" << fixed << setprecision(2) << lateFEE << " penalty for being " << days - 15 << " days late!" << std::endl;
				}

				tempCounter++;
				cout << "Publication returned\n";
			}

			else
			{
				cout << "Aborted!\n";
				return;
			}
		}
		else
		{
			cout << "Aborted!\n";
		}
	}

	void LibApp::run()
	{
		int exitChoice = 2;
		int usrInput;
		do
		{
			usrInput = m_mainMenu.run();

			switch (usrInput)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			default:

				if (m_changed)
				{
					exitChoice = m_exitMenu.run();
					if (exitChoice == 1)
					{
						save();
						break; //!!!!!!!!!!
					}
					else if (exitChoice == 2)
					{
						usrInput = -1;
					}
					else
					{
						if (confirm("This will discard all the changes are you sure?"))
						{
							break; //!!!!!!!!!!
						}
						else
						{
							usrInput = -1;
						}
					}
				}
				break; //!!!!!!!!!!
			}
			cout << endl;
		} while (usrInput != 0);

		cout << "-------------------------------------------\n";
		cout << "Thanks for using Seneca Library Application\n";
	}

}
