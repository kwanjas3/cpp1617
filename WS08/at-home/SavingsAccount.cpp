#include "SavingsAccount.h"

using namespace std;

namespace sict{
   SavingsAccount::SavingsAccount(const double init, const double interest): Account(init)
   {
      if (interest > 0) {
      interestRate = interest;
      }
      else {
         interestRate = 0;
      }
   }
   double SavingsAccount::calculateInterest()
   {
      return (getBalance() * interestRate);
   }
   ostream & SavingsAccount::display(ostream & os)
   {
      os.setf(ios::fixed);
      os.precision(2);
      os << "Account type: Saving" << endl;
      os << "Balance: $ " << getBalance() << endl;
      os << "Interest Rate (%): " << interestRate * 100 << endl;
      return os;
   }
   // TODO: Implement SavingsAccount member functions here
}