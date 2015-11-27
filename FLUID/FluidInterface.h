// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef FluidInterface_h
#define FluidInterface_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Table.H>

class FluidInterface {
public:
  FluidInterface();
  Fl_Double_Window *m_win_timer;
  Fl_Button *m_btn_start;
  Fl_Button *m_btn_stop;
  Fl_Slider *m_slider_one;
  Fl_Value_Input *m_value_1;
  Fl_Value_Input *m_value_2;
  Fl_Value_Input *m_value_3;
  Fl_Value_Input *m_value_5;
  Fl_Value_Input *m_value_4;
  Fl_Table *m_table;
};
#endif
