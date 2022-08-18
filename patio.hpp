/*********************************************************************
** Program name: patio.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of patio class
*********************************************************************/


#ifndef PATIO_HPP
#define PATIO_HPP

#include "space.hpp"

class Patio : public Space
{
private:

public:
	Patio();
	Patio(string pName);
	~Patio();
	virtual void printMenu();
};

#endif
