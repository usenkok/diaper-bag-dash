/*********************************************************************
** Program name: itemp.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of item class
*********************************************************************/

#include "item.hpp"

/*********************************************************************
** Item::Item() - Default constructor should not be used during gameplay
**
*********************************************************************/
Item::Item()
{
	itemDesc = "Default Item";
	required = false;
}

/*********************************************************************
** Item::Item(string desc, bool required)
** Item constructor that sets item description and required flag
*********************************************************************/
Item::Item(string desc, bool r)
{
	itemDesc = desc;
	required = r;
}


/*********************************************************************
** Item::~Item - Destructor
*********************************************************************/
Item::~Item()
{
	//destructor
}


/*********************************************************************
** Item::getItemDesc() - returns string describing item
*********************************************************************/
string Item::getItemDesc()
{
	return itemDesc;
}


/*********************************************************************
** Item::setItemDesc(string d) - set item description manually
*********************************************************************/
void Item::setItemDesc(string d)
{
	itemDesc = d;
}


/*********************************************************************
** Item::getRequired() - returns true/false if item is required for game
*********************************************************************/
bool Item::getRequired()
{
	return required;
}
