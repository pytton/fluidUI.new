#include <sstream> //replaces cout
#include <string>
#include "UserInterface.h"

class Control;
Pointers UserInterface::StaticPointers(0,0,0);

extern Pointers pointers3;

UserInterface::UserInterface()	//constructor
{
	//refToPointers = pointers3;
	//add remove elements below:
	m_window1->begin();
	delete m_table;
	WidgetTable * table = new WidgetTable(350, 15, 685, 495, "widgettable");	//size and location of table

//setting up the textdisplay with textbuffer:
	textBuffer = new Fl_Text_Buffer();
	text_display->buffer(textBuffer);

//below just playing with creating new widgets outside of fluid:
//	Fl_Button* m_myExtraBtn = new Fl_Button(125, 125, 65, 40, "Extra");
	m_window1->end();
//	m_window1->show();
//creting cells inside table:
	table->ptr_to_UserInterface = this;	//tells WidgetTable the location of Userinterface - for callbacks in WidgetTable
	table->SetSize(100, 25, table);		//this needs to be called to construct all the cells of WidgetTable


	m_btn_next->callback(experimental_cb, table);
}

UserInterface::UserInterface(Pointers p)	//constructor
{
	pointers2 = &p;
	UserInterface::StaticPointers = p;
	//add remove elements below:
	m_window1->begin();
	delete m_table;
	WidgetTable * table = new WidgetTable(350, 15, 685, 495, "widgettable");	//size and location of table
	//setting up the textdisplay with textbuffer:
	textBuffer = new Fl_Text_Buffer();
	text_display->buffer(textBuffer);

	//below just playing with creating new widgets outside of fluid:
	//	Fl_Button* m_myExtraBtn = new Fl_Button(125, 125, 65, 40, "Extra");
	m_window1->end();
	
	//creting cells inside table:
	table->ptr_to_UserInterface = this;	//tells WidgetTable the location of Userinterface - for callbacks in WidgetTable
	table->SetSize(100, 25, table);		//this needs to be called to construct all the cells of WidgetTable

	m_btn_down->callback(experimental2_cb);
	m_btn_next->callback(experimental_cb, table);
}

UserInterface::UserInterface(Display*p)
{
	ptr_t_display = p;
	//add remove elements below:
	m_window1->begin();
	delete m_table;
	WidgetTable * table = new WidgetTable(350, 15, 685, 495, "widgettable");	//size and location of table

																				//setting up the textdisplay with textbuffer:
	textBuffer = new Fl_Text_Buffer();
	text_display->buffer(textBuffer);

	//below just playing with creating new widgets outside of fluid:
	//	Fl_Button* m_myExtraBtn = new Fl_Button(125, 125, 65, 40, "Extra");
	m_window1->end();
	//	m_window1->show();
	//creting cells inside table:
	table->ptr_to_UserInterface = this;	//tells WidgetTable the location of Userinterface - for callbacks in WidgetTable
	table->SetSize(100, 25, table);		//this needs to be called to construct all the cells of WidgetTable

	m_btn_down->callback(experimental2_cb, this);
	m_btn_next->callback(experimental_cb, table);
}

void UserInterface::experimental_cb(Fl_Widget *w, void * p)
{	
	WidgetTable * myTable =(WidgetTable*) p;

	std::string trythis = "mess";
	int row = 15;
	int col = 8;

	myTable->printInTable(row, col, trythis, myTable);
}

void UserInterface::experimental2_cb(Fl_Widget *w, void*p)
{
	//class Control;
	UserInterface * myUserInterface = (UserInterface*)p;

	Display * myDisplay = myUserInterface->ptr_t_display;

	

	//pointers2->ptr


	//Control * myControl = myDisplay->ptr_t_control;

	//Control  * myControl = (Control*)(UserInterface::StaticPointers.returnControlPtr());

	

	//UserInterface::StaticPointers.ptr_t_control->tryout1();

	//CANNOT GET THE ONE LINE BELOW TO WORK!!!!!!
	//myControl->tryout1();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//	pointers3.ptr_t_control->tryout1();
	
//	Pointers myPointers = (Pointers*)p;
//	UserInterface * myInterface = (UserInterface*)p;

//	Control & myControl = UserInterface::StaticPointers.ptr_t_control;

	//myControl->tryout1();

//	myControl->tryout1();

	//std::string trythis = "mess";
	//int row = 15;
	//int col = 8;

	//Control *myControl  = myInterface->pointers->ptr_t_control;

	//myControl->tryout1();

}
void UserInterface::show()
{
	//m_btn_start->callback((Fl_Callback*)cb_btn_start_callback, this);
	//m_btn_stop->callback((Fl_Callback*)cb_btn_stop_callback, this);
	m_window1->show();
	m_window2->show();
}

void WidgetTable::button_cb(Fl_Widget *w, void * p)
{
	fprintf(stderr, "BUTTON: %s\n", (const char*)w->label());



	WidgetTable * myTable = static_cast<WidgetTable*>(p);		//WidgetTable * myTable = (WidgetTable*)(p);
	UserInterface * myUserInterface = static_cast<UserInterface*>(myTable->ptr_to_UserInterface);		//UserInterface * myUserInterface = (UserInterface*)(myTable->ptr_to_UserInterface);

	int  myRow = 8, myColumn = 8;
	
	//std::stringstream buffer;


	Fl_Widget * myWidget = myTable->GetElement(myRow, myColumn);
	Fl_Input * myCell = dynamic_cast<Fl_Input*>(myWidget);

	myWidget = myTable->GetElement(myRow, myColumn);
	
	My_fl_button * myFlButton = (My_fl_button*)w;

	std::cout << std::endl << myFlButton->x_pos << std::endl;
	std::cout << myFlButton->y_pos << std::endl;

	myCell = dynamic_cast<Fl_Input*>(myWidget);

	myCell->value("try");
	myUserInterface->textDisplayString << "button pressed" << std::endl;
	myUserInterface->textBuffer->text((myUserInterface->textDisplayString).str().c_str());

	myTable->printInTable(6, 6, "text", myTable);

}

Fl_Widget * WidgetTable::GetElement(int nRow, int nCol)	//used to get a pointer to an element of WidgetTable with X Y coordinates nRow nCol
{
	int numCol = this->cols();
	int nIndex = nRow * numCol + nCol;
	return this->child(nIndex);
}

//below fills the table with objects:
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
				//below decides what is put into table:
				//r is row and c is col
				if (c != 0 && c != 1 && c != 2 && c != 3) //this used to be ( c & 1) -bitwise comparison				
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
					My_fl_button *butt = new My_fl_button(X, Y, W, H, strdup(s));
					//Fl_Light_Button *butt = new Fl_Light_Button(X, Y, W, H, strdup(s));
					butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
					butt->callback(button_cb, (void*)mytable);
					//butt->value(((r + c * 2) & 4) ? 1 : 0);	//this sets the light on or off for Fl_Light_Button
					if (c == 0) butt->label("B LMT");
					if (c == 1) butt->label("B STP");
					if (c == 2) butt->label("S LMT");
					if (c == 3) butt->label("S STP");
					butt->x_pos = c;
					butt->y_pos = r;
				}

			}
		}
	}
	end();

}

WidgetTable::WidgetTable(int x, int y, int w, int h, const char *l = 0) : Fl_Table_Row(x, y, w, h, l)
{
	table_rows, table_cols = 20;
	col_header(1);
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
		col_width_all(50);				// sets the width of the columns
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
//
//void UserInterface::printInTable(int row, int col, std::string text, UserInterface *p)//this causes trouble
//{
//	
//	UserInterface * myInterface = p;
//
//	WidgetTable * myWidgetTable = myInterface->table;
//
//	Fl_Widget * myWidget =  myWidgetTable->GetElement(row, col);
//
//	Fl_Input * myCell = dynamic_cast<Fl_Input*>(myWidget);
//
//	std::stringstream buffer;
//
//	buffer << "try";
////	myCell->value(buffer.str().c_str());
//
//	//myCell->value("try");
//
//	//Fl_Widget * myWidget = mytable->GetElement(row, col);
//	
//	
//	/*Fl_Input * myTargetCell = 
//	mytable->GetElement(row, col);*/
//	
//	
//	//Fl_Input  * targetCell = (Fl_Input*)(table->GetElement(row, col));
//	//std::stringstream buffer;
//	//buffer << text;
//
//	//targetCell->value(buffer.str().c_str());
//	//targetCell->value("400");
//}

void WidgetTable::printInTable(int row, int col, std::string text, WidgetTable * myWidgetPointer)//this causes trouble
{
	WidgetTable * myTable = myWidgetPointer;
	Fl_Widget * myWidget = (Fl_Widget*) (myTable->GetElement(row, col));
	Fl_Input * myCell = (Fl_Input*)(myWidget);
	std::stringstream buffer;
	buffer << text;
	myCell->value(buffer.str().c_str());
}
//
//void WidgetTable::printInTable(int row, int col, std::string text, UserInterface * myIntPointer)//this causes trouble
//{
//
//	UserInterface * myInterface = myIntPointer;
//
//
//	WidgetTable * myTable = myIntPointer->table;
//
//	//Fl_Widget * myWidget = myTable->GetElement(row, col);
//
//	Fl_Widget * myWidget = static_cast<Fl_Widget*> (myTable->GetVoidElement(row, col));
//
//	//Fl_Input * myCell = static_cast<Fl_Input*>(myWidget);
//
//	Fl_Input * myCell = (Fl_Input*)(myWidget);
//
//	//My_fl_button * myCell = static_cast<My_fl_button*>(myWidget);
//
//	std::stringstream buffer;
//
//	buffer << "try";
//	//myCell->value(buffer.str().c_str());
//
//	//myCell->value("try");
//
//	//Fl_Widget * myWidget = mytable->GetElement(row, col);
//
//
//	/*Fl_Input * myTargetCell =
//	mytable->GetElement(row, col);*/
//
//
//	//Fl_Input  * targetCell = (Fl_Input*)(table->GetElement(row, col));
//	//std::stringstream buffer;
//	//buffer << text;
//
//	//targetCell->value(buffer.str().c_str());
//	//targetCell->value("400");
//
//}

//const double UserInterface::TIMER_TIMEOUT = 1.0;

//Fl_Text_Buffer * UserInterface::textBuffer;
//Fl_Text_Display * UserInterface::text;

//void UserInterface::setptr()		//OLD CODE?? DO I STILL NEED THIS?
//{
//	table->ptr_to_UserInterface = this;
//}

//void UserInterface::cb_btn_start_callback(Fl_Widget* btn, void* userdata)
//{
//	UserInterface* window = (UserInterface*)userdata;
//	window->m_window1->label("start"); //set window title
//	window->m_is_animated = true;
//	Fl::add_timeout(/*TIMER_TIMEOUT*/ UserInterface::TIMER_TIMEOUT, timer_event, window);
//}

//void UserInterface::cb_btn_stop_callback(Fl_Widget* btn, void* userdata)
//{
//	UserInterface* window = (UserInterface*)userdata;
//	window->m_is_animated = false;
//	window->m_window1->label("stop");
//}

//void UserInterface::timer_event(void* userdata)
//{
//	UserInterface* window = (UserInterface*)userdata;
//	
//	if (window->m_is_animated)
//	{
//		++window->m_count;
//		std::stringstream buffer;
//		buffer << window->m_count;
//		//buffer.str(); // .str() convert what's in buffer to string
//		//buffer.str().c_str(); // .c_str() converts std::string to char*
//		window->m_window1->label(buffer.str().c_str() );
//		Fl::add_timeout(/*TIMER_TIMEOUT*/1.0, timer_event, window);
//	}
//}
