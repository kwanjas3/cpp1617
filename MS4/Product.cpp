
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Product.h"

namespace sict {
   Product::Product()
   {
      setEmpty();
   }

   Product::Product(const Product & x)
   {
      sku(x.sku_);
      name(x.name_);
      price(x.price_);
      taxed(x.taxed_);
      quantity(quantity_);
      qtyNeeded(x.qtyNeeded_);
   }

   Product::Product(const char *x, const char *y)
   {
      sku(x);
      name(y);
   }

   Product::Product(const char * s, const char * nm, bool tax, double p, int needed)
   {
      sku(s);
      name(nm);
      taxed(tax);
      price(p);
      qtyNeeded(needed);
      quantity(0);
   }

   Product::~Product()
   {   
      clearMemory();   
   }

   void Product::setEmpty()
   {
      sku_[0] = 0;
      name_ = nullptr;
      price_ = 0;
      taxed_ = 0;
      quantity_ = 0;
      qtyNeeded_ = 0;
   }

   bool Product::isEmpty() const
   {
      return (sku_[0] == 0 &&
         name_ == nullptr &&
         price_ == 0 &&
         taxed_ == 0 &&
         quantity_ == 0 &&
         qtyNeeded_ == 0);
   }

 

  

   Product& Product::operator=(const Product & x)
   {
      if (this != &x) {
         sku(x.sku_);
         name(x.name_);
         price(x.price_);
         quantity(x.quantity_);
         taxed(x.taxed_);
         qtyNeeded(x.qtyNeeded_);
      }
      return *this;
   }

   void Product::clearMemory()
   {
      delete[] name_;
      name_ = nullptr;
   }

   bool Product::operator==(const char * sku)
   {
      return (strcmp(sku_, sku) == 0);
   }

   int Product::operator+=(const int x)
   {
      return (quantity_ += x);
   }

   int Product::operator-=(const int x)
   {
      return (quantity_ -= x);
   }

   void Product::sku(const char* x)
   {
      strcpy(sku_, x);
   }

   void Product::name(const char* x) {
      clearMemory();
      name_ = new char[strlen(x)];
      strcpy(name_, x);
   }

   void Product::price(const double x)
   {
      price_ = x;
   }

   

   void Product::taxed(const bool x)
   {
      taxed_ = x;
   }

   void Product::quantity(const int x)
   {
      quantity_ = x;
   }

   void Product::qtyNeeded(const int x)
   {
      qtyNeeded_ = x;
   }

   const char * Product::sku() const
   {
      return sku_;
   }

   const double Product::price() const
   {
      return price_;
   }

   const char * Product::name() const
   {
      return name_;
   }

   const bool Product::taxed() const
   {
      return taxed_;
   }

   const int Product::quantity() const
   {
      return quantity_;
   }

   const int Product::qtyNeeded() const
   {
      return qtyNeeded_;
   }

   const double Product::cost() const
   {
      double cost = 0;
      if (taxed()) {
         cost = price() * (1 + taxed());
      }
      else {
         cost = price();
      }
      return cost;
   }


   double operator+=(double & ref, const Product & a)
   {
      ref += a.price() * a.quantity();
      return ref;
   }

   std::ostream & operator<<(std::ostream &os, Product& x)
   {
      return x.write(os, true);
   }

   std::istream & operator>>(std::istream &is, Product& x)
   {
      return x.read(is);
   }


}