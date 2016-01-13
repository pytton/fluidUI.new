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
	
	static Pointers  StaticPointers;
	Pointers pointers;

	//constructor:
	Control();	//called first
	void construct(Pointers pointers);	//this must be run from outside to initialize class with correct pointers!

	//member functions:
	void tryout1();

};








#endif //_CONTROL_H_INCLUDED_
