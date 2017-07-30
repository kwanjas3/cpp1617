#ifndef SICT_AIDAPP_H__
#define SICT_AIDAPP_H__
#include <iostream>
#include "AmaPerishable.h"
#include "AmaProduct.h"
#include "general.h"
#include "Streamable.h"

namespace sict {
   class AidApp {
   private:
      char filename_[256];
      Product* product_[MAX_NO_RECS];
      fstream datafile_; //An fstream instance used to create and access a file.
      int noOfProducts_;
      AidApp (const AidApp&);                 //Prevent users from using these
      AidApp operator=(const AidApp&);        //Prevent users from using these
   public:
      AidApp(char * file);
      ~AidApp();
      void pause()const;
      int menu();
      void loadRecs();
      void saveRecs();
      void listProducts()const;
      int SearchProducts(const char* sku)const;
      void addQty(const char* sku);
      void addProduct(bool isPerishable);
      int run();
      void deallocate();
   };
}


#endif // !SICT_AIDAPP_H__

