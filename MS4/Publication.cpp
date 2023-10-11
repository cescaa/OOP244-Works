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
	Publication::Publication()
	{
		m_title = nullptr;
		m_memberhsip = 0;
		m_libRef = -1;
		m_shelfId[0] = '\0';
	}

	Publication::~Publication()
	{
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}

	}
	Publication::Publication(const Publication& rhs)
	{
		if (rhs.m_title == nullptr)
		{
			m_title = nullptr;
		}
		else
		{
			m_title = new char[strlen(rhs.m_title) + 1];
			strcpy(m_title, rhs.m_title);
		}
		m_memberhsip = rhs.m_memberhsip;
		m_libRef = rhs.m_libRef;
		m_date = rhs.m_date;
		strcpy(m_shelfId, rhs.m_shelfId);
	}
	Publication& Publication::operator=(const Publication& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		if (m_title)
		{
			delete[] m_title;
		}

		if (rhs.m_title != nullptr)
		{
			m_title = new char[strlen(rhs.m_title) + 1];
			strcpy(m_title, rhs.m_title);
		}
		else {
			m_title = nullptr;
		}
		m_memberhsip = rhs.m_memberhsip;
		m_libRef = rhs.m_libRef;
		m_date = rhs.m_date;
		strcpy(m_shelfId, rhs.m_shelfId);
		return *this;
	}


	//ok
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
		if (value != 0)
		{
			m_libRef = value;
		}
		else
		{
			m_libRef = -1;
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
		return (m_memberhsip != 0);
	}
	// Returns true is the publication is checkout (membership is non-zero)

	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	// Returns the date attribute

	bool Publication::operator==(const char *title) const
	{
		return strstr(m_title, title)!=nullptr;
	}
	/* Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)*/

	Publication::operator const char *() const
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
	ostream &Publication::write(ostream &os) const
	{
		
		if (conIO(os)) {
			if (m_title) {
				
				char title[SDDS_TITLE_WIDTH + 1] = { 0 };
				strncpy(title, m_title, SDDS_TITLE_WIDTH);
				os << "| " << m_shelfId << " | "
					<< std::setw(SDDS_TITLE_WIDTH) << std::left << std::setfill('.')
					<< title << " | ";
				(m_memberhsip == 0) ? os << " N/A " : os << m_memberhsip;
				os << " | "
					<< m_date
					<< " |";
			}
		}
		else
		{
			os << type()
			<< "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			(m_memberhsip == 0) ? os << " N/A " : os << m_memberhsip;
			os << "\t" << m_date;
		}
		return os;
	}
	istream &Publication::read(istream &istr)
	{
		m_date = Date();
		m_shelfId[0] = '\0';
		m_memberhsip = 0;
		m_libRef = -1;
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		char title[256];
		char shelfId[6];
		int memberCode;
		int libRef;
		Date dateTemp;

		if (conIO(istr) == true)
		{
			cout << "Shelf No: ";
			istr >> shelfId;
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN)
			{
				istr.setstate(std::ios::failbit);
			}
			istr.ignore();
			cout << "Title: ";
			istr.getline(title, 256);
			cout << "Date: ";
			dateTemp.read(istr);
			if (strcmp(dateTemp.dateStatus(), "No Error") != 0)
			{
				istr.setstate(std::ios::failbit);
			}
			if (!istr.fail())
			{
				m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
			
				strcpy(m_shelfId, shelfId);
				m_date = dateTemp;
			}	
		}
		else
		{
			istr >> libRef;
			istr.ignore();
			istr >> shelfId;
			istr.ignore();
			istr.getline(title, 256, '\t');
			istr >> memberCode;
			istr.ignore();
			dateTemp.read(istr);
			if (strcmp(dateTemp.dateStatus(), "No Error") != 0)
			{
				istr.setstate(std::ios::failbit);
			}
			if (!istr.fail())
			{
				m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
				strcpy(m_shelfId, shelfId);
				m_memberhsip = memberCode;
				m_libRef = libRef;
				m_date = dateTemp;
			}
		}
		return istr;
	}

	// Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
	bool Publication::conIO(ios &io) const
	{
		// geet cin and cout addresses
		ios *cinAddr = &cin;
		ios *coutAddr = &cout;

		// get  address of io
		ios *ioAddr = &io;

		return (ioAddr == cinAddr || ioAddr == coutAddr);
	}

	Publication::operator bool()
	{
		return ( m_title[0] != '\0' &&m_title != nullptr && m_shelfId[0] != '\0');
	}

	/*Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}*/

}

// g++ -Wall -std=c++11 -g -o ws ms3_tester.cpp Streamable.cpp Publication.cpp