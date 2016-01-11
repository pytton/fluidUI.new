#include "Pointers.h"

//static Pointers::myStaticPointers;


Pointers::Pointers()
{}

Pointers::Pointers(Control * c, Data * d, Display * dis)
{}

void Pointers::initPointers(Control * control, Data * data, Display * display)
{
	ptr_t_display = display;
	ptr_t_data = data;
	ptr_t_control = control;
}