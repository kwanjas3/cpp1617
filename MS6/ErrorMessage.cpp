// Final Project Milestone 2
// Version 1.0
// Date	
// Author	
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ErrorMessage.h"

namespace sict {
   ErrorMessage::ErrorMessage()
   {
      message_ = nullptr;
   }
   ErrorMessage::ErrorMessage(const char * errorMessage)
   {
      message_ = nullptr;
      message(errorMessage);
   }
   ErrorMessage & ErrorMessage::operator=(const char * errorMessage)
   {
      clear();
      message(errorMessage);
      return *this;
   }
   ErrorMessage::~ErrorMessage()
   {
      delete[] message_;
   }
   void ErrorMessage::clear()
   {
      delete[] message_;
      message_ = nullptr;
   }
   bool ErrorMessage::isClear() const
   {
      return (message_ == nullptr);
   }
   const char * ErrorMessage::message() const
   {
      return message_;
   }
   std::ostream & operator<<(std::ostream & os, const ErrorMessage & msg)
   {
      if (!msg.isClear()) {
         os << msg.message();
      }
      return os;
   }
}