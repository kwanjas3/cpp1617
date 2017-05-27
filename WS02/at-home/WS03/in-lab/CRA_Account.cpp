#include "CRA_Account.h"
#include <iostream>

using namespace std;
namespace sict {

   void CRA_Account::set(const char * familyName_, const char * givenName_, int sin_)
   {
      strcpy(familyName, familyName_);
      strcpy(givenName, givenName_);
      sin = sin_;


   }

   bool CRA_Account::isValid() const
   {
      bool valid = false;
      if (sin >= MIN_SIN && sin <= MAX_SIN) {
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
      cout << "CRA Account: "; sin;
   }
}
