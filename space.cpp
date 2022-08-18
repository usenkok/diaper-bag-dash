/*********************************************************************
** Program name: space.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Implementation of abstract parent space class
*********************************************************************/

#include "space.hpp"


/*********************************************************************
** Space::Space() - Default constructor
*********************************************************************/
Space::Space()
{
	//default constructor
	this->sType = NOT_SET;
	this->spaceName = "abstract space";
	this->spaceMapFileName = "";

	this->collectable = false;
	this->locked = false;

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;

}


/*********************************************************************
** Space::(string n, spaceType t) - Constructor that sets name
*********************************************************************/
Space::Space(string n)
{
	//constructor to set attributes
	this->spaceName = n;
	this->sType = NOT_SET;
	this->curPlayer = nullptr;
	this->spaceMapFileName = "";

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;

}


/*********************************************************************
** Space::~Space() - Destructor
*********************************************************************/
Space::~Space()
{
	//destructor
}


/*********************************************************************
** Space::setSpaceName(string n) - sets name
*********************************************************************/
void Space::setSpaceName(string n)
{
	this->spaceName = n;
}



/*********************************************************************
** Space::getSpaceName() - returns name
*********************************************************************/
string Space::getSpaceName()
{
	return this->spaceName;
}



/*********************************************************************
** Space::getSpaceType - returns space type
*********************************************************************/
spaceType Space::getSpaceType()
{
	return this->sType;
}


/*********************************************************************
** Space::setSpaceAdjacent(char dir, space * s) - assigns up, down,
** left, or right linked space based on arguments passed
*********************************************************************/
void Space::setSpaceAdjacent(char dir, Space * s)
{
	if (dir == 'l')
	{
		this->left = s;
	}
	else if (dir == 'r')
	{
		this->right = s;
	}
	else if (dir == 'd')
	{
		this->down = s;
	}
	else if (dir == 'u')
	{
		this->up = s;
	}
	else {
		//invalid character sent
	}
}


/*********************************************************************
** Space::getSpaceAdjacent(char dirGet) - returns pointer to space
** that occupies the provided adjacent direction in argument
*********************************************************************/
Space * Space::getSpaceAdjacent(char dirGet)
{

	if (dirGet == 'l')
	{
		return this->left;
	}
	else if (dirGet == 'r')
	{
		return this->right;
	}
	else if (dirGet == 'd')
	{
		return this->down;
	}
	else if (dirGet == 'u')
	{
		return this->up;
	}
	else {
		//invalid character sent
		return nullptr;
	}

}


/*********************************************************************
** Space::setCurPlayer(Player * p) - assign player to space
*********************************************************************/
void Space::setCurPlayer(Player * p)
{
	this->curPlayer = p;
}


/*********************************************************************
** Space::getCurPlayer()-returns player pointer
*********************************************************************/
Player * Space::getCurPlayer()
{
	return this->curPlayer;
}



/*********************************************************************
** Space::getSpaceLocked() - returns if space is locked
*********************************************************************/
bool Space::getSpaceLocked()
{
	return this->locked;
	
}



/*********************************************************************
** Space::getSpaceCollectable() - returns whether items can be collected yet
*********************************************************************/
bool Space::getSpaceCollectable()
{
	return this->collectable;
}



/*********************************************************************
** Space::printSpaceMap() - prints map from text file
*********************************************************************/
void Space::printSpaceMap()
{
	string lines;
	ifstream spaceFile;

	spaceFile.open(this->spaceMapFileName);

	if (spaceFile)

	{
		while (spaceFile)
		{
			string curLine;
			getline(spaceFile, curLine);
			curLine += "\n";
			lines += curLine;
		}
		cout << lines << endl;
		spaceFile.close();
	}
	else
	{
		cout << "Error! Could not find file " << this->spaceMapFileName << "!" << endl;
	}

	cout << "         ***** PATIENCE: " << curPlayer->getPatienceAmnt();
	cout << " | LOCATION: " << spaceName << " *****\n" << endl;
}


/*********************************************************************
** Space::printItems()-prints items available in space
*********************************************************************/
void Space::printItems()
{
	//check collectable flag
	if (this->collectable == false)
	{
		cout << this->collectableMessage << endl;
	}
	else
	{
		if (!availableItems.empty())
		{
			cout << "Available Items" << endl;
			int counter = 1;
			for (auto it = availableItems.begin(); it != availableItems.end(); it++, counter++)
			{
				cout << "[" << counter << "] " << (*it)->getItemDesc() << endl;
			}
		}
	}

}

/*********************************************************************
** Space::getAmountOfItems()-returns how many items available
*********************************************************************/
int Space::getAmountOfItems()
{
	return availableItems.size();
}



/*********************************************************************
** Space::removeItem(int i)-removes item from space list and returns
** poitner to the item that was removed
*********************************************************************/
Item* Space::removeItem(int i)
{
	//remove item at index i from list
	unsigned counter = 1;
	Item *toRemove = nullptr;

	for (auto it = availableItems.begin(); it != availableItems.end(); it++, counter++)
	{
		if (counter == i)
		{
			toRemove = (*it);
		}
	}
	availableItems.remove(toRemove);

	return toRemove;
}



/*********************************************************************
** Space::addItem(Item* a) - accepts pointer to item it will add to list
*********************************************************************/
void Space::addItem(Item* a)
{
	availableItems.push_back(a);
}