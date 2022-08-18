/*********************************************************************
** Program name: kitchen.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of kitchen class
*********************************************************************/

#ifndef KITCHEN_HPP

#define KITCHEN_HPP
#include "space.hpp"

class Kitchen : public Space
{
private:
	bool breakfastMade;
	bool lunchMade;
	void makeLunch();
	void makeBreakfast();

public:
	Kitchen();
	Kitchen(string k);
	~Kitchen();
	virtual void printMenu();
	void printCat();
};

#endif