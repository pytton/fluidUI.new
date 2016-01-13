#include "Display.h"

Pointers Display::StaticPointers(0,0,0);





Display::Display()
{
	Display::StaticPointers;
	
	window = new UserInterface;// (pointers);// (pointers);// = new UserInterface;
	//window->show();
}

void Display::construct(Pointers pointers)
{
	delete window;
	//window = new UserInterface(Display::StaticPointers);// (pointers);// (pointers);// = new UserInterface;
	window = new UserInterface(this);
	window->show();
}