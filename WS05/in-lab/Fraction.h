// TODO: header file guard
#ifndef SICT_FRACTION_H__
#define SICT_FRACTION_H__





// TODO: create namespace
namespace sict {

   // TODO: define the Fraction class
   class Fraction {
   private:
      int numerator;
      int denominator;
      int gcd() const; // returns the greatest common divisor of num and denom
      int max() const; // returns the maximum of num and denom
      int min() const; // returns the minimum of num and denom
      void reduce();   // simplifies a Fraction by dividing the 
                       // numerator and denominator to their greatest common divisor 
      void setEmpty();
   public:
      // TODO: declare the member functions
      Fraction();
      Fraction(const int n, const int d);
      bool isEmpty() const;
      void display() const;
      // TODO: declare the + operator overload
      Fraction operator+(const Fraction&);
   };
}

#endif // !SICT_FRACTION_H__
