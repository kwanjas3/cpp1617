#ifndef SICT_AIDAPP_H__
#define SICT_AIDAPP_H__
#include <iostream>
#include "AmaPerishable.h"
#include "AmaProduct.h"
#include "general.h"
#include "Streamable.h"

namespace sict {
   class AidApp : Product {
   private:
      char filename_[256];
      Product* product_[MAX_NO_RECS];
      fstream datafile_; //An fstream instance used to create and access a file.
      int noOfProducts_;
   public:
      AidApp(char * file);
      void pause()const;
      int menu();
      void loadRecs();
      void saveRecs();
      void listProducts()const;
      int SearchProducts(const char* sku)const;
      void addQty(const char* sku);
      void addProduct(bool isPerishable);
      int run();
   };
}


#endif // !SICT_AIDAPP_H__

