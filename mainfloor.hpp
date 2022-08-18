/*********************************************************************
* Program name: mainfloor.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of mainfloor class
*********************************************************************/

#ifndef MAINFLOOR_HPP
#define MAINFLOOR_HPP

#include "space.hpp"


class Mainfloor : public Space
{
private:
	void dillydally();

public:
	Mainfloor();
	Mainfloor(string m);
	~Mainfloor();
	virtual void printMenu();

};
#endif