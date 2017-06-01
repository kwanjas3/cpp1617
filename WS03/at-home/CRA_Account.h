#ifndef sict_CRA_Account_h__
#define sict_CRA_Account_h__
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
#define MAX_YRS 4


namespace sict {
   class CRA_Account
   {
   public:
      void set(const char* familyName_, const char* givenName_, int sin_);
      void set(int year, double balance);
      bool isValid() const;
      void display() const;
   private:
      char familyName[MAX_NAME_LENGTH + 1];
      char givenName[MAX_NAME_LENGTH + 1];
      int sin;
      int m_year[MAX_YRS] = { 0 };
      double m_balance[MAX_YRS] = { 0 };
      int m_years = 0;
   };
}

#endif // !sict_CRA_Account_h__

