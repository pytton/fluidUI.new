// This is one of the first FLTK projects that I learned about






// In Project Properties add the following:
// Configuration Properties/ VC++ Directories/Include Directories:
// C:\code\fltkPractice\fltk-1.3.3
// Configuration Properties/ VC++ Directories/Library Directories:
// C:\code\fltkPractice\fltk-1.3.3\lib
//

//	C/C++ Preprocessor definitions:
//WIN32
//_DEBUG
//_WINDOWS
//
//

// Linker/Input/Additional Dependencies:
//fltkd.lib
//wsock32.lib
//comctl32.lib
//fltkjpegd.lib
//fltkimagesd.lib
//
// In the above - 'd' stands for debug. So fltkd.lib is debug version. release version without the 'd'
//

#include "stdio.h"
#include <conio.h>
#include <iostream>

#include "FL/Fl.h"
#include "FL/Fl_Window.h"
#include "FL/Fl_Button.h"
#include "FL/Fl_Output.h"

struct Price {
	int bid;
	int ask;
	int bidVolume;
	int askVolume;

	Price()
	{
		bidVolume = 0;
		askVolume = 0;
	}
};

void OnStartClick(Fl_Widget * button, void * pVoid)
{
	Price * pPrice = (Price *)pVoid;

	//std::cout << pPrice->ask << " " << button->label() <<std::endl;

	std::string strLbl = button->label();

	//const char * strLbl = button->label();
	//int nSize = strlen(strLbl);

	(pPrice->bid);

	Fl_Button *pButton = (Fl_Button *)button;	// all FLTK objects are derived from class Fl_Widget.
												// here, we are casting the pointer button of type Fl_Widget to 
												// a pointer of class Fl_Button
												// button was pointing to the button that calls this function
												/*
												if (strcmp(pButton->label(),"Clicked") == 0)
												{
												pButton->label("again");
												}
												else
												{
												pButton->label("Clicked");
												}
												*/

	pButton->label("mine!");
}

void OnUpClick(Fl_Widget * button, void * pVoid)
{
	Fl_Output * pOutput = (Fl_Output *)pVoid;

	//std::cout << pPrice->ask << " " << button->label() <<std::endl;

	pOutput->label("Up Clicked");

	pOutput->value("500");

	Fl_Button *pButton = (Fl_Button *)button;

	if (strcmp(pButton->label(), "Clicked Up") == 0)
	{
		(*pButton).label("again Up");
	}
	else
	{
		pButton->label("Clicked Up");
	}

}

int main()
{

	Price myPrice;
	myPrice.bid = 45;
	myPrice.ask = 46;

	int a = 50;

	Fl_Window win(1200, 900, "Michael Window");

	///////////////////////////////////////////////////////
	//Window Construction

	win.begin();

	Fl_Button upBtn(200, 10, 100, 20, "Up");
	Fl_Button startBtn(10, 30, 100, 20, "Start");
	Fl_Button stopBtn(400, 30, 100, 20, "Stop");
	Fl_Button downBtn(200, 50, 100, 20, "Down");

	Fl_Output output(200, 100, 100, 20, "Output");

	win.end();
	/////////////////////////////////////////////////

	startBtn.callback(OnStartClick, &myPrice);
	upBtn.callback(OnUpClick, &output);
	stopBtn.callback(OnStartClick, &myPrice);
	downBtn.callback(OnStartClick, &myPrice);

	win.show();

	Fl::run();

	++a;
}