/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Fisherman.hpp is the class specification file for
** the Fisherman class.  This class contains data for the main player
** in the game.  Member methods defined in separate implementation file.
*********************************************************************/
#ifndef Fisherman_hpp
#define Fisherman_hpp

class Fisherman
{
public:
	Fisherman();				// Default constructor
	~Fisherman();				// Class destructor
	void setEnergy(int e);		// Set energy
	int getEnergy();			// Get energy
	void setBiteOdds(int b);	// Set bite odds
	int getBiteOdds();			// Get bite odds
	void setLandingOdds(int g);	// Set landing odds
	int getLandingOdds();		// Get landing odds

	int jig();			// Number generation respond to fish bite
	int net();			// Number generation respond to fish fight
	int defense1();		// Number generation defense

	int dieRoll(int high, int low);	// Generate random num

private:
	int energy;			// Player energy
	int biteOdds;		// Odds bias hooking a fish
	int landingOdds;	// Odds bias of landing a fish

};

#endif
