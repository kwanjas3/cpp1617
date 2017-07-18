// Final Project Milestone 2
// Version 1.0
// Date	
// Author	Jason Kwan
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__

namespace sict {
   class ErrorMessage {
   
   private:
      char* message_;

   public:
      ErrorMessage();
      ErrorMessage(const char * errorMessage);
      ErrorMessage(const ErrorMessage& em) = delete;
      ErrorMessage& operator= (const ErrorMessage& em) = delete;
      ErrorMessage& operator= (const char* errorMessage);

      virtual ~ErrorMessage();
      void clear();
      bool isClear()const;
      void message(const char* value);
      const char* message()const;
   };
   std::ostream& operator<<(std::ostream&, ErrorMessage&);
}



#endif // !SICT_ERRORMESSAGE_H__
