#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include "Product.h"
#include "ErrorMessage.h"

using namespace std;
namespace sict {
   class AmaProduct : public Product {
   private:
      char fileTag_;
      char unit_[11];// unit of measurement 
   protected:
      ErrorMessage err_;
   public:
      AmaProduct(const char ft = 'N');

      const char* unit()const;
      void unit(const char* value);

      fstream& AmaProduct::store(fstream& file, bool addNewLine)const;
      fstream& AmaProduct::load(fstream& file);
      ostream& AmaProduct::write(ostream& os, bool linear)const;
      istream& AmaProduct::read(istream& istr);
   };
}

#endif // !SICT_AMAPRODUCT_H__
