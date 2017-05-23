/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/



// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(const Kingdom& kingdom) {
		cout << kingdom.m_name << ", " << kingdom.m_population << endl;
	}
	void display(const Kingdom * kingdom, int sizeofKingdom)
	{
		int i;
		int sum = 0;
		for (int i = 0; i < sizeofKingdom; i++) {
			sum += kingdom[i].m_population;
		}
		
		cout << "Kingdoms are" << endl;
		for (i = 0; i < sizeofKingdom; i++) {
			cout << i + 1 << ". " << kingdom[i].m_name << ", " << kingdom[i].m_population << endl;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of all Kingdoms: " << sum << endl;
		cout << "------------------------------" << endl;
	}
}
