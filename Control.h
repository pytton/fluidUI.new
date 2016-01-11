#ifndef _CONTROL_H_INCLUDED_
#define _CONTROL_H_INCLUDED_

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//#include "UserInterface.h"
//#include "MktSnapshot.h"	//for Price and MktSnapshot

#include "Pointers.h"

class Data;
class Control;
class Pointers;


class Control
{
public:
	//Pointers * pointers;
	static Pointers  StaticPointers;
	Display * ptr_t_display;
	Data * ptr_t_data;

	static Pointers myStaticPointers;
	//empty so far - put algos here?

	static Pointers setStaticPointers(Pointers * p);

};








#endif //_CONTROL_H_INCLUDED_
