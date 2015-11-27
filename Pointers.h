#ifndef _POINTERS_H_INCLUDED_
#define _POINTERS_H_INCLUDED_
//this class stores pointers to all elements of the application - for easy access

class Pointers
{
public:
	void * ptr_t_UserInterface;	//main window of userinterface
	void set_ptr_t_UserInterface(void * pointer)
	{
		ptr_t_UserInterface = pointer;
	}
	void * get_ptr_t_UserInterface()
	{
		return ptr_t_UserInterface;
	}

	void * ptr_t_


};



#endif // !_POINTERS_H_INCLUDED_

