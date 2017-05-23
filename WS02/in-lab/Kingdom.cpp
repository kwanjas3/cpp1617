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
	void display( const Kingdom& kingdom ) {
		cout << kingdom.m_name << ", " << kingdom.m_population << endl;
	}
}
