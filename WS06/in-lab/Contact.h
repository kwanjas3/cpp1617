#ifndef SICT_CONTACT_H__
#define SICT_CONTACT_H__

namespace sict {

	const int sizeOfName = 20;

	class Contact {
	private:
		char name[sizeOfName + 1];
		long long* pnum;
		int sizeNum;
      void setEmpty();
      bool isValid(long long) const;
	public:
		Contact();
		Contact(const char* name, const long long* aPhone, const int numOfPhones);
		~Contact();		
      bool isEmpty() const
      {
         return (pnum == nullptr && name[0] == 0 && sizeNum == 1);
      }
      void display() const;
	};

}

#endif