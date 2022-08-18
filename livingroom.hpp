/*********************************************************************
** Program name: livingroom.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: definition of living room class
*********************************************************************/

#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP

#include "space.hpp"

class Livingroom : public Space
{
private:
	void lookAroundCorner();
	void checkCouchCushions();

public:
	Livingroom();
	Livingroom(string l);
	~Livingroom();
	virtual void printMenu();
};

#endif
