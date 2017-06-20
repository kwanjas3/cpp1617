#include <iostream>
#include "Contact.h"
#include <cstring>
using namespace std;

namespace sict {
	Contact::Contact()
	{
		name[0] = 0;
		sizeNum = 1;
		pnum = new long long[sizeNum];
		pnum[0] = 0;
	}
	Contact::Contact(const char* srcname, const long long* aPhone, const int numOfPhones)
	{
		strcpy_s(name, srcname);
		pnum = new long long[sizeNum = numOfPhones];
		for (int i = 0; i < numOfPhones; pnum[i] = aPhone[i++]);
		
	}
	Contact::~Contact()
	{
		delete[] pnum;
	}
	Contact::Contact(const Contact& src)
	{
		pnum = nullptr;
		operator=(src);
	}
	Contact & Contact::operator=(const Contact &x)
	{
		if (this != &x) {
			sizeNum = x.sizeNum;
			if (x.pnum != nullptr && x.name != nullptr && x.sizeNum != 0) {
			delete[] pnum;
			pnum = new long long[sizeNum];
			for (int i = 0; i < sizeNum; pnum[i] = x.pnum[i++]);
			}
		}
		return *this;
	}
	bool Contact::isEmpty() const
	{
		return (pnum[0] == 0 && name[0]==0 && sizeNum == 1);
	}
	void Contact::display() const
	{
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << "CONTACT_NAME" << endl;
			for (int i = 0; i < sizeNum; i++) {
				cout << "+" << pnum[i] / 10000000000 << pnum[i] / 10000000 % 1000 << " "
					<< pnum[i] / 10000 % 1000 << "-" << pnum[i] % 10000 << endl;
			}
		}
	}
}