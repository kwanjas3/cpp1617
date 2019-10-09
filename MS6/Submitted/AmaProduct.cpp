#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
#include "AmaProduct.h"
// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sict {
   AmaProduct::AmaProduct(const char ft)
   {
      fileTag_ = ft;
   }

   const char * AmaProduct::unit() const
   {
      return unit_;
   }

   void AmaProduct::unit(const char * value)
   {
      if (strlen(value) < 11) {
         strcpy(unit_, value);
      }

   }

   fstream & AmaProduct::store(fstream & file, bool addNewLine) const
   {

      file << fileTag_ << ','
         << sku() << ','
         << name() << ','
         << price() << ','
         << taxed() << ','
         << quantity() << ','
         << unit() << ','
         << qtyNeeded();
         if (addNewLine) {
         file << endl;
         }
         else {
            file << ',';
         }
      return file;
   }

   inline fstream & AmaProduct::load(fstream & file)
   {
      double td;
      int ti;
      int tq;
      int tn;
      char s[MAX_SKU_LEN];
      char n[MAX_NAME_SIZE];

      file.getline(s, MAX_SKU_LEN, ','); // SKU
      sku(s);

      file.getline(n, MAX_NAME_SIZE, ',');// NAME
      name(n);

      (file >> td).ignore(); // PRICE
      price(td);

      (file >> ti).ignore(); //TAXED
      taxed(ti);

      (file >> tq).ignore(); // quantity
      quantity(tq);

      file.getline(n, 10 + 1, ','); // UNIT
      unit(n);

      (file >> tn).ignore(); //quantityNeeded
      qtyNeeded(tn);

      return file;
   }

   ostream & AmaProduct::write(ostream & os, bool linear) const
   {
      if (!err_.isClear()) {
         os << err_.message();
      }
      else {
         if (linear) {
            os << setfill(' ') << left << " " << setw(MAX_SKU_LEN)
               << sku() << '|' <<
               setw(20) << name() << '|' << right << setw(7) << fixed << showpoint <<
               setprecision(2) << cost() << '|' <<
               setw(4) << quantity() << '|' << setw(10) <<
               left << unit() << '|' << right <<
               setw(4) << qtyNeeded() << '|';
         }

         else {
            if (taxed()) {
               os << "Sku: " << sku() << endl
                  << "Name: " << name() << endl
                  << "Price: " << price() << endl
                  << "Price after tax: " << cost() << endl
                  << "Quantity On Hand: " << quantity() << ' ' << unit() << endl
                  << "Quantity Needed: " << qtyNeeded();
            }
            else {
               os << "Sku: " << sku() << endl
                  << "Name: " << name() << endl
                  << "Price: " << price() << endl
                  << "Price after tax: " << "N/A" << endl
                  << "Quantity On Hand: " << quantity() << ' ' << unit() << endl
                  << "Quantity Needed: " << qtyNeeded() << endl;
            }
         }
      }
      return os;
   }

   istream & AmaProduct::read(istream & is)
   {
      double td;
      int ti;
      int qn;
      char yn;
      char s[MAX_SKU_LEN];
      char un[DISPLAY_LINES + 1]; // 10 + 1
      string uns;
      string tns;
      char tn[21];

      if (!is.fail()) {
         err_.clear();
         cout << "Sku: ";
         is >> s;
         sku(s);
         ///////////////
         cout << "Name: ";
         is.ignore();
         getline(is, tns);
         if (tns.empty()) {
            tn[0] = 0;
         }
         else {
            strcpy(tn, tns.c_str());
         }
         name(tn);
         ///////////////
         cout << "Unit: ";
         getline(is, uns);
         if (uns.empty()) {
            un[0] = 0;
         }
         else {
            strcpy(un, uns.c_str());
         }
         unit(un);
         ///////////////
         cout << "Taxed? (y/n): ";
         is >> yn;
         switch (yn) {
         case 'Y':
            taxed(true);
            break;
         case 'y':
            taxed(true);
            break;
         case 'n':
            taxed(false);
            break;
         case 'N':
            taxed(false);
            break;
         default:
            err_.message("Only (Y)es or (N)o are acceptable");
            is.setstate(ios::failbit);
         }
         ///////////////
         if (err_.isClear()) {
            cout << "Price: ";
            cin.ignore();
            is >> td;
            if (is.fail()) {
               err_.message("Invalid Price Entry");
               is.setstate(ios::failbit);
            }
            else {
               price(td);
            }
         }
         ////////////////
         if (err_.isClear()) {
            cout << "Quantity On hand: ";
            cin.ignore();
            is >> ti;
            if (is.fail()) {
               err_.message("Invalid Quantity Entry");
               is.setstate(ios::failbit);
            }
            else {
               quantity(ti);
            }
         }
         ////////////////
         if (err_.isClear()) {
            cout << "Quantity Needed: ";
            is >> qn;
            if (is.fail()) {
               err_.message("Invalid Quantity Needed Entry");
               is.setstate(ios::failbit);
            }
            else {
               qtyNeeded(qn);
               //cin.ignore();
            }
         }
      }

      return is;
   }

}