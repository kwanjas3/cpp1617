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
      return 0;
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
      istr >> year_ >> mon_ >> day_;
      if (istr.fail()) {
         readErrorCode_ = CIN_FAILED;
      }
      else {
         if (year_ > MAX_YEAR || year_ < MIN_YEAR) {
            readErrorCode_ = YEAR_ERROR;

         }
         if (mon_ > 12 || mon_ < 1) {
            readErrorCode_ = MON_ERROR;

         }
         if (day_ < 1 || day_ > mdays(mon_)) {
            readErrorCode_ = DAY_ERROR;
         }
      }
      return istr;
   }

   std::ostream & Date::write(std::ostream & ostr) const
   {
      ostr << year_ << '/' << mon_ << '/' << day_;
      return ostr;
   }

   std::ostream & operator<<(std::ostream & ostr, Date x)
   {
      return x.write(ostr);
   }

   std::istream & operator>>(std::istream & istr, Date x)
   {
      return x.read(istr);
   }

}
