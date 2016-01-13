#include "Display.h"

Pointers Display::StaticPointers(0,0,0);





Display::Display()
{
	window = new UserInterface;// (pointers);// (pointers);// = new UserInterface;
	window->show();
}
//
//void Display::construct(Pointers pointers)
//{
//	window = new UserInterface;// (pointers);// (pointers);// = new UserInterface;
//	window->show();
//}