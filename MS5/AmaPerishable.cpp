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
      file >> temp;
      expiry(temp);
      file.ignore();

      return file;
   }
   ostream & AmaPerishable::write(ostream & os, bool linear) const
   {
      AmaProduct::write(os, linear);
      if (linear) {
         os << expiry();
      }
      else {
         os << "Expiry Date: " << expiry();
      }

         return os;
      
   }
   istream & AmaPerishable::read(istream & is)
   {
      double td;
      int ti;
      char yn;
      char s[MAX_SKU_LEN];
      char un[DISPLAY_LINES + 1]; // 10 + 1
      char n[MAX_NAME_SIZE];
      Date temp;

      AmaProduct::read(is);
      if (!is.fail()) { 
         /////////////////
            cout << "Expiry Date (YYYY/MM/DD) : ";
            is >> temp;

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
            }
            else {
               expiry(temp);
            }

         }
         return is;
      }
   }