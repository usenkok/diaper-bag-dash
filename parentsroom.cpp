
/*********************************************************************
** Program name:
** Author: Kelly Usenko
** Date: 6/12/2018
** Description:
*********************************************************************/




#include "parentsroom.hpp"

/*********************************************************************
** Parentsroom::
**
*********************************************************************/




/*********************************************************************
** Parentsroom::
**
*********************************************************************/
Parentsroom::Parentsroom()
{

	//default constructor
	this->sType = _PARENTSROOM;
	this->spaceName = "Parent's Room Default Name";
	
	this->spaceMapFileName = "parentsroom.txt";
	this->collectableMessage = "There's got to be a toy in here somewhere.. \nIs there something poking out from the closet??";

	this->collectable = false;
	this->locked = false;

	this->haveTakenNap = false;
	this->lookedUnderCovers = false;
	this->checkedCloset = false;

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;

}


/*********************************************************************
** Parentsroom::
**
*********************************************************************/
Parentsroom::Parentsroom(string pRoomName)
{

	//default constructor
	this->sType = _PARENTSROOM;
	this->spaceName = pRoomName;
	
	this->spaceMapFileName = "parentsroom.txt";
	this->collectableMessage = "There's got to be a toy in here somewhere.. \nIs there something poking out from the closet?";

	this->collectable = false;
	this->locked = false;

	this->haveTakenNap = false;
	this->lookedUnderCovers = false;
	this->checkedCloset = false;

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}



/*********************************************************************
** Parentsroom::
**
*********************************************************************/
Parentsroom::~Parentsroom()
{
	//destructor
}



/*********************************************************************
** Parentsroom::
**
*********************************************************************/
void Parentsroom::printMenu()
{
	int spaceChoice = 0;

	do {
		helpers::clearScreen();
		printSpaceMap();

		cout << "\nParent's Room Activities" << endl;
		cout << "[1] Look under covers" << endl;
		cout << "[2] Check closet" << endl;
		cout << "[3] Take a nap" << endl;
		cout << "[4] Return to previous menu" << endl;

		helpers::getValidInteger(&spaceChoice, "Choose 1-4", 0, 5);

		if (spaceChoice == 1) {
			helpers::clearScreen();
			printSpaceMap();
			lookUnderCovers();
		}
		else if (spaceChoice == 2)
		{
			helpers::clearScreen();
			printSpaceMap();
			checkCloset();
		}
		else if (spaceChoice == 3)
		{
			helpers::clearScreen();
			printSpaceMap();
			takeNap();
		}
	} while (spaceChoice != 4);

}




/*********************************************************************
** Parentsroom::
**
*********************************************************************/
void Parentsroom::takeNap()
{
	//gain 5 patience points
	//but if you try again you will lose points
	if (haveTakenNap)
	{
		cout << "\nCareful what you wish for ... taking too many naps has a negative impact on patience!" << endl;
		cout << "You've lost 5 patience points." << endl;
		curPlayer->adjustPatience(-5);
	}
	else {
		cout << "\nAhhh *big stretch* nothing like a quick nap! You gain 5 patience points." << endl;
		cout << "But be wary of too much of a good thing" << endl;
		curPlayer->adjustPatience(5);
		haveTakenNap = true;
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}


/*********************************************************************
** Parentsroom::
**
*********************************************************************/
void Parentsroom::lookUnderCovers()
{
	//what do we find?
	helpers::clearScreen();
	printCovers();

	if (lookedUnderCovers)
	{
		cout << "Haven't you had enough of this scene!?!?!" << endl;
		cout << "Get outta here you can deal with it later." << endl;
	}
	else
	{
		cout << "Oh no!!! You smell something stinky...." << endl;
		helpers::enterKeyToContinue("Hit [ENTER]");

		cout << "Your little angel has peed in your bed! You lose 10 patience points." << endl;
		this->curPlayer->adjustPatience(-10);
		lookedUnderCovers = true;
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}


/*********************************************************************
** Parentsroom::
**
*********************************************************************/
void Parentsroom::checkCloset()
{
	//what's in the closet?
	if (this->collectable)
	{
		cout << "You've already found the shakey elephant!" << endl;
	}
	else
	{
		cout << "Ah-hah! There is that elephant toy!! Now you can add it to your bag" << endl;
		this->collectable = true;
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}


/*********************************************************************
** Parentsroom::
**
*********************************************************************/
void Parentsroom::printParentsRoom()
{
	//print main parent's room scene
	string lines;
	string filename = "parentsroom.txt";
	ifstream parentsRoomFile;

	parentsRoomFile.open(filename);

	if (parentsRoomFile)

	{
		while (parentsRoomFile)
		{
			string curLine;
			getline(parentsRoomFile, curLine);
			curLine += "\n";
			lines += curLine;
		}
		cout << lines << endl;
		parentsRoomFile.close();
	}
	else
	{
		cout << "Error! Could not find file " << filename << "!" << endl;
	}
}


/*********************************************************************
** Parentsroom::
**
*********************************************************************/
void Parentsroom::printCovers()
{
	//print bed image
	string lines;
	string filename = "bed.txt";
	ifstream bedImageFile;

	bedImageFile.open(filename);

	if (bedImageFile)

	{
		while (bedImageFile)
		{
			string curLine;
			getline(bedImageFile, curLine);
			curLine += "\n";
			lines += curLine;	
		}
		cout << lines << endl;
		bedImageFile.close();
	}
	else
	{
		cout << "Error! Could not find file " << filename << endl;
	}

}
