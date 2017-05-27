#include "CRA_Account.h"
#include <iostream>
#include <string>

using namespace std;
namespace sict {

   void CRA_Account::set(const char * familyName_, const char * givenName_, int sin_)
   {
      strcpy(familyName, familyName_);
      strcpy(givenName, givenName_);
      sin = sin_;
   }

   void CRA_Account::set(int year, double balance)
   {
      m_year[m_years] = year;
      m_balance[m_years] = balance;
      m_years++;
   }

   bool CRA_Account::isValid() const
   {
      int sum = 0;
      bool valid = false;
      int sum;
      int oddsum;
      //first digit is farthlest left workin progress
      int dig1 = (sin - (sin % 100000000)) / 100000000;
      int dig2 = ((sin - (sin % 10000000)) / 10000000) % 10;
      int dig3 = ((sin - (sin % 1000000)) / 1000000) % 10;
      int dig4 = ((sin - (sin % 100000)) / 100000) % 10;
      int dig5 = ((sin - (sin % 10000)) / 10000) % 10;
      int dig6 = ((sin - (sin % 1000)) / 1000) % 10;
      int dig7 = ((sin - (sin % 100)) / 100) % 10;
      int dig8 = ((sin - (sin % 10)) / 10) % 10;
      int dig9 = (sin - (sin % 10));
      
      


      
         if (sin >= MIN_SIN && sin <= MAX_SIN)
         {
            valid = true;
         }
      return valid;
   }

   void CRA_Account::display() const
   {
      cout << "Family name: "; cout << familyName;
      cout << endl;
      cout << "Given Name : "; cout << givenName;
      cout << endl;
      cout << "CRA Account: "; cout << sin;
      cout << endl;
      cout << "Year (" << m_year << ") ";
   }
}
