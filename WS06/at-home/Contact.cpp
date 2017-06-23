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
   bool Contact::isValid(const long long x) const
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
         if (strlen(srcname)>sizeOfName) {
            for (int i = 0; i < (sizeOfName - 1) && srcname[i] != NULL; i++) {
               name[i] = srcname[i];
            }
         }
         else {
            strcpy_s(name, sizeOfName, srcname);
            pnum = new long long[sizeNum = numOfPhones];
            for (int i = 0; i < sizeNum; i++) {
               if (isValid(aPhone[i])) {
                  pnum[i] = aPhone[i];
               }
            }
         }

      }
      else {
         setEmpty();
      }
   }
   Contact::Contact(const Contact &x)
   {
      pnum = nullptr;
      *this = x;
   }
   Contact & Contact::operator=(const Contact &x)
   {
      if (this != &x) {
         strncpy_s(name, x.name, 19);
         sizeNum = x.sizeNum;
         delete[] pnum;
         if (x.pnum != nullptr) {
            pnum = new long long[sizeNum];
            for (int i = 0; i < sizeNum; pnum[i] = x.pnum[i++]);
         }
         else {
            pnum = nullptr;
         }
      }
      return *this;
   }
   Contact & Contact::operator+=(const long long newnum)
   {
      if (isValid(newnum)) {
         long long* resize = new long long[sizeNum + 1];
         for (int i = 0; i < sizeNum; resize[i] = pnum[i++]);
         delete[] pnum;
         pnum = resize;
         pnum[sizeNum] = newnum;
         sizeNum++;
      }
      return *this;
   }

   Contact::~Contact()
   {
      delete[] pnum;
   }


   bool Contact::isEmpty() const
   {
      return (pnum == nullptr && name[0] == 0 && sizeNum == 1);
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