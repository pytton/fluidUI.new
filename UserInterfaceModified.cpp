#include <sstream> //replaces cout
#include <string>
#include "UserInterface.h"

#include <iostream>
#include <sstream>

#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Table_Row.H>

const double UserInterface::TIMER_TIMEOUT = 1.0;


// Simple demonstration class to derive from Fl_Table_Row
//
class WidgetTable : public Fl_Table_Row
{
protected:
	void draw_cell(TableContext context,  		// table cell drawing
		int R = 0, int C = 0, int X = 0, int Y = 0, int W = 0, int H = 0);

public:

	Fl_Input * myArrayInput[64][64] = { 0 };		// stores pointers to all the elements of the table

	Fl_Input *returnLocation(int row, int col)
	{
		return myArrayInput[row][col];
	}


	WidgetTable(int x, int y, int w, int h, const char *l = 0) : Fl_Table_Row(x, y, w, h, l)
	{
		col_header(1);
		col_resize(1);
		col_header_height(25);
		row_header(1);
		row_resize(1);
		row_header_width(80);
		end();
	}
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
					if (c & 1)
					{
						// Create the input widgets
						sprintf(s, "%d.%d", r, c);
						Fl_Input *in = new Fl_Input(X, Y, W, H);
						myArrayInput[r][c] = in;	///////////////////////////////to access Fl_input ------> c has to be odd(not even)
						in->value(s);
					}
					else
					{
						// Create the light buttons
						sprintf(s, "%d/%d ", r, c);
						Fl_Light_Button *butt = new Fl_Light_Button(X, Y, W, H, strdup(s));
						butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
						//butt->callback(button_cb,  (void*) mytable );
						butt->value(((r + c * 2) & 4) ? 1 : 0);
					}
				}
			}
		}
		end();
	}
};

void WidgetTable::draw_cell(TableContext context,
	int R, int C, int X, int Y, int W, int H)
{
	switch (context)
	{
	case CONTEXT_STARTPAGE:
		fl_font(FL_HELVETICA, 12);		// font used by all headers
		break;

	case CONTEXT_RC_RESIZE:
	{
		int X, Y, W, H;
		int index = 0;
		for (int r = 0; r<rows(); r++)
		{
			for (int c = 0; c<cols(); c++)
			{
				if (index >= children()) break;
				find_cell(CONTEXT_TABLE, r, c, X, Y, W, H);
				child(index++)->resize(X, Y, W, H);
			}
		}
		init_sizes();			// tell group children resized
		return;
	}

	case CONTEXT_ROW_HEADER:
		fl_push_clip(X, Y, W, H);
		{
			static char s[40];
			sprintf(s, "Row %d", R);
			fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
			fl_color(FL_BLACK);
			fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
		}
		fl_pop_clip();
		return;

	case CONTEXT_COL_HEADER:
		fl_push_clip(X, Y, W, H);
		{
			static char s[40];
			sprintf(s, "Column %d", C);
			fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, col_header_color());
			fl_color(FL_BLACK);
			fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
		}
		fl_pop_clip();
		return;

	case CONTEXT_CELL:
		return;		// fltk handles drawing the widgets

	default:
		return;
	}
}



UserInterface::UserInterface()
{
	m_is_animated = false;
	m_count = 0;
	//m_win_timer->user_data((void*)(this));
	m_win_timer->begin();
	delete m_table;
	WidgetTable table = new WidgetTable(20, 20, 300, 300, "widgettable");
	//WidgetTable * myTablePointer = &table;
	table.SetSize(8, 8, &table);
	//win.end();
	//win.resizable(table);
	//win.show();




	Fl_Button* m_myExtraBtn = new Fl_Button(125, 125, 65, 40, "Extra");
//	m_table->end();
	m_win_timer->end();

}

void UserInterface::show()
{
	m_btn_start->callback((Fl_Callback*)cb_btn_start_callback, this);
	m_btn_stop->callback((Fl_Callback*)cb_btn_stop_callback, this);
	m_win_timer->show();
}

void UserInterface::cb_btn_start_callback(Fl_Widget* btn, void* userdata)
{
	UserInterface* window = (UserInterface*)userdata;
	window->m_win_timer->label("start"); //set window title
	window->m_is_animated = true;
	Fl::add_timeout(/*TIMER_TIMEOUT*/ UserInterface::TIMER_TIMEOUT, timer_event, window);
}

void UserInterface::cb_btn_stop_callback(Fl_Widget* btn, void* userdata)
{
	UserInterface* window = (UserInterface*)userdata;
	window->m_is_animated = false;
	window->m_win_timer->label("stop");
}

void UserInterface::timer_event(void* userdata)
{
	UserInterface* window = (UserInterface*)userdata;
	
	if (window->m_is_animated)
	{
		++window->m_count;
		std::stringstream buffer;
		buffer << window->m_count;
		//buffer.str(); // .str() convert what's in buffer to string
		//buffer.str().c_str(); // .c_str() converts std::string to char*
		window->m_win_timer->label(buffer.str().c_str() );
		Fl::add_timeout(/*TIMER_TIMEOUT*/1.0, timer_event, window);
	}
}

