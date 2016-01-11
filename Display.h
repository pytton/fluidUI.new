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
//	Pointers * pointers;	//for communication between three main classes - must be set from outside

	static int mystaticint;
	static Pointers  StaticPointers;
	Data * ptr_t_data;	//	this needs to be set from outside by Pointer class
	Control * ptr_t_control;

	UserInterface * window;

	//constructor
	Display();
	//{
	//	window = new UserInterface;
	//	//window->show();
	//}
};







#endif //_DISPLAY_H_INCLUDED_
