//This is where I want to start developing
//
//What do I want??????
//
//Create a window
// that window has buttons and a fl_table or fl_output
//window has buttons
//callback functions for buttons - they will always call a member function of one class.
//what class? maybe a 'control' class?

//buttons - one for price up, one for price down
//another buttons for price up/down five times
//slider or that other 'infinite slider' next to buttons - to control up/down price movement

//callbacks send directions to control class

//control class might have something like a 'main loop'????

//decide where to keep all data - current orders, filled orders, current positions, algo decisions - what else?
//keep prices as int!!! always in cents. not floats or doubles
//that old idea:
//check current bid/ask
//check orders for fills
//send all information to algo
//algo pull information from where it needs it
//algo make decisions
//algo make orders
//
// go back to check current bid/ask
//

//learn that fl_table - have results displayed in it

// for starters - just make a super simple scalper algo
// presume price moves between 200 and 240 cents
// when bid goes above 210 - issue order to join bid at 210
// wait until order is filled
// when order filled, issue order to sell at 215
// when sell order for 215 is filled, issue order to buy at 210. store the profit somewhere

//or a different idea - no algo yet
//just live or saved feed of data and simple buy/sell - showing P/L as price changes