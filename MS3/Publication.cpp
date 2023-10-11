#include <iostream>
#include <string>
#include <fstream>
#include "Publication.h"
#include "Streamable.h"
#include <string.h>
#include <iomanip>
#include <limits>
using namespace std;

namespace sdds
{

	Publication::Publication() : m_date() // publish date or borrowed date if book
	{
		// To ease the implementation, let's assume this dynamic array can not be more than 255 characters long.
		m_title[0] = '\0';
		m_title[SDDS_TITLE_WIDTH] = '\0';
		m_shelfId[0] = '\0'; // location of pub
		m_memberhsip = 0;    // member's num
		m_libRef = -1;       // internal pub ID
	}

	void Publication::set(int member_id)
	{
		if (member_id > 9999)
		{
			m_memberhsip = member_id;
		}
		else
		{
			m_memberhsip = 0;
		}
	}
	// Sets the membership attribute to either zero or a five-digit integer.

	void Publication::setRef(int value)
	{
		if (value)
		{
			m_libRef = value;
		}
	}
	// Sets the **libRef** attribute value

	void Publication::resetDate()
	{
		Date currentDate;
		m_date = currentDate; // copy assignment!!!!!!!
	}
	// Sets the date to the current date of the system.

	char Publication::type() const
	{
		return 'P';
	}
	// Returns the character 'P' to identify this object as a "Publication object"

	bool Publication::onLoan() const
	{
		return (m_memberhsip > 0);
	}
	// Returns true is the publication is checkout (membership is non-zero)

	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	// Returns the date attribute

	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title);
	}
	/* Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)*/

	Publication::operator const char* () const
	{
		return m_title;
	}
	// Returns the title attribute

	int Publication::getRef() const
	{
		return m_libRef;
	}
	// Returns the libRef attirbute.

	///// OVERIDEEEEEEEEEEE ///
	ostream& Publication::write(ostream& os) const
	{
		if (conIO(os))
		{
			if (m_shelfId[0] != '\0')
			{
				string memberCode = (m_memberhsip == 0) ? " N/A " : to_string(m_memberhsip);

				os << "| " << m_shelfId;
				os << " | " << std::left << std::setw(30) << std::setfill('.') << m_title;
				os << " | " << memberCode;
				os << " | " << m_date << " |";
			}
		}
		else
		{
			os << type() << "\t"
				<< m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_memberhsip << "\t" << m_date;
		}
		return os;
	}
	istream& Publication::read(istream& istr)
	{
		// clear all the attributes
		m_shelfId[0] = '\0';
		m_memberhsip = 0;
		m_libRef = -1;
		m_title[0] = '\0';
		m_date = Date(); // reset date obj

		if (istr.eof())
		{
			return istr;
		}

		// if the istr argument is a console IO object (use conIO())
		if (conIO(istr) == true)
		{
			// prompt: "Shelf No: "
			cout << "Shelf No: ";
			// read the shelf number up to its limit (see Lib.h).
			istr >> m_shelfId;

			// if the number is not exactly the length it is supposed to be, set the istr to a fail state manually.
			if (strlen(m_shelfId) != SDDS_SHELF_ID_LEN)
			{
				m_shelfId[0] = '\0';
				// Set the istr to a fail state manually
				istr.setstate(std::ios::failbit);
			}
			else
			{
				istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			// prompt: "Title: "
			cout << "Title: ";
			// read the title
			istr.getline(m_title, SDDS_TITLE_WIDTH);
			// istr >> m_title;

			// prompt: "Date: "
			cout << "Date: ";

			// read the date
			m_date.read(istr);
			if (strcmp(m_date.dateStatus(), "No Error") != 0) {
				m_shelfId[0] = '\0';
			}
		}
		else
		{
			// assume reading begins with libRef attribute as if the type 'P' is not in the file.
			// read the libRef number
			istr >> m_libRef;
			// skip the tab
			istr.ignore(1, '\t');
			// read the shelf number
			string tt;
			istr >> tt;
			for (int i = 0; i < 4; i++)
			{
				m_shelfId[i] = tt[i];
			}
			m_shelfId[4] = '\0';
			// skip the tab
			istr.ignore(1, '\t');
			// read the title
			string mt;
			std::getline(istr, mt, '\t');
			for (size_t i = 0; i < mt.length(); i++)
			{
				m_title[i] = mt[i];
			}
			m_title[mt.length()] = '\0';
			// skip the tab
			istr.ignore(0, '\t');

			// read the membership
			istr >> m_memberhsip;
			// skip the tab
			istr.ignore(1, '\t');

			// read the date
			m_date.read(istr);
		}
		// if the date is in an invalid state set the istr to a fail state manually
		if (m_date.errCode() != 0)
		{
			istr.setstate(std::ios::failbit);
		}
		return istr;
	}

	// Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
	bool Publication::conIO(ios& io) const
	{
		// geet cin and cout addresses
		ios* cinAddr = &cin;
		ios* coutAddr = &cout;

		// get  address of io
		ios* ioAddr = &io;

		return (ioAddr == cinAddr || ioAddr == coutAddr);
	}

	Publication::operator bool()
	{
		return (m_title != nullptr && m_shelfId[0] != '\0');
	}

	/*Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}*/

}

// g++ -Wall -std=c++11 -g -o ws ms3_tester.cpp Streamable.cpp Publication.cpp