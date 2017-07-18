// AmaPersishable.cpp
#include "AmaPerishable.h"
namespace sict {
   AmaPerishable::AmaPerishable() : AmaProduct('P')
   {

   }
   const Date & AmaPerishable::expiry() const
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
   ostream & AmaPerishable::write(ostream & ostr, bool linear) const
   {
      return ostr;
   }
   istream & AmaPerishable::read(istream & istr)
   {
      return istr;
   }
}