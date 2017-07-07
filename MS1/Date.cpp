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
<<<<<<< HEAD
      day_ = d;
      if (d < 1 || d > mdays()) {
         errCode(DAY_ERROR);
      }
=======
      return true;
>>>>>>> a528cac52f287080a7f1449dacf872f38755ccb0
   }

   bool Date::isEmpty()
   {
      return (year_ == 0 && mon_ == 0 &&
         day_ == 0 && readErrorCode_ == NO_ERROR);
   }

<<<<<<< HEAD
   int Date::value()const {
      return year_ * 372 + mon_ * 31 + day_;
   }

   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
=======
   int Date::value() const
   {
      return 0;
   }

   int Date::mdays(int mon) const
   {
      return 31;
>>>>>>> a528cac52f287080a7f1449dacf872f38755ccb0
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
<<<<<<< HEAD
      char buffer;
      int y, m, d;

      istr >> y >> buffer >> m >> buffer >> d;
      
=======
      istr >> year_ >> mon_ >> day_;
>>>>>>> a528cac52f287080a7f1449dacf872f38755ccb0
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
<<<<<<< HEAD
      return src.read(istr);
=======
      return x.read(istr);
>>>>>>> a528cac52f287080a7f1449dacf872f38755ccb0
   }

}
