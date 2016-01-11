#ifndef _DATA_H_INCLUDED_
#define _DATA_H_INCLUDED_

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//#include "UserInterface.h"
#include "MktSnapshot.h"	//for Price and MktSnapshot
#include "Pointers.h"
//#include "Display.h"

class Data;
class Control;
class Pointers;


class Data	//stores all data used by program
{	//put all marketdata here
public:
	static Pointers myStaticPointers;
	Display * ptr_t_display;	//this needs to be set from outside by Pointer class
	Control * ptr_t_control;	//used for communication 

	std::vector<MktSnap>  histSavedData;	//holds historical data saved in a file called "Sample2.txt"

	//member functions:

	void MktSnapshot();	//loads historical data into memory (from Sample2.txt)
	void Data::LiveData();
};


#endif //_DATA_H_INCLUDED_
