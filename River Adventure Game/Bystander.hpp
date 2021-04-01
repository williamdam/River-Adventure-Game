/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Barbarian.hpp is the class specification file for the
** Barbarian class.  Barbarian is a derived class of the Character base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Bystander_hpp
#define Bystander_hpp
#include "Cpu.hpp"
#include <string>

class Bystander : public Cpu
{

public:
	Bystander();				// Default constructor
	~Bystander();				// Destructor

private:

};

#endif