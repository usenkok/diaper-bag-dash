/*********************************************************************
** Program name: livingroom.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: implementation of livingroom class child of space
*********************************************************************/

#include "livingroom.hpp"


/*********************************************************************
** Livingroom::Livingroom() - Default constructor
*********************************************************************/
Livingroom::Livingroom()
{
	//default constructor

	//set name
	this->spaceName = "Default Livingroom Name";
	this->sType = _LIVINGROOM;

	this->spaceMapFileName = "livingroom.txt";

	this->collectable = false;
	this->locked = false;

	this->collectableMessage = "You can never really have enough... where are those extra nappies?";

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}


/*********************************************************************
** Livingroom::Livingroom(string l) - Constructor sets name of room
*********************************************************************/
Livingroom::Livingroom(string l)
{
	//set name
	this->spaceName = l;
	this->sType = _LIVINGROOM;

	this->spaceMapFileName = "livingroom.txt";

	this->collectable = false;
	this->locked = false;

	this->collectableMessage = "You can never really have enough... where are those extra nappies?";

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}



/*********************************************************************
** Livingroom::~Livingroom() - Destructor
*********************************************************************/
Livingroom::~Livingroom()
{
	//destructor
}


/*********************************************************************
** Livingroom::printMenu() - Space specific menu
*********************************************************************/
void Livingroom::printMenu()
{
	//Livingroom menu
	int spaceChoice = 0;

	do {
		helpers::clearScreen();
		printSpaceMap();

		cout << "\nLivingroom Activities" << endl;
		cout << "[1] Look around the corner" << endl;
		cout << "[2] Check the couch cushions" << endl;
		cout << "[3] Return to previous menu" << endl;

		helpers::getValidInteger(0, &spaceChoice, "> ", 0, 4);

		if (spaceChoice == 1) {

			helpers::clearScreen();
			printSpaceMap();
			lookAroundCorner();
		}
		else if (spaceChoice == 2)
		{
			helpers::clearScreen();
			printSpaceMap();
			checkCouchCushions();
		}
		else 
		{
			//return to previous menu
		}
	} while (spaceChoice != 3);
}

/*********************************************************************
** Livingroom::lookAroundCorner() - action triggers random events that may
** add or remove from patience
*********************************************************************/
void Livingroom::lookAroundCorner()
{
	//gamble: can be either positive or negative
	int randEvent = helpers::generateRandomNumber(1, 100);

	if (randEvent < 46) //negative event
	{
		cout << "\nYour child finds the TV remote and chases you around DEMANDING to watch!" << endl;
		cout << "Why has society made you feel so bad about screen time?!!!?" << endl;
		cout << "\nYou lose 10 patience points" << endl;

		this->curPlayer->adjustPatience(-10);
	}

	else if (randEvent > 55)
	{
		cout << "\nOh look! Your toddler is playing nicely with their sibling." << endl;
		cout << "**sigh of relief**" << endl;
		cout << "You gain 10 patience points." << endl;

		this->curPlayer->adjustPatience(10);
	}
	else //10% chance of no event
	{
		cout << "Hmm .. nothing going on over here." << endl;

	}

	helpers::enterKeyToContinue("Hit [ENTER]");
}


/*********************************************************************
** Livingroom::checkCouchCusions() - action that allows diapers to be
** collectable
*********************************************************************/
void Livingroom::checkCouchCushions()
{
	if (this->collectable == true)
	{
		cout << "you've already found the diapers!" << endl;
	}
	else { //haven't unlocked yet
		cout << "Dig ... Dig ... Dig ..." << endl;
		helpers::enterKeyToContinue("Hit [ENTER]");
		cout << "\nWhat's that!? Is something in there? Dig deeper" << endl;
		helpers::enterKeyToContinue("Hit [ENTER]");

		cout << "VOILA!!! YESSS MORE DIAPERS! JUST WHAT YOU NEEDED!" << endl;
		this->collectable = true;
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}