// AmaPersishable.cpp
#include <iostream>
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
      file << 'P' << ','
         << sku() << ','
         << name() << ','
         << price() << ','
         << taxed() << ','
         << unit() << ','
         << qtyNeeded() << ','
         << expiry() << endl;

      return file;
   }
   fstream & AmaPerishable::load(fstream & file)
   {
      double td;
      int ti;
      char s[MAX_SKU_LEN];
      char n[MAX_NAME_SIZE];
      char c; // eat buffer
      Date temp;

      file.getline(s, MAX_SKU_LEN, ','); // SKU
      sku(s);

      file.getline(n, MAX_NAME_SIZE, ',');// NAME
      name(n);

      file >> td >> c; // PRICE
      price(td);

      file >> ti >> c; // TAXED
      taxed(1);

      file.getline(n, 10 + 1, ','); //UNIT unit size is 10 + 1 for nullchar
      unit(n);

      file >> ti; // qtyNeeded
      qtyNeeded(ti);
      file.ignore;

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
            os << os.setf(ios::left) << os.width(MAX_SKU_LEN) << sku() << '|'
               << os.width(20) << name() << '|'
               << os.setf(ios::right) << os.width(9) << os.precision(2) << cost() << '|'
               << os.width(4) << os.precision(0) << quantity() << '|'
               << os.setf(ios::left) << os.width(10) << unit() << '|'
               << os.setf(ios::right) << os.width(4) << qtyNeeded() << '|';
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
               os << "Sku:: " << sku() << endl
                  << "Name:  " << name() << endl
                  << "Price:  " << price() << endl
                  << "Price after tax:  " << "N/A" << endl
                  << "Quantity On Hand:  " << quantity() << ' ' << unit() << endl
                  << "Quantity Needed:  " << qtyNeeded() << endl
                  << "Expiry date:  " << expiry() << endl;
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

      if (!is.fail()) {
         err_.clear();

         cout << "Sku:  ";
         is >> s;
         if (!is.fail())
            sku(s);
         ///////////////
         cout << "Name:  ";
         is >> n;
         if (!is.fail())
            name(n);
         ///////////////
         cout << "Unit:  ";
         is >> un;
         if (!is.fail())
            unit(un);
         ///////////////
         cout << "Taxed? (y/n):  ";
         is >> yn;
         is.clear();
         while (yn != 'y' || yn != 'Y' || yn != 'n' || yn != 'N') {
            err_.message("Only (Y)es or (N)o are acceptable");
            is >> yn;
         }
         ///////////////

         cout << "Price:  ";
         is >> td;
         if (is.fail()) {
            err_.message("Invalid Price Entry");
            is.setstate(ios::failbit);
         }
         else {
            price(td);
         }
         ////////////////
         cout << "Quantity On hand:  ";
         is >> ti;
         is.clear();
         if (is.fail()) {
            err_.message("Invalid Quantity Entry");
            is.setstate(ios::failbit);
         }
         else {
            quantity(ti);
         }
         ////////////////
         cout << "Quantity needed:  ";
         is >> ti;
         is.clear();
         if (is.fail()) {
            err_.message("Invalid Quantity Needed Entry");
            is.setstate(ios::failbit);
         }
         else {
            qtyNeeded(ti);
         }

         cout << "Expiry Date (YYYY/MM/DD)  :  ";
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