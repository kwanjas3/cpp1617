// AmaPerishable.h
#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include "AmaProduct.h"
#include "Date.h"
#include "ErrorMessage.h"

namespace sict {
   class AmaPerishable : public AmaProduct {
   private:
      Date expiry_;
   public:
      AmaPerishable();
      const Date& expiry()const;
      void expiry(const Date& value);


      fstream& store(fstream& file, bool addNewLine = true)const;
      fstream& load(fstream& file);
      ostream& write(ostream& ostr, bool linear)const;
      istream& read(istream& istr);
   };

}
#endif // !SICT_AMAPERISHABLE_H__
