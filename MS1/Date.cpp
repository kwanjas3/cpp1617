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
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "general.h"


using namespace std;
namespace sict {

   Date::Date()
   {
      setEmpty();
   }

   Date::Date(int year, int month, int day)
   {
      year_ = year;
      mon_ = month;
      day_ = day;
      readErrorCode_ = NO_ERROR;
   }

   void Date::setEmpty()
   {
      year_ = 0;
      mon_ = 0;
      day_ = 0;
      readErrorCode_ = NO_ERROR;
   }

   void Date::setYear(int y)
   {
      year_ = y;
      if (y < MIN_YEAR || y > MAX_YEAR) {
         errCode(YEAR_ERROR);
      }
   }

   void Date::setMonth(int m)
   {
      mon_ = m;
      if (m < 1 || m > 12) {
         errCode(MON_ERROR);
      }
   }

   void Date::setDay(int d)
   {
      day_ = d;
      if (d < 1 || d > mdays(mon_)) {
         errCode(DAY_ERROR);
      }
   }


   bool Date::isEmpty()
   {
      return (year_ == 0 && mon_ == 0 &&
         day_ == 0 && readErrorCode_ == NO_ERROR);
   }

   int Date::value() const
   {
      return year_ * 372 + mon_ * 31 + day_;
   }

   int Date::mdays(int mon) const
   {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      //int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      int month = mon;
      month--;
      return days[month] + int((month == 1) * ((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }

   void Date::errCode(int errorCode)
   {
      readErrorCode_ = errorCode;
   }

   int Date::errCode() const
   {
      return readErrorCode_;
   }

   bool Date::bad() const
   {
      return (readErrorCode_ != 0);
   }

   bool Date::operator==(const Date & D) const
   {
      return (value() == D.value());
   }

   bool Date::operator!=(const Date & D) const
   {
      return (value() != D.value());
   }

   bool Date::operator<(const Date & D) const
   {
      return (value() < D.value());
   }

   bool Date::operator>(const Date & D) const
   {
      return (value() > D.value());
   }

   bool Date::operator<=(const Date & D) const
   {
      return (value() <= D.value());
   }

   bool Date::operator>=(const Date & D) const
   {
      return (value() >= D.value());
   }

   std::istream & Date::read(std::istream & istr)
   {
      char buffer;
      int y, m, d;
      errCode(NO_ERROR);

      istr >> y >> buffer >> m >> buffer >> d;
      
      if (istr.fail()) {
         errCode(CIN_FAILED);
      }
      else 
      {
         if (errCode() == NO_ERROR) {
            setYear(y);
            setMonth(m);
            setDay(d);
         }
      }
      return istr;
   }

   std::ostream & Date::write(std::ostream & ostr) const
   {
      ostr << year_ << "/" 
         << right << setw(2) << setfill('0') 
         << mon_ << "/" << setw(2) << right << setfill('0') 
         << day_ << setw(0) << setfill(' ');

      return ostr;
   }

   std::ostream & operator<<(std::ostream & ostr, Date src)
   {
      return src.write(ostr);
   }

   std::istream & operator>>(std::istream & istr, Date src)
   {
      return (src.read(istr));
   }

}
