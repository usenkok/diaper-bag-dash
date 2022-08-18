/*********************************************************************
** Program name: bathroom.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Implementation of bathroom class derived class of space
*********************************************************************/

#include "bathroom.hpp"

/*********************************************************************
** Bathroom::Bathroom() - Default constructor
*********************************************************************/
Bathroom::Bathroom()
{
	this->sType = _BATHROOM;
	this->spaceName = "Bathroom Default Name";
	
	this->spaceMapFileName = "bathroom.txt";

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}


/*********************************************************************
** Bathroom::Bathroom(string b) - constructor sets name of room
*********************************************************************/
Bathroom::Bathroom(string b)
{
	this->sType = _BATHROOM;
	this->spaceName = b;
	
	this->spaceMapFileName = "bathroom.txt";

	this->collectable == false;
	this->locked == false;

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;

	this->collectableMessage = "You don't see anything in here yet.. Maybe check the medicine cabinet?";
}



/*********************************************************************
** Bathroom::printMenu() - prints space specific menu
*********************************************************************/
void Bathroom::printMenu()
{
	int spaceChoice = 0;

	do {
		helpers::clearScreen();
		this->printSpaceMap();
		
		cout << "\nBathroom Actions" << endl;
		cout << "[1] Search medicine cabinet" << endl;
		cout << "[2] Wash face" << endl;
		cout << "[3] Return to previous menu" << endl;

		helpers::getValidInteger(0, &spaceChoice, "> ", 0, 4);

		if (spaceChoice == 1) {
				checkMedicineCabinet();
		}
		else if (spaceChoice == 2)
		{
			helpers::clearScreen();
			bathroomArt();
			cout << "You are squaky clean now!" << endl;
			helpers::enterKeyToContinue("Hit [ENTER]");
		}

	} while (spaceChoice != 3);
}

/*********************************************************************
** Bathroom::checkMedicineCabinet()-searching medicine cabinet
** unlocks rash cream needed in this space
*********************************************************************/
void Bathroom::checkMedicineCabinet()
{
	//make items available to collect
	if (this->collectable == false)
	{
		helpers::clearScreen();
		bathroomArt();
		cout << "\nThere it is!" << endl;
		cout << "You found the cream and can add it to your bag now." << endl;

		helpers::enterKeyToContinue("Hit [ENTER]");
		this->collectable = true;
	}
	else {
		helpers::clearScreen();
		bathroomArt();
		cout << "\nYou've already found the rash cream in here silly!" << endl;
		helpers::enterKeyToContinue("Hit [ENTER]");
	}
}


/*********************************************************************
** Bathroom::bathroomArt() prints image below
**http://chris.com/ascii/index.php?art=animals/birds%20(water)
*********************************************************************/

void Bathroom::bathroomArt()
{

	cout << "       ..---.. " << endl;
	cout << "     .'  _    `." << endl;
	cout << " __..'  (o)    : " << endl;
	cout << "`..__          ; " << endl;
	cout << "     `.       / " << endl;
	cout << "       ;      `..---...___ " << endl;
	cout << "     .'                   `~-. .-') " << endl;
	cout << "    .                         ' _.' " << endl;
	cout << "   :                           : " << endl;
	cout << "   \\                           ' " << endl;
	cout << "    +                         J " << endl;
	cout << "     `._                   _.' " << endl;
	cout << "        `~--....___...---~' " << endl;
	cout << "\n--------------BATHROOM--------------" << endl;
}


