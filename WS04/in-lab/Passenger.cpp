// TODO: add your headers here 
#include <iostream>
#include "Passenger.h"
#include <cstring>

using namespace std;
// TODO: continue your namespace here
namespace sict {
   Passenger::Passenger()
   {
      setEmpty();
   }

   Passenger::Passenger(char * name, char * destination)
   {
      if (name == nullptr || destination == nullptr || name == "" || destination == "") {
         setEmpty();
      }
      else {
         strcpy(pname, name);
         strcpy(des, destination);
      }
   }
   bool Passenger::isEmpty() const
   {
      bool check = false;
      if (pname[0] == 0 && des[0] == 0) {
         check = true;
      }
      return check;
   }

   void Passenger::display() const
   {
      cout << pname << " - " << des << endl;
   }


   void Passenger::setEmpty()
   {
      pname[0] = 0;
      des[0] = 0;
   }


}



