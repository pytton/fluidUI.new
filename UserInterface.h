#ifndef _UserInterface_H_INCLUDED_
#define _UserInterface_H_INCLUDED_

#include "FLUID/FluidInterface.h"

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

class UserInterface : public FluidInterface
{
public:	
	static const double TIMER_TIMEOUT;// = 1.0; used for callback from Youtube video
	bool m_is_animated;
	int m_count;
	WidgetTable *table;		
	//this replaces regular Fl_Table with my custom one
	
	Fl_Text_Buffer * textBuffer;
	Fl_Text_Display * text;
	std::stringstream textDisplayString;

	//constructors/destructor
	UserInterface();
	void show();
	
	//callback functions
	static void cb_btn_start_callback(Fl_Widget* btn, void* userdata);	//from youtube video - timeout feature demo
	static void cb_btn_stop_callback(Fl_Widget* btn, void* userdata);	//form youtube
	static void timer_event(void* userdata);							//from youtube - timeout
	//void setptr();	//OLD CODE? DO I STILL NEED THIS?
};

class WidgetTable : public Fl_Table_Row		//WigetTable - table with cells drawed inside it
{
protected:
	void draw_cell(TableContext context,  		// table cell drawing
		int R = 0, int C = 0, int X = 0, int Y = 0, int W = 0, int H = 0);	//supplied from example - dont know how this works
	
public:
	Fl_Widget * WidgetTable::GetElement(int nRow, int nCol);
	//returns a pointer to the cell in the table at nRow nCol

	void * ptr_to_UserInterface;	//stores a pointer to window in which table is constructed. null at first. has to be set from outside.
	int table_rows, table_cols;

	//callbacks:
	static void button_cb(Fl_Widget *w, void * p);	//callbacks in fltk have to be static

	//constructor:
	WidgetTable(int x, int y, int w, int h, const char *l);
	~WidgetTable() { }
	
	//the below function fills the table with cells:
	void SetSize(int newrows, int newcols, WidgetTable * mytable);
};



#endif //_UserInterface_H_INCLUDED_