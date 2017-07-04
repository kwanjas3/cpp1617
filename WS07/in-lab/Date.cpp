// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include "general.h"
#include <iostream>

using namespace std;
namespace sict{
	Date::Date()
	{
		setEmpty();
	}

	Date::Date(int year, int month, int day)
	{
		if (!isEmpty()) {
			if (isValid()) {
				year_ = year;
				mon_ = month;
				day_ = day;
				readErrorCode_ = NO_ERROR;
			}
			else {
				setEmpty();
			}

		}
		else {
			setEmpty();
		}

	}

	void Date::setEmpty()
	{
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}

	bool Date::isValid()
	{
		return true;
	}

	bool Date::isEmpty()
	{
		return (year_ == 0 && mon_ == 0 &&
			day_ == 0 && readErrorCode_ == NO_ERROR);
	}

	int Date::value() const
	{
		return 256;
	}

	int Date::mdays(int mon) const
	{
		return 31;
	}

	void Date::errCode(int errorCode)
	{
		readErrorCode_ = errorCode;
	}

	int Date::errCode() const
	{
		return (readErrorCode_ != 0);
	}

	bool Date::bad() const
	{
		return false;
	}

	bool Date::operator==(const Date & D) const
	{
		return (year_ == D.year_ &&
			mon_ == D.mon_ &&
			day_ == D.day_);
	}

	bool Date::operator!=(const Date & D) const
	{
		return (year_ != D.year_ &&
			mon_ != D.mon_ &&
			day_ != D.day_);
	}

	bool Date::operator<(const Date & D) const
	{
		return false; //waiting value function
	}

	bool Date::operator>(const Date & D) const
	{
		return false; //waiting value function
	}

	bool Date::operator<=(const Date & D) const
	{
		return false; //waiting value function
	}

	bool Date::operator>=(const Date & D) const
	{
		return false; //waiting value function
	}

	std::istream & Date::read(std::istream & istr)
	{
		int ty;
		int tm;
		int td;
		istr >> ty;
		istr >> tm;
		istr >> td;
		if (ty > MAX_YEAR || ty < MIN_YEAR) {
			errCode(YEAR_ERROR);
		}
		if (tm < 1 || tm > 12)
		{
			errCode(MON_ERROR);
		}
		if (td < 1 || td > mdays(tm))
		{
			errCode(DAY_ERROR);
		}
		else {
			year_ = ty;
			mon_ = tm;
			day_ = td;
			errCode(NO_ERROR);
		}
		return istr;
	}

	std::ostream & Date::write(std::ostream & ostr) const
	{
		ostr << year_ << '/' << mon_ << '/' << day_ << '\n';
		return ostr;
	}

}
