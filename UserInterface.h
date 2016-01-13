#ifndef _UserInterface_H_INCLUDED_
#define _UserInterface_H_INCLUDED_

#include "FLUID/FluidInterface.h"
#include "Pointers.h"

#include <iostream>
#include <sstream>

#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Table_Row.H>
#include <FL/Fl_Text_Display.H>


//const double TIMER_TIMEOUT = 1.0; // 1 sec
class WidgetTable;	//forward declaration
class Pointers;
class Display;

class UserInterface : public FluidInterface
{public:
	
	static Pointers StaticPointers;

//	class Pointers;
	Display * ptr_t_display;
	Pointers *pointers2;
	//Pointers & refToPointers;
	WidgetTable *table;		//this replaces regular Fl_Table with my custom one
	
	int myint;
	Fl_Text_Buffer * textBuffer;
	Fl_Text_Display * text;
	std::stringstream textDisplayString;

	//constructors/destructor
	
	UserInterface(Display*p);
	UserInterface(Pointers p);
	UserInterface(/*Pointers *p*/);
	void show();
	
	//callback functions
	static void experimental2_cb(Fl_Widget *w, void * p);
	static void experimental_cb(Fl_Widget *w, void * p);
	
	//helper functions
	

};

class WidgetTable : public Fl_Table_Row		//WigetTable - table with cells drawed inside it
{protected:
	void draw_cell(TableContext context,  		// table cell drawing
		int R = 0, int C = 0, int X = 0, int Y = 0, int W = 0, int H = 0);	//supplied from example - dont know how this works
	
public:
	UserInterface * ptr_to_UserInterface;	//stores a pointer to window in which table is constructed. null at first. has to be set from outside.
	int table_rows, table_cols;

	//callbacks:
	static void button_cb(Fl_Widget *w, void * p);	//callbacks in fltk have to be static

	
	//constructor:
	WidgetTable(int x, int y, int w, int h, const char *l);
	~WidgetTable() { }
	
	//the below function fills the table with cells:
	void SetSize(int newrows, int newcols, WidgetTable * mytable);

	//helper functions:
	void printInTable(int row, int col, std::string text, WidgetTable * myWidgetPointer);
	Fl_Widget * GetElement(int nRow, int nCol);	//returns a pointer to the cell in the table at nRow nCol
};

class My_fl_button : public Fl_Button  //with location of button in Fl_Table
{
public:
	//below determines where in the Fl_Table the button is located
	//needs to be set inside WidgetTable::SetSize function
	int x_pos;
	int y_pos;

	//constructor:
	My_fl_button(int x, int y, int w, int h, const char *l = 0)
		: Fl_Button(x, y,  w,  h, l ), x_pos(0), y_pos(0)
	{
		//x_pos = 0;
		//y_pos = 0;
	}
};



#endif //_UserInterface_H_INCLUDED_