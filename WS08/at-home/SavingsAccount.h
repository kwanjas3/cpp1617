#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {
   class SavingsAccount : public Account {
   private:
      double interestRate; // interest rate (percentage) 
   public:
      SavingsAccount(const double init, const double interest);
      double calculateInterest();
         // TODO: put prototypes here
      ostream& display(ostream&);
   };
};
#endif
