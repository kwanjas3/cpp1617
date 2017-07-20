
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Product.h"
namespace sict {
   Product::Product()
   {
      setEmpty();
   }

   Product::Product(const Product & x)
   {
      name_ = nullptr;
      *this = x;
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
      delete[] name_;
      name_ = nullptr;
   }

   void Product::setEmpty()
   {
      sku_[0] = 0;
      name_ = nullptr;
      price_ = 0;
      taxed_ = false;
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

   void Product::sku(const char * x)
   {
      strcpy(sku_, x);
   }

   void Product::price(const double x)
   {
      price_ = x;
   }


   void Product::name(const char* x) {
      name_ = new char[strlen(x) + 1];
      if (name_ != nullptr) {
         strcpy(name_, x);
      }
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
     /* double cost;
      if (taxed()) {
      cost = price() * (TAX + 1);
      }
      else
      {
      cost = price();
      }
      return cost;*/
     return taxed() ? price() * (TAX + 1) : price();
   }


   double operator+=(double & ref, const Product & a)
   {
      return ref += a.cost() * a.quantity();
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