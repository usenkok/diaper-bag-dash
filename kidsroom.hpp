/*********************************************************************
** Program name: kidsroom.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of kidsroom class
*********************************************************************/


#ifndef KIDSROOM_HPP
#define KIDSROOM_HPP

#include "space.hpp"

class Kidsroom : public Space
{
private:
	void searchUnderBed();
	void searchInCloset();

public:
	Kidsroom();
	Kidsroom(string k);
	~Kidsroom();
	virtual void printMenu();

};


#endif