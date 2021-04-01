/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: BaitShop.hpp is the specification file for the
** BaitShop class.  BaitShop is an inherited class of the Space class.
** Member functions defined in separate implementation file, BaitShop.cpp.
*********************************************************************/
#ifndef BaitShop_hpp
#define BaitShop_hpp
#include "Space.hpp"

class BaitShop: public Space
{
public:
	BaitShop();			// Default constructor
	~BaitShop();		// Class destructor
	void spaceIntro();	// Space intro

private:

};

#endif
