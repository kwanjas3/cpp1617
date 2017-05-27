#ifndef sict_CRA_Account_h__
#define sict_CRA_Account_h__
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
namespace sict {

   class CRA_Account
   {
   public:
      void set(const char* familyName_, const char* givenName_, int sin_);
      bool isValid() const;
      void display() const;
   private:
      char familyName[MAX_NAME_LENGTH];
      char givenName[MAX_NAME_LENGTH];
      int sin;
   };
}

#endif // !sict_CRA_Account_h__

