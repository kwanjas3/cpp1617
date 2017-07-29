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
   void Date::setEmpty()
   {
      year_ = 0;
      mon_ = 0;
      day_ = 0;
      readErrorCode_ = NO_ERROR;
   }

   Date::Date(int year, int month, int day)
   {
      year_ = year;
      mon_ = month;
      day_ = day;
      isValid();
   }


   void Date::isValid()
   {
      if (year_ < MIN_YEAR || year_ > MAX_YEAR) {
         readErrorCode_ = YEAR_ERROR;
      }
      else if (mon_ < 1 || mon_ > 12) {
         readErrorCode_ = MON_ERROR;
      }
      else if (day_ < 1 || day_ > mdays()) {
         readErrorCode_ = DAY_ERROR;
      }
      else {
         readErrorCode_ = NO_ERROR;
      }


   }



   bool Date::isEmpty()
   {
      return (year_ == 0 && mon_ == 0 &&
         day_ == 0 && readErrorCode_ == NO_ERROR);
   }

   int Date::value()const {
      return year_ * 372 + mon_ * 31 + day_;
   }

   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
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

      int y, m, d;
      istr >> y;
      istr.get();
      istr >> m;
      istr.get();
      istr >> d;

      if (istr.fail()) {
         errCode(CIN_FAILED);
      }
      else
      {
         year_ = y;
         mon_ = m;
         day_ = d;
         isValid();
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

   std::ostream & operator<<(std::ostream & ostr, const Date& src)
   {
      return src.write(ostr);
   }

   std::istream & operator >> (std::istream & istr, Date& src)
   {
      return src.read(istr);
   }

}
