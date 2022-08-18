/*********************************************************************
** Program name: mainfloor.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Implementation of mainfloor class a derived class of space
*********************************************************************/


#include "mainfloor.hpp"


/*********************************************************************
** Mainfloor::Mainfloor() - default constructor
*********************************************************************/
Mainfloor::Mainfloor()
{
	this->sType = _MAINFLOOR;
	this->spaceName = "Main Floor Default Name";
	this->spaceMapFileName = "MainFloor.txt";
	this->collectable = false;
	this->locked = false;

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}

/*********************************************************************
** Mainfloor::Mainfloor(string m) - Constructor that sets room name
*********************************************************************/

Mainfloor::Mainfloor(string m)
{
	this->spaceName = m;
	this->sType = _MAINFLOOR;

	this->collectableMessage = "There is nothing to collect on the main floor. Carry on!";
	this->spaceMapFileName = "MainFloor.txt";

	this->collectable = false;
	this->locked = false;

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}



/*********************************************************************
** Mainfloor::~Mainfloor() - Destructor
*********************************************************************/
Mainfloor::~Mainfloor()
{
	//destructor
}



/*********************************************************************
** Mainfloor::printMenu() - space specific menu
*********************************************************************/

void Mainfloor::printMenu()
{
	//print mainfloor menu
	int spaceChoice = 0;

	do {
		helpers::clearScreen();
		printSpaceMap();

		cout << "\nMain Floor" << endl;
		cout << "There are no things to collect on this floor. Dilly dallying is risky." << endl;
		cout << "        You should move along!" << endl;
		cout << "[1] Dilly Dally" << endl;
		cout << "[2] Return to previous menu" << endl;

		helpers::getValidInteger(0, &spaceChoice, "> ", 0, 3);

		if (spaceChoice == 1) {
			helpers::clearScreen();
			printSpaceMap();
			dillydally();
		}
		else {
			//return to other menu
		}
	} while (spaceChoice != 2);
}



/*********************************************************************
** Mainfloor::dillydally()-Function that wastes time and removes a point
*********************************************************************/
void Mainfloor::dillydally()
{
	cout << "Dilly dallying stresses you out! You've lost 1 patience point" << endl;
	curPlayer->adjustPatience(-1);
	helpers::enterKeyToContinue("Hit [ENTER]");
}


