#ifndef SICT_CONTACT_H__
#define SICT_CONTACT_H__

namespace sict {
	const int sizeOfName = 22;
	class Contact {
	private:
		char name[sizeOfName];
		long long* pnum;
		int sizeNum;
	public:
		Contact();
		Contact(const char* name, const long long* aPhone, const int numOfPhones);
		~Contact();
		Contact& operator=(const Contact&);
		Contact(const Contact&);		
		bool isEmpty() const;
		void display() const;

	};

}

#endif