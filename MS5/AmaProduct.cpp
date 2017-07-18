#include <cstring>
#include "AmaProduct.h"
// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
namespace sict {
   sict::AmaProduct::AmaProduct(const char ft)
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
         << unit() << ','
         << qtyNeeded()
         << endl;

      return file;
   }

   fstream & AmaProduct::load(fstream & file)
   {
      double td;
      int ti;
      char s[MAX_SKU_LEN];
      char n[MAX_NAME_SIZE];
      char c; // eat buffer

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

      return file;
   }

   ostream & AmaProduct::write(ostream & os, bool linear) const
   {

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
               << "Quantity Needed:  " << qtyNeeded();
         }
         else {
            os << "Sku:: " << sku() << endl
               << "Name:  " << name() << endl
               << "Price:  " << price() << endl
               << "Price after tax:  " << "N/A" << endl
               << "Quantity On Hand:  " << quantity() << ' ' << unit() << endl
               << "Quantity Needed:  " << qtyNeeded();
         }
      }
      return os;
   }

   istream & AmaProduct::read(istream & is)
   {
      double td;
      int ti;
      char yn;
      char s[MAX_SKU_LEN];
      char un[DISPLAY_LINES + 1]; // 10 + 1
      char n[MAX_NAME_SIZE];

      if (!is.fail()) {
         err_.clear();
         cout << "Sku:  ";
         is >> s;
         sku(s);
///////////////
         cout << "Name:  ";
         is >> n;
         name(n);
///////////////
         cout << "Unit:  ";
         is >> un;
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

      }

      return is;
   }

}
