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
class WidgetTable;

class UserInterface : public FluidInterface
{
public:
	
	
	static const double TIMER_TIMEOUT;// = 1.0;
	bool m_is_animated;
	int m_count;
	WidgetTable *table;

	Fl_Text_Buffer * textBuffer;// = new Fl_Text_Buffer();
	Fl_Text_Display * text;// = new Fl_Text_Display(205, 210, 475, 160, "text");

public:
	//constructors/destructor
	UserInterface();
	void show();
	//callback functions
	static void cb_btn_start_callback(Fl_Widget* btn, void* userdata);
	static void cb_btn_stop_callback(Fl_Widget* btn, void* userdata);
	static void timer_event(void* userdata);
	void setptr();

};




// Simple demonstration class to derive from Fl_Table_Row
//
class WidgetTable : public Fl_Table_Row
{
protected:
	void draw_cell(TableContext context,  		// table cell drawing
		int R = 0, int C = 0, int X = 0, int Y = 0, int W = 0, int H = 0);
	
public:
	Fl_Widget * WidgetTable::GetElement(int nRow, int nCol);
	void * ptr_to_UserInterface;	//stores a pointer to window in which table is constructed. null at first. has to be set from outside.
	int table_rows, table_cols;


	static void button_cb(Fl_Widget *w, void * p);



	WidgetTable(int x, int y, int w, int h, const char *l);// : Fl_Table_Row(x, y, w, h, l);
	~WidgetTable() { }
	void SetSize(int newrows, int newcols, WidgetTable * mytable)
	{
		rows(newrows);
		cols(newcols);
		begin();		// start adding widgets to group
		{
			for (int r = 0; r<newrows; r++)
			{
				for (int c = 0; c<newcols; c++)
				{
					int X, Y, W, H;
					find_cell(CONTEXT_TABLE, r, c, X, Y, W, H);

					char s[40];
					if (c != 0) //this used to be ( c & 1) -bitwise comparison
					{
						// Create the input widgets
						//sprintf(s, "%d.%d", r, c);
						Fl_Input *in = new Fl_Input(X, Y, W, H);
						//in->value(s);
					}
					else
					{
						// Create the light buttons
						sprintf(s, "%d/%d ", r, c);
						Fl_Light_Button *butt = new Fl_Light_Button(X, Y, W, H, strdup(s));
						butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
						butt->callback(button_cb,  (void*) mytable );
						butt->value(((r + c * 2) & 4) ? 1 : 0);
					}
				}
			}
		}
		end();
		
	}
};



#endif //_UserInterface_H_INCLUDED_