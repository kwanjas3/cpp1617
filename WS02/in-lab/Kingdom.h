/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef sict_kingdom_h__
#define sict_kingdom_h__

// TODO: sict namespace
namespace sict {

// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[33];
		int m_population;
		
	};
// TODO: declare the function display(...),
	void display(const Kingdom& kingdom);
//         also in the sict namespace


}
#endif // !sict_kingdom_h___
