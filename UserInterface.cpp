#include <sstream> //replaces cout
#include <string>
#include "UserInterface.h"

const double UserInterface::TIMER_TIMEOUT = 1.0;

//Fl_Text_Buffer * UserInterface::textBuffer;
//Fl_Text_Display * UserInterface::text;

UserInterface::UserInterface()	//constructor
{
	
	m_is_animated = false;	m_count = 0;	//used by youtube functions for timeout demo
	
	//m_value_1->value(1);	//setting the 5 input window values
	//m_value_2->value(1);
	//m_value_3->value(1);
	//m_value_4->value(1);
	//m_value_5->value(1);

	//m_value_1->label("Enter value:");
	//m_value_2->label("Row:");
	//m_value_3->label("Column:");

	//add remove elements below:
	m_win_timer->begin();
	delete m_table;
	WidgetTable * table = new WidgetTable(350, 15, 685, 495, "widgettable");	//size and location of table

//setting up the textdisplay with textbuffer:
	textBuffer = new Fl_Text_Buffer();
	//text = new Fl_Text_Display(205, 210, 475, 160, "text");
	text_display->buffer(textBuffer);



//below just playing with creating new widgets outside of fluid:
//	Fl_Button* m_myExtraBtn = new Fl_Button(125, 125, 65, 40, "Extra");
	m_win_timer->end();

//creting cells inside table:
	table->ptr_to_UserInterface = this;	//tells WidgetTable the location of Userinterface - for callbacks in WidgetTable
	table->SetSize(100, 25, table);		//this needs to be called to construct all the cells of WidgetTable
}

//void UserInterface::setptr()		//OLD CODE?? DO I STILL NEED THIS?
//{
//	table->ptr_to_UserInterface = this;
//}

void UserInterface::show()
{
	//m_btn_start->callback((Fl_Callback*)cb_btn_start_callback, this);
	//m_btn_stop->callback((Fl_Callback*)cb_btn_stop_callback, this);
	m_win_timer->show();
	window2->show();
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

WidgetTable::WidgetTable(int x, int y, int w, int h, const char *l = 0) : Fl_Table_Row(x, y, w, h, l)
{
	
	table_rows, table_cols = 20;
	col_header(0);
	col_resize(0);
	col_header_height(20);

	row_header(0);
	row_resize(0);
	row_header_width(30);
	end();
}

void WidgetTable::draw_cell(TableContext context,
	int R, int C, int X, int Y, int W, int H)
{
	switch (context)
	{
	case CONTEXT_STARTPAGE:
		fl_font(FL_HELVETICA, 12);		// font used by all headers
		col_width_all(40);				// sets the width of the columns
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

void WidgetTable::button_cb(Fl_Widget *w, void * p)
{
	fprintf(stderr, "BUTTON: %s\n", (const char*)w->label());
	//Fl_Light_Button * pBtn = dynamic_cast<Fl_Light_Button*> (w);
	
	WidgetTable * myTable = static_cast<WidgetTable*>(p);		//WidgetTable * myTable = (WidgetTable*)(p);
	UserInterface * myUserInterface = static_cast<UserInterface*>(myTable->ptr_to_UserInterface);		//UserInterface * myUserInterface = (UserInterface*)(myTable->ptr_to_UserInterface);

	int  myRow = 0, myColumn = 0;
//	double myValue = myUserInterface->m_value_1->value();

//	myRow = (int)myUserInterface->m_value_2->value();
//	myColumn = (int)myUserInterface->m_value_3->value();
	
	std::stringstream buffer;
	//buffer << myValue;

	Fl_Widget * myWidget = myTable->GetElement(myRow, myColumn);
	Fl_Input * myCell = dynamic_cast<Fl_Input*>(myWidget);

	myWidget = myTable->GetElement(myRow, myColumn);
		
	myCell = dynamic_cast<Fl_Input*>(myWidget);
	myCell->value(buffer.str().c_str());

	myUserInterface->textDisplayString << "button pressed" << std::endl;
	myUserInterface->textBuffer->text((myUserInterface->textDisplayString).str().c_str());
		//text->buffer(myInterface->textBuffer);	
	//myUserInterface->textBuffer->text("callback run\n");	//pushing text to textBuffer to display in fl_text_Display
}

Fl_Widget * WidgetTable::GetElement(int nRow, int nCol)	//used to get a pointer to an element of WidgetTable with X Y coordinates nRow nCol
{
	int numCol = this->cols();
	int nIndex = nRow * numCol + nCol;
	return this->child(nIndex);
}

void WidgetTable::SetSize(int newrows, int newcols, WidgetTable * mytable)
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
				if (1/*c != 0*/) //this used to be ( c & 1) -bitwise comparison
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
					butt->callback(button_cb, (void*)mytable);
					butt->value(((r + c * 2) & 4) ? 1 : 0);
				}
			}
		}
	}
	end();

}