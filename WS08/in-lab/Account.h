#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict {

   class Account {
   private:
      double balance; // data member that stores the balance

   protected:
      double getBalance() const; // return the account balance
      void setBalance(double); // sets the account balance
      void setEmpty();

   public:
      // TODO: Write a prototype for constructor which initializes balance
      Account();
      Account(const double);
      // TODDO: Write a function prototype for the virtual function credit 
      virtual void credit(const double amt);
      // TODO: Write a function prototype for the virtual function debit
      virtual bool debit(const double amt);
      // TODO: Write a function prototype for the virtual function display		
      virtual ostream& display(ostream& os) = 0;
      bool isValid(const double x);
   };
};
#endif
