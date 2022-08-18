/*********************************************************************
** Program name: kidsroom.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Implementation of kidsroom class a derived class of space
*********************************************************************/


#include "kidsroom.hpp"


/*********************************************************************
** Kidsroom::Kidsroom() - Default Constructor
*********************************************************************/
Kidsroom::Kidsroom()
{
	this->sType = _KIDSROOM;
	this->spaceName = "Kids Room Default Name";
	
	this->spaceMapFileName = "kidsroom.txt";

	this->collectable = false;
	this->locked = false;

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}


/*********************************************************************
** Kidsroom::Kidsroom(string k) - constructor sets room name
*********************************************************************/
Kidsroom::Kidsroom(string k)
{
	this->sType = _KIDSROOM;
	this->spaceName = k;
	
	this->spaceMapFileName = "kidsroom.txt";

	this->collectable = false;
	this->locked = false;

	this->collectableMessage = "Nothing found in here. Did you hear that? \nIs there a noise coming from under the bed?";

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}


/*********************************************************************
** Kidsroom::~Kidsroom() - destructor
**
*********************************************************************/
Kidsroom::~Kidsroom()
{
	//destructor
}


/*********************************************************************
** Kidsroom::printMenu() - Space specific menu
*********************************************************************/
void Kidsroom::printMenu()
{
	int spaceChoice = 0;

	do {
		helpers::clearScreen();
		printSpaceMap();

		cout << "\nKid's Room Action Menu" << endl;
		cout << "[1] Search in closet" << endl;
		cout << "[2] Search under bed" << endl;
		cout << "[3] Return to previous menu" << endl;

		helpers::getValidInteger(0, &spaceChoice, "> ", 0, 4);

		if (spaceChoice == 1)
		{
			helpers::clearScreen();
			printSpaceMap();
			searchInCloset();
		}
		else if (spaceChoice == 2)
		{
			helpers::clearScreen();
			printSpaceMap();
			searchUnderBed();
		}
	} while (spaceChoice != 3 && (curPlayer->getHasPatienceLeft()));
}


/*********************************************************************
** Kidsroom::searchUnderBed() - search under bed action unlocks
** items to be collected in this room
*********************************************************************/
void Kidsroom::searchUnderBed()
{
	//under the bed
	if (this->collectable == false)
	{
		cout << "What is that!?" << endl;
		this->collectable = true;
		cout << "You pull out a stack of clean baby clothes. Return to previous menu to add them to your bag!" 
			 << endl;
	}
	else {
		cout << "You've already found the item here! Do you just like hiding under the bed? That's ok." 
			 << endl;
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}

/*********************************************************************
** Kidsroom::searchCloset() - Clothes fall out of closet and user
** loses patience points
*********************************************************************/
void Kidsroom::searchInCloset()
{
	cout << "\nAhhh!!! You opened the door an all your stacked clothes came crashing out!" << endl;
	cout << "              You've lost 10 patience points." << endl;
	if (this->curPlayer)
	{
		this->curPlayer->adjustPatience(-10);
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}