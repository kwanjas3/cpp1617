#include "CRA_Account.h"
#include <iostream>
#include <string>


using namespace std;
namespace sict {

   void CRA_Account::set(const char * familyName_, const char * givenName_, int sin_)
   {
      sin = sin_;
      if (!isValid()) {
         familyName[0] = 0;
         givenName[0] = 0;
         sin = 0;
      }
      else {
      strcpy(familyName, familyName_);
      strcpy(givenName, givenName_);
      }
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
      bool valid = true;
      int evensum = 0;
      int oddsum = 0;

      //first digit is farthlest left workin progress
      int dig1 = sin / 100000000;
      int dig2 = (sin % 100000000) / 10000000;
      int dig3 = (sin % 10000000) / 1000000;
      int dig4 = (sin % 1000000) / 100000;
      int dig5 = (sin % 100000) / 10000;
      int dig6 = (sin % 10000) / 1000;
      int dig7 = (sin % 1000) / 100 ;
      int dig8 = (sin % 100) / 10 ;
      int dig9 = (sin % 10);



      if (sin < MIN_SIN || sin > MAX_SIN)
      {
         valid = false;
      }
      else {
         if (dig2 * 2 > 9) {
            evensum += (dig2*2%10 + 1);
         }
         else {
            evensum += (dig2 * 2);
         }
         if (dig4 * 2 > 9) {
            evensum += (dig4 * 2 % 10 + 1);
         }
         else {
            evensum += (dig4 * 2);
         }
         if (dig6 * 2 > 9) {
            evensum += (dig6 * 2 % 10 + 1);
         }
         else {
            evensum += (dig6 * 2);
         }
         if (dig8 * 2 > 9) {
            evensum += (dig8 * 2 % 10 + 1);
         }
         else {
            evensum += (dig8 * 2);
         }
         oddsum = dig1 + dig3 + dig5 + dig7;
         sum = evensum + oddsum;
         
         
         if (((sum / 10 + 1) * 10) - sum != dig9) {
            valid = false;
         }
         else {
            valid = true;
         }
      }
     



      return valid;
   }

   void CRA_Account::display() const
   {
      int i = 0;
      cout.setf(ios::fixed);
      cout.width(10);
      cout.precision(2);
      cout << "Family name: "; cout << familyName;
      cout << endl;
      cout << "Given Name : "; cout << givenName;
      cout << endl;
      cout << "CRA Account: "; cout << sin;
      cout << endl;

      for (; i < MAX_YRS; i++)

      if (m_balance[i] > 2) {
         cout << "Year (" << m_year[i] << ") " << "balance owing: " << m_balance[i] << endl;
      }
      else if (m_balance[i] < -2) {
         cout << "Year (" << m_year[i] << ") " << "refund due: " << m_balance[i] * -1 << endl;
      }

      else {
         cout << "Year (" << m_year[i] << ") " << "No balanace owing or refund due!" << endl;
      }
   }
}
