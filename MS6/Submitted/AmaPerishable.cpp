// AmaPersishable.cpp
#include <iomanip>
#include <cstring>
#include <fstream>
#include "AmaPerishable.h"
using namespace std;

namespace sict {
   AmaPerishable::AmaPerishable() : AmaProduct('P')
   {

   }
   const Date& AmaPerishable::expiry()const
   {
      return expiry_;
   }

   void AmaPerishable::expiry(const Date & value)
   {
      expiry_ = value;
   }
   fstream & AmaPerishable::store(fstream & file, bool addNewLine) const
   {
      AmaProduct::store(file, false);
       file << expiry() << endl;

      return file;
   }
   fstream & AmaPerishable::load(fstream & file)
   {
      Date temp;
      AmaProduct::load(file);
      (file >> temp).ignore();
      expiry(temp);

      return file;
   }
   ostream & AmaPerishable::write(ostream & os, bool linear) const
   {
      AmaProduct::write(os, linear);
      if (linear) {
         os << expiry();
      }
      else {
         os << "Expiry date: " << expiry();
      }
         return os;
      
   }
   istream & AmaPerishable::read(istream & is)
   {
      Date temp;
      AmaProduct::read(is);
      if (!is.fail()) { 
         /////////////////
            cin.ignore();
            cout << "Expiry date (YYYY/MM/DD): ";
            is >> temp;
            cin.ignore();
            if (temp.bad()) {
               if (temp.errCode() == CIN_FAILED) {
                  err_.message("Invalid Date Entry");
               }
               if (temp.errCode() == YEAR_ERROR) {
                  err_.message("Invalid Year in Date Entry");
               }
               if (temp.errCode() == MON_ERROR) {
                  err_.message("Invalid Month in Date Entry");
               }
               if (temp.errCode() == DAY_ERROR) {
                  err_.message("Invalid Day in Date Entry");
               }
               is.setstate(ios::failbit);
               return is;
            }
            else {
               expiry(temp);
            }

         }
         return is;
      }
   }
