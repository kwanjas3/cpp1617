// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict {


   // TODO: implement the default constructor
   Fraction::Fraction()
   {
      if (!isEmpty()) {
         setEmpty();
      }
   }
   // TODO: implement the two-argument constructor
   Fraction::Fraction(const int n, const int d)
   {
      if (!isEmpty()) {
         if (n > 0 && d > 0) {
            numerator = n;
            denominator = d;
            reduce();
         }
         else {
            setEmpty();
         }
      }
   }
   // TODO: implement the max query
   // max returns the maximum of the numerator and denominator
   //
   int Fraction::max() const
   {
      int greater;
      if (numerator > denominator) {
         greater = numerator;
      }
      else {
         greater = denominator;
      }
      return greater;
   }
   // TODO: implement the min query
   // min returns the maximum of the numerator and denominator
   //
   int Fraction::min() const
   {
      int lesser;
      if (numerator < denominator) {
         lesser = numerator;
      }
      else {
         lesser = denominator;
      }
      return lesser;
   }
   // gcd returns the greatest common divisor of num and denom
   //
   int Fraction::gcd() const {
      int mn = max();  // min of numerator and denominator
      int mx = min();  // max of numerator and denominator
      int g_c_d = 1;
      bool found = false;

      for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
         if (mx % x == 0 && mn % x == 0) {
            found = true;
            g_c_d = x;
         }
      }
      return g_c_d;
   }




   // TODO: implement the reduce modifier  
   // reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
   //
   void Fraction::reduce() {
      int gcd = Fraction::gcd();
      numerator /= gcd;
      denominator /= gcd;
   }

   void Fraction::setEmpty()
   {
      numerator = -1;
      denominator = -1;
   }







   // TODO: implement the display query
   // display inserts num/denom into the output stream
   //
   void Fraction::display() const
   {
      if (denominator == 1) {
         cout << numerator << endl;
      }
      else if (numerator == -1 && denominator == -1) {
         cout << "no fraction stored" << endl;
      }
      else {
         cout << numerator << "/" << denominator << endl;
      }
   }



   // TODO: implement the isEmpty query
   // isEmpty returns true if Fraction object is in a safe empty state
   //
   bool Fraction::isEmpty() const
   {
      return (numerator == -1 && denominator == -1);
   }





   // TODO: implement the + operator
   // + operator adds the rhs to the current object and reduces the result
   //
   Fraction Fraction::operator+(const Fraction &rhs)
   {
      Fraction temp;
      temp = *this;
      int tempnum;
      int tempden;
      if (isEmpty() == true || rhs.isEmpty() == true) {
         temp.setEmpty();
      }
      else {
         tempnum = (temp.numerator*rhs.denominator) + (rhs.numerator* temp.denominator);
         tempden = temp.denominator*rhs.denominator;
         temp.numerator = tempnum;
         temp.denominator = tempden;
         temp.reduce();
      }
      return temp;
   }

   Fraction Fraction::operator*(const Fraction &x)
   {
      Fraction temp = *this;
      if (temp.isValid() && x.isValid()) {
         temp.numerator = numerator * x.numerator;
         temp.denominator = denominator * x.denominator;
         temp.reduce();
      }
      else {
         temp.setEmpty();
      }
      return temp;
   }

   bool Fraction::operator==(const Fraction & x) const
   {
      bool check = false;
      if (isValid() && x.isValid()) {
         if (numerator == x.numerator && denominator == x.denominator) {
            check = true;
         }
      }
      return check;
   }

   bool Fraction::operator!=(const Fraction & x) const
   {
      bool check = false;
      if (isValid() && x.isValid()) {
         if (numerator != x.numerator || denominator != x.denominator) {
            check = true;
         }
      }
      return check;
   }

   Fraction & Fraction::operator+=(const Fraction & y)
   {
      if (isValid() && y.isValid()) {
         numerator = (numerator*y.denominator) + (y.numerator*denominator);
         denominator *= y.denominator;
         reduce();
      }
      else {
         setEmpty();
      }
      return *this;
   }



   bool Fraction::isValid() const {
      return (numerator > 0 && denominator > 0);
   }


}
