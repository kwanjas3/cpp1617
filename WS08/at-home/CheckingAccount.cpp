#include "CheckingAccount.h"

using namespace std;

namespace ict {

   // TODO: define CheckingAccount class member functions here  

   void CheckingAccount::chargeFee(double amt)
   {
      double newBalance = getBalance() - amt;
      setBalance(newBalance);
   }

   CheckingAccount::CheckingAccount(const double init, const double fee) : Account(init)
   {
      if (fee > 0) {
         transactionFee = fee;
      }
      else {
         transactionFee = 0;
      }
   }

   void CheckingAccount::credit(const double amt)
   {
      Account::credit(amt);
      chargeFee(transactionFee);
   }

   bool CheckingAccount::debit(const double amt)
   {
      bool check = false;
      if (Account::debit(amt)) {
         chargeFee(transactionFee);
         check = true;
      }
      return check;
   }

   ostream & CheckingAccount::display(ostream & os)
   {
      os.setf(ios::fixed);
      os.precision(2);
      os << "Account type: Checking" << endl;
      os << "Balance: $ " << getBalance() << endl;
      os << "Transaction Fee: " << transactionFee << endl;
      return os;
   }

}