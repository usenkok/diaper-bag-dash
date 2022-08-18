/*********************************************************************
** Program name: space.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of parent space class
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "helpers.hpp"
#include "item.hpp"
#include "player.hpp"

enum spaceType { NOT_SET, _BATHROOM, _KIDSROOM, _KITCHEN, _LIVINGROOM, _MAINFLOOR, _PARENTSROOM, _PATIO};

class Space {

protected:
	string spaceName;					//Description of space in home
	spaceType sType;					//Type of space/room
	string spaceMapFileName;			//name of file to print space specific map
	Player * curPlayer;					//Player object for occupant of space. nullptr if space unoccupied
	bool collectable;					//flag to indicate if items in space can be collected
	bool locked;						//flag to indicate if room is locked or can be entered
	string collectableMessage;			//text that displays when room items are not yet collectable
	std::list<Item*> availableItems;	//List container of items available within space
	Space * left;						//pointer to space to the left of current space
	Space * right;						//pointer to space to the right of current space
	Space * down;						//pointer to space below current space
	Space * up;							//pointer to space above current space
	
public:
	Space();
	Space(string n);
	virtual ~Space();
	void setSpaceName(string n);
	string getSpaceName();
	spaceType getSpaceType();
	void setSpaceAdjacent(char dir, Space* s);
	Space * getSpaceAdjacent(char dirGet);
	void setCurPlayer(Player* p);
	Player* getCurPlayer();
	virtual bool getSpaceLocked();
	virtual bool getSpaceCollectable();
	virtual void printMenu() = 0;
	virtual void printSpaceMap();
	void printItems();
	int getAmountOfItems();
	Item* removeItem(int i);
	void addItem(Item* a);
};

#endif
