#include "Account.h"

using namespace std;

namespace ict {

   double Account::getBalance() const
   {
      return balance;
   }

   void Account::setBalance(double newBalance)
   {
      balance = newBalance;
   }
   void Account::setEmpty()
   {
      balance = 1;
   }
   Account::Account()
   {
      setEmpty();
   }
   Account::Account(const double x)
   {
      if (isValid(x)) {
         balance = x;
      }
   }
   void Account::credit(const double amt)
   {
      balance += amt;
   }
   bool Account::debit(const double amt)
   {

      bool check = false;
      if (amt > 0 && amt < balance) {
         balance -= amt;
         check = true;
      }
      return check;

   }
   bool Account::isValid(double x)
   {
      return (x >= 0);
   }
}