/*********************************************************************
** Program name: kitchen.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Implementation of kitchen class derived class of space
*********************************************************************/

#include "kitchen.hpp"


/*********************************************************************
** Kitchen::Kitchen()
** Default constructor
*********************************************************************/
Kitchen::Kitchen()
{
	this->sType = _KITCHEN;
	this->spaceName = "Kitchen Default Name";
	
	this->spaceMapFileName = "kitchen.txt";

	this->collectable = false;
	this->locked = false;
	this->lunchMade = false;
	this->breakfastMade = false;

	this->collectableMessage = "Nothing to pack here yet. Have you made breakfast or lunch yet?";

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}

/*********************************************************************
** Kitchen::(string k)
** Constructor that sets name of room
*********************************************************************/
Kitchen::Kitchen(string k)
{
	//set name
	this->spaceName = k;
	this->sType = _KITCHEN;
	
	this->spaceMapFileName = "kitchen.txt";

	this->collectable = false;
	this->locked = false;
	this->lunchMade = false;
	this->breakfastMade = false;

	this->collectableMessage = "Nothing to pack here yet. Have you made breakfast or lunch yet?"; 

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;
}

/*********************************************************************
** Kitchen::~Kitchen()
*********************************************************************/
Kitchen::~Kitchen()
{
	//destructor
}

/*********************************************************************
** Kitchen::printMenu()
** Prints space specific menu
*********************************************************************/

void Kitchen::printMenu()
{
	//kitchen menu
	int spaceChoice = 0;

	do {
		helpers::clearScreen();
		printSpaceMap();

		cout << "\nKitchen Activities" << endl;
		cout << "[1] Make breakfast" << endl;
		cout << "[2] Make Lunch" << endl;
		cout << "[3] Feed the stray cat" << endl;
		cout << "[4] Return to previous menu" << endl;

		helpers::getValidInteger(0, &spaceChoice, "> ", 0, 5);

		if (spaceChoice == 1) {
			
			helpers::clearScreen();
			printSpaceMap();
			makeBreakfast();
		}
		else if (spaceChoice == 2)
		{
			helpers::clearScreen();
			printSpaceMap();
			makeLunch();
		}
		else if (spaceChoice == 3)
		{
			helpers::clearScreen();
			printSpaceMap();
			printCat();

		}
	} while (spaceChoice != 4);
}


/*********************************************************************
** Kitchen::printCat()
** Prints cat ascii image
*********************************************************************/
void Kitchen::printCat()
{
	cout << "\n - - - - P U R R R F E C T  C H O I C E - - - - " << endl;
	cout <<	"                   /\\_/\\ "  << endl;
	cout << "                 =( °w° )=" << endl;
	cout << "                   )   (  //" << endl;
	cout << "                  (__ __)//\n" << endl;

	cout << "\n     You've gained 5 patience points!!" << endl;
	curPlayer->adjustPatience(5);

	helpers::enterKeyToContinue("Hit [ENTER]");
}



/*********************************************************************
** Kitchen::makeLunch()
** makes lunch and half of required actions to make items collectable
*********************************************************************/
void Kitchen::makeLunch()
{
	helpers::clearScreen();
	printSpaceMap();
	
	//make lunch
	if (this->collectable)
	{
		cout << "\nYou've done everything there is to do here!" << endl;
	}
	else //either lunch or breakfast hasn't been made
	{
		if (!(this->lunchMade))
		{
			cout << "\nYou make the perfect PB&Js! \nYou can now pack it up!" << endl;
			this->lunchMade = true;

			if (lunchMade && breakfastMade)
			{
				this->collectable = true;
			}
		}
		else { //already made lunch
			cout << "\nYou already made lunch for today! Don't dilly dally! Did you skip breakfast?" << endl;
		}
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}

/*********************************************************************
** Kitchen::makeBreakfast()
** Creates breakfast which is half of what is required to unlock lunch
*********************************************************************/
void Kitchen::makeBreakfast()
{
	helpers::clearScreen();
	printSpaceMap();

	if (this->collectable)
	{
		cout << "\nYou've done everything there is to do here!" << endl;
	}
	else //either lunch or breakfast hasn't been made yet
	{
		//make breakfast
		if (!(this->breakfastMade))
		{
			cout << "\nYou throw together some peanut butter, banana, and milk in the blender. Ready to go!" << endl;
			this->breakfastMade = true;

			if (lunchMade && breakfastMade)
			{
				this->collectable = true;
			}
		}
		else { //breakfast already made
			cout << "Breakfast has already been made. What about lunch?" << endl;
		}
	}
	helpers::enterKeyToContinue("Hit [ENTER]");
}
