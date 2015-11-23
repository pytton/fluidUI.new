//FluidInterface.h and FluidInterface.cxx - these two files are generated by Fluid - do not modify them!
//UserInterface.h and UserInterface.cpp - these are the two main files implementing the User interface
//UserInterface class is derived from FluidInterface class
//add/remove elements in the UserInterface class constructor using delete and new

//TODO:

//add a Control class where the main program will run
//ass an Algo class which will house all the algos and be accessed by Control - this is where trading decisions are made
//add a Data class which will deal with all the data - at first loaded from a file into some structure database
//at a later point the Data class will be getting a live feed from Interactive Brokers
//connect all the classes with pointers so they know about each other's existance - possibly through just one class

//first algo to write - something very very simple like a stupid scalper without any guards


#include "UserInterface.h"

#include <iostream>

int runInterface()
{
	UserInterface * window = new UserInterface;
	//UserInterface window;
	window->show();

	return Fl::run();
}


int main()
{
	int ret = runInterface();

	std::cout << ret;

	std::cin >> ret;

	return 0;

	//UserInterface * window = new UserInterface;
	////UserInterface window;
	//window->show();

	//return Fl::run();
}