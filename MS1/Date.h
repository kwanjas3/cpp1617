// Final Project Milestone 1
//
// Version 1.0
// Date 2017-07-04
// Author Jason Kwan
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
namespace sict{
	class Date {
	private:
		int year_;
		int mon_;
		int day_;
		int readErrorCode_;

	public:
		Date();
		Date(int year, int month, int day);
		void setEmpty();
		bool isValid();
		bool isEmpty();

		int value()const; // already defined
		int mdays(int mon)const; // already defined

		void errCode(int errorCode);
		int errCode()const;
		bool bad()const;

		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};






}
#endif