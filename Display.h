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
	Control * ptr_t_control;
	Data * ptr_t_data;
//	Display * ptr_t_display;

	static Pointers  StaticPointers;

	UserInterface * window;

	//constructor
	Display();
	void construct(Pointers pointers);
};







#endif //_DISPLAY_H_INCLUDED_
