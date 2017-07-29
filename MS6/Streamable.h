#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__ // matrix error comment these out and use pragma once instead
#include <fstream>
#include <iostream>

namespace sict {
   class Streamable {
   public:
      virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;
      virtual std::fstream& load(std::fstream& file) = 0;
      virtual std::ostream& write(std::ostream& os, bool linear)const = 0;
      virtual std::istream& read(std::istream& is) = 0;
   };

}
#endif // !SICT_STREAMABLE_H__

