/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: FishStringer.hpp is the class specification file for the
** FishStringer class.  FishStringer is a stack container used to hold
** fish caught in the game.  Fish are pushed to the stack as string
** ascii art. Member methods defined in separate implementation file.
*********************************************************************/
#ifndef FishStringer_hpp
#define FishStringer_hpp
#include <string>
#include <cstdlib>
#include <stack>
#include <list>

class FishStringer
{
public:
	FishStringer();			// Default constructor
	~FishStringer();		// Class destructor
	void addFish();			// Add fish to stack
	void removeFish();		// Remove fish from stack
	void printStringer();	// Print stack
	bool emptyStringer();	// Check if stack empty

private:
	std::string fish;	// String for fish ascii art

	// Stack of strings
	std::stack <std::string, std::list<std::string> > myStringer, myStringerTemp;
};

#endif