#ifndef _UserInterface_H_INCLUDED_
#define _UserInterface_H_INCLUDED_

#include "FLUID/CFluidTimerUI.h"

//const double TIMER_TIMEOUT = 1.0; // 1 sec

class UserInterface : public CFluidTimerUI
{
	static const double TIMER_TIMEOUT;// = 1.0;
	bool m_is_animated;
	int m_count;
public:
	//constructors/destructor
	UserInterface();
	void show();
	//callback functions
	static void cb_btn_start_callback(Fl_Widget* btn, void* userdata);
	static void cb_btn_stop_callback(Fl_Widget* btn, void* userdata);
	static void timer_event(void* userdata);
};


#endif //_UserInterface_H_INCLUDED_