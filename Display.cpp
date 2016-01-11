#include "Display.h"

Pointers Display::StaticPointers(0,0,0);

int Display::mystaticint(0);



Display::Display()
{
	window = new UserInterface;
	//window->show();
}