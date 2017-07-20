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
      if (!err_.isClear()) {
         os << err_.message();
      }
      else {
         if (linear) {
            os << setfill(' ') << left << setw(MAX_SKU_LEN)
               << sku() << '|' <<
               setw(20) << name() << '|' << right << setw(7) << fixed << showpoint <<
               setprecision(2) << cost() << '|' <<
               setw(4) << quantity() << '|' << setw(10) <<
               left << unit() << '|' << right <<
               setw(4) << qtyNeeded() << '|' << expiry();
         }

         else {
            if (taxed()) {
               os << "Sku:: " << sku() << endl
                  << "Name:  " << name() << endl
                  << "Price:  " << price() << endl
                  << "Price after tax:  " << cost() << endl
                  << "Quantity On Hand:  " << quantity() << ' ' << unit() << endl
                  << "Quantity Needed:  " << qtyNeeded() << endl
                  << "Expiry date:  " << expiry() << endl;
            }
            else {
               os << "Sku: " << sku() << endl
                  << "Name: " << name() << endl
                  << "Price: " << price() << endl
                  << "Price after tax: " << "N/A" << endl
                  << "Quantity On Hand: " << quantity() << ' ' << unit() << endl
                  << "Quantity Needed: " << qtyNeeded() << endl
                  << "Expiry date: " << expiry() << endl;
            }
         }
         return os;
      }
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