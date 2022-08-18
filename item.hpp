/*********************************************************************
** Program name: item.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of item class
*********************************************************************/


#ifndef ITEM_HPP
#define ITEM_HPP

#include "helpers.hpp"

class Item
{
private:
	string itemDesc;
	bool required;
public:
	Item();								//default constructor
	Item(string desc, bool r);			//constructor that sets data members
	~Item();							//destructor
	string getItemDesc();
	void setItemDesc(string d);
	bool getRequired();

};

#endif

