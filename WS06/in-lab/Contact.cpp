#include <iostream>
#include "Contact.h"
#include <cstring>
using namespace std;

namespace sict {
   void Contact::setEmpty()
   {
      name[0] = 0;
      sizeNum = 1;
      pnum = nullptr;
   }
   bool Contact::isValid(long long x) const
   {
      bool check = false;
      long long cc = x / 10000000000;
      long long ac = x / 10000000 % 1000;
      long long pre = x / 10000 % 1000;

      if (cc > 0 && cc < 100 &&
         ac > 100 && ac < 1000 &&
         pre > 100 && pre < 1000) {
         check = true;
      }

      return check;
   }
   Contact::Contact()
   {
      if (!isEmpty()) {
      setEmpty();
      }
   }
   Contact::Contact(const char* srcname, const long long* aPhone, const int numOfPhones)
   {
      if (srcname != nullptr && strlen(srcname) != 0) {
         strncpy_s(name, srcname, sizeOfName - 1);
         pnum = new long long[sizeNum = numOfPhones];
         int count = 0;
         for (int i = 0; i < sizeNum; i++) {
            if (isValid(aPhone[i])) {
               pnum[i] = aPhone[i];
               //count++;
            }
            else {
               pnum[i] = 0;
            }
         }
      }
      else {
         setEmpty();
      }
   }

   Contact::~Contact()
   {
      delete[] pnum;
   }


   void Contact::display() const
   {
      if (isEmpty()) {
         cout << "Empty contact!" << endl;
      }
      else {
         cout << name << endl;
         for (int i = 0; i < sizeNum; i++) {
            if (isValid(pnum[i])) {
               cout << "(+" << pnum[i] / 10000000000 << ") " << pnum[i] / 10000000 % 1000 << " "
                  << pnum[i] / 10000 % 1000 << "-" << pnum[i] % 10000 << endl;
            }
         }
      }
   }
}