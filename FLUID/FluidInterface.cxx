// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "FluidInterface.h"

FluidInterface::FluidInterface() {
  { m_window1 = new Fl_Double_Window(1051, 536, "window1");
    m_window1->user_data((void*)(this));
    { m_btn_load_data = new Fl_Button(10, 295, 75, 55, "Load historical data");
      m_btn_load_data->align(Fl_Align(FL_ALIGN_WRAP));
    } // Fl_Button* m_btn_load_data
    { m_slider_one = new Fl_Slider(285, 15, 35, 490, "mySlider");
      m_slider_one->type(4);
      m_slider_one->minimum(10);
      m_slider_one->maximum(200);
    } // Fl_Slider* m_slider_one
    { m_starting_bid = new Fl_Value_Input(130, 15, 45, 20, "Starting Bid");
    } // Fl_Value_Input* m_starting_bid
    { m_curr_ask = new Fl_Value_Input(130, 40, 45, 20, "Current Ask");
    } // Fl_Value_Input* m_curr_ask
    { m_top_limit = new Fl_Value_Input(130, 90, 45, 20, "Top Limit");
    } // Fl_Value_Input* m_top_limit
    { m_top_profit = new Fl_Value_Input(130, 140, 45, 20, "Profit at top lim");
    } // Fl_Value_Input* m_top_profit
    { m_table = new Fl_Table(350, 15, 685, 495);
      m_table->end();
    } // Fl_Table* m_table
    { m_curr_bid = new Fl_Value_Input(130, 65, 45, 20, "Current Bid");
    } // Fl_Value_Input* m_curr_bid
    { m_bottom_limit = new Fl_Value_Input(130, 115, 45, 20, "Bottom Limit");
    } // Fl_Value_Input* m_bottom_limit
    { m_bottom_profit = new Fl_Value_Input(130, 165, 45, 20, "Profit at bottom lim");
    } // Fl_Value_Input* m_bottom_profit
    { m_btn_up = new Fl_Button(200, 15, 65, 40, "Up");
    } // Fl_Button* m_btn_up
    { m_btn_down = new Fl_Button(200, 70, 65, 40, "Down");
    } // Fl_Button* m_btn_down
    { m_btn_next = new Fl_Button(105, 295, 80, 55, "Next");
    } // Fl_Button* m_btn_next
    { m_btn_initAlgo = new Fl_Button(10, 360, 80, 55, "Initialize Algo");
      m_btn_initAlgo->align(Fl_Align(FL_ALIGN_WRAP));
    } // Fl_Button* m_btn_initAlgo
    { m_set_startBid = new Fl_Button(5, 15, 40, 20, "Set");
    } // Fl_Button* m_set_startBid
    { m_set_topLimit = new Fl_Button(5, 90, 40, 20, "Set");
    } // Fl_Button* m_set_topLimit
    { m_set_btmLimit = new Fl_Button(5, 115, 40, 20, "Set");
    } // Fl_Button* m_set_btmLimit
    m_window1->end();
  } // Fl_Double_Window* m_window1
  { m_window2 = new Fl_Double_Window(246, 282, "window2");
    m_window2->user_data((void*)(this));
    { text_display = new Fl_Text_Display(25, 25, 225, 255, "text");
    } // Fl_Text_Display* text_display
    m_window2->end();
  } // Fl_Double_Window* m_window2
}
