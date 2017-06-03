// TODO: add your headers here 
#include <iostream>
#include "Passenger.h"
#include <cstring>

using namespace std;
// TODO: continue your namespace here
namespace sict {
   Passenger::Passenger()
   {
      if (!isEmpty()) {
         setEmpty();
      }
   }

   Passenger::Passenger(const char * name, const char * destination)
   {
      if (!isEmpty()) {

         if (name == nullptr || destination == nullptr || strlen(name) == 0 || strlen(destination) == 0) {
            setEmpty();
         }
         else {
            strcpy(pname, name);
            strcpy(des, destination);
         }
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



