#ifndef _DISPLAY_H_INCLUDED_
#define _DISPLAY_H_INCLUDED_

#include "Pointers.h"
#include "UserInterface.h"


class Data;
class Control;
class Pointers;

//Pointers Display::StaticPointers = 0;



class Display	//stores all user input/output activities
{
public:
	static Pointers  StaticPointers;

	UserInterface * window;

	//constructor
	Display();
	//void construct(Pointers pointers);
};







#endif //_DISPLAY_H_INCLUDED_
