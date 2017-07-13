#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace sict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance
         void chargeFee(double);
		
		public:

			// TODO: constructor initializes balance and transaction fee 
         CheckingAccount(const double init, const double fee);
			// TODO: Write a function prototype to override credit function
         void credit(const double amt);
			// TODO: Write a function prototype to override debit function
         bool debit(const double amt);
			// TODO: Write a function prototype to  override display function
         ostream& display(ostream&);
	};
};
#endif
