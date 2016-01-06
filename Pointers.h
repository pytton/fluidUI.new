//includes Data, Control and Display

#ifndef _POINTERS_H_INCLUDED_
#define _POINTERS_H_INCLUDED_
//this class stores pointers to all elements of the application - for easy access

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "UserInterface.h"
#include "MktSnapshot.h"	//for Price and MktSnapshot

class Data;
class Control;
class Pointers;

class Display	//stores all user input/output activities
{
public:
	Data * ptr_t_data;	//	this needs to be set from outside by Pointer class
	Control * ptr_t_control; 
	
	UserInterface * window;
	
	//constructor
	Display()
	{
		window = new UserInterface;
		//window->show();
	}
};

class Data	//stores all data used by program
{	//put all marketdata here
public:
	Display * ptr_t_display;	//this needs to be set from outside by Pointer class
	Control * ptr_t_control;	//used for communication 
	
	std::vector<MktSnap>  histSavedData;	//holds historical data saved in a file called "Sample2.txt"
	
//	Data()	//constructor
//	{
////		ptr_t_display->window->m_value_5->value(200);	//ERASE THIS this is only for testing
//														//this creates a RUNTIME ERROR
//	}

	//member functions:

	void MktSnapshot();	//loads historical data into memory (from Sample2.txt)
	void Data::LiveData();
};

class Control
{
public:
	Display * ptr_t_display;
	Data * ptr_t_data;
	
	//empty so far - put algos here?


};

class Pointers	//this is used for communication between three main elements of the program
{
public:
	Display * ptr_t_display;
	Data * ptr_t_data;
	Control * ptr_t_control;

	void initPointers(Display * display, Data * data, Control * control)
	{
		ptr_t_display = display;
		ptr_t_data = data;
		ptr_t_control = control;
	}
};




#endif // !_POINTERS_H_INCLUDED_



////below, just for reference - a way to handle pointers the safe? or stupid? way:
//
//class Display	//stores all user input/output activities
//{
//public:
//	UserInterface * window;
//	Display * ptr_t_display;	//pointer to self - used for access
//
//								//constructor
//	Display()
//	{
//		window = new UserInterface;
//		window->show();
//	}
//	void set_display_ptr()	//THIS MUST BE CALLED RIGHT AFTER CONSTRUCTING CLASS!!!!
//	{
//		ptr_t_display = this;
//	}
//	Display * get_display_ptr()
//	{
//		return this;
//	}
//};
//
//class Data	//stores all data used by program
//{	//put all marketdata here
//public:
//	Data * ptr_t_data;
//
//	Data()	//constructor
//	{
//
//	}
//	void set_data_ptr()	//THIS MUST BE CALLED RIGHT AFTER CONSTRUCTING CLASS!!!!
//	{
//		ptr_t_data = this;
//	}
//	Data * get_data_ptr()
//	{
//		return this;
//	}
//
//};
//
//class Control
//{
//public:
//
//
//};
//
//class Pointers
//{
//public:
//	Display * ptr_t_display;
//	Data * ptr_t_data;
//	Control * ptr_t_control;
//
//
//	//below is old code:
//	//void * ptr_t_UserInterface;	//main window of userinterface
//	//void set_ptr_t_UserInterface(void * pointer)
//	//{
//	//	ptr_t_UserInterface = pointer;
//	//}
//	//void * get_ptr_t_UserInterface()
//	//{
//	//	return ptr_t_UserInterface;
//	//}
//};