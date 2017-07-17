// Product.h
#ifndef SICT_PRODUCT_H__
#define SICT_PRODUCT_H__
#include "Streamable.h"
#include "general.h"

namespace sict {
   class Product : public Streamable {
   private:
      char sku_[MAX_SKU_LEN + 1];
      char* name_;
      double price_;
      bool taxed_;
      int quantity_;
      int qtyNeeded_;

   public:
      Product();
      Product(const Product &x);
      Product(const char *, const char *); // this was not in the PDF
      Product(const char* sku, const char* name, bool taxed, double price, int needed);
      ~Product();

      void setEmpty();
      bool isEmpty()const;

      Product& operator=(const Product & x);
      bool operator== (const char* sku);
      int operator+=(const int x);
      int operator-=(const int x);
      //setters
      void sku(const char* x);
      void price(const double x);
      void name(const char *x); 
      void taxed(const bool x);
      void quantity(const int x);
      void qtyNeeded(const int x);

      //getters
      const char* sku()const;
      const double price()const;
      const char* name()const  ;
      const bool taxed()const  ;
      const int quantity()const ;
      const int qtyNeeded()const;
      const double cost()const; 
   };

   double operator+=(double& ref, const Product& x);

   std::ostream & operator<<(std::ostream &os, Product& x);
   std::istream & operator>>(std::istream &is, Product& x);
}
#endif // !SICT_PRODUCT_H__
