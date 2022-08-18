/*********************************************************************
** Program name: parentsroom.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of parentsroom class
*********************************************************************/


#ifndef PARENTSROOM_HPP
#define PARENTSROOM_HPP

#include "space.hpp"

class Parentsroom : public Space
{

private:
	bool haveTakenNap;
	bool lookedUnderCovers;
	bool checkedCloset;
	void takeNap();
	void lookUnderCovers();
	void checkCloset();

public:
	Parentsroom();
	Parentsroom(string pRoomName);
	~Parentsroom();
	virtual void printMenu();
	void printParentsRoom();
	void printCovers();
};

#endif