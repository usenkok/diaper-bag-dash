/*********************************************************************
** Program name: bathroom.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of bathroom class
*********************************************************************/


#ifndef BATHROOM_HPP
#define BATHROOM_HPP

#include "space.hpp"

class Bathroom : public Space
{
private:
	void checkMedicineCabinet();
	void bathroomArt();
public:
	Bathroom();
	Bathroom(string b);
	virtual void printMenu();
};

#endif