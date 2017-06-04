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
   Passenger::Passenger(const char * name, const char * destination, const int year, const int month, const int day)
   {
      if (!isEmpty()) {
         if (name == nullptr || destination == nullptr ||
            strlen(name) == 0 || strlen(destination) == 0 ||
            (year < 2017 || year > 2020) ||
            (month < 1 || month > 12) ||
            (day < 1 || day > 31)
            )
         {
            setEmpty();
         }
         else {
            strcpy(pname, name);
            strcpy(des, destination);
            yeard = year;
            monthd = month;
            dayd = day;
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
      cout << pname << " - " << des << " on " << yeard << "/" << monthd << "/" << dayd << endl;
   }




   void Passenger::setEmpty()
   {
      pname[0] = 0;
      des[0] = 0;
      yeard = 0;
      monthd = 0;
      dayd = 0;
   }

   const char * Passenger::name() const
   {
      return pname;
   }

   bool Passenger::canTravelWith(const Passenger &ref)
   {
      bool check = false;
      if (strcmp(ref.des, des) == 0) {
         check = true;
      }
      return check;
   }


}



