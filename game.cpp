/*********************************************************************
** Program name: game.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Implementation of game class
*********************************************************************/

/*********************************************************************
**  Image sources
** youwon.txt, title.txt made with http://www.network-science.de/ascii/
** teddy.txt from http://www.chris.com/ascii/index.php?art=animals/bears%20(teddybears)
*********************************************************************/



/*********************************************************************
** Game::
**
*********************************************************************/


#include "game.hpp"


/*********************************************************************
** Game::Game() - Default constructor initializes members and calls
**  build function to set spaces and linkages
*********************************************************************/
Game::Game()
{
	testingMode = true;
	Player gamePlayer;
	mapFile = "map.txt";
	wonFile = "youwon.txt";
	titleFile = "title.txt";
	gameOverFile = "gameover.txt";

	curSpace = nullptr;
	nextSpace = nullptr;
	prevSpace = nullptr;
	gameOver = false;
	gameWon = false;

	buildGame();
}


/*********************************************************************
** Game::~Game() - Destructor frees spaces and all items
**
*********************************************************************/
Game::~Game()
{
	//destructor
	delete bathRoomSpace;
	delete kitchenSpace;
	delete kidsBedRoom;
	delete mainSpace;
	delete livingSpace;
	delete parentsBedroom;
	delete backyard;
	delete mainPatio;
	delete parentsBalcony;

	for (auto i = allItems.begin(); i != allItems.end(); i++)
	{
		delete *i;
	}
	allItems.clear();
}

/*********************************************************************
** Game::buildGame() - creates spaces, items, places items in appropriate
** spaces and places player in bathroom to begin
*********************************************************************/
void Game::buildGame()
{
	//initialize game parameters

	/* Create Spaces */
	bathRoomSpace = new Bathroom("Bathroom");
	kidsBedRoom = new Kidsroom("Kid's Room");
	kitchenSpace = new Kitchen("Kitchen");
	mainSpace = new Mainfloor ("Main floor");
	livingSpace = new Livingroom("Living Room");
	parentsBedroom = new Parentsroom("Parent's Room");
	backyard = new Patio("Backyard");
	mainPatio = new Patio("Livingroom Patio");
	parentsBalcony = new Patio("Parent's Balcony");


	/*Create Items*/
	bathRoomItems.push_back(new Item("Rash cream", true));		//bathroom
	bathRoomItems.push_back(new Item("Dirty diaper", false));	//bathroom
	bathRoomItems.push_back(new Item("Advil", false));			//bathroom

	kidsBedRoomItems.push_back(new Item("Baby clothes", true));			//Kid's Room
	kidsBedRoomItems.push_back(new Item("Moldy sippy cup", false));		//Kid's Room
	kidsBedRoomItems.push_back(new Item("Packet of mayonnaise", false));//Kid's Room
	
	livingRoomItems.push_back(new Item("Cracker sleeve full of ants", false));	//livingroom
	livingRoomItems.push_back(new Item("Diapers", true));						//livingroom
	livingRoomItems.push_back(new Item("TV Remote", false));					//livingroom

	parentsRoomItems.push_back(new Item("Even more dirty diapers", false));	//parentsroom
	parentsRoomItems.push_back(new Item("Rain coat", false));			//parentsroom
	parentsRoomItems.push_back(new Item("Shakey Elephant", true));		//parentsroom

	kitchenItems.push_back(new Item("Lunch", true));		//kitchen
	kitchenItems.push_back(new Item("Breakfast", false));	//kitchen
	kitchenItems.push_back(new Item("Blue cup", false));	//kitchen
	kitchenItems.push_back(new Item("Orange cup", false));	//kitchen


	/* Add items to their locations */
	//bathroom
	for (auto i = bathRoomItems.begin(); i != bathRoomItems.end(); i++)
	{
		bathRoomSpace->addItem(*i);
		allItems.push_back(*i);
	} //clear list now that all are in room
	bathRoomItems.clear();

	//kids room
	for (auto i = kidsBedRoomItems.begin(); i != kidsBedRoomItems.end(); i++)
	{
		kidsBedRoom->addItem(*i);
		allItems.push_back(*i);
	} 
	kidsBedRoomItems.clear();

	//kitchen
	for (auto i = kitchenItems.begin(); i != kitchenItems.end(); i++)
	{
		kitchenSpace->addItem(*i);
		allItems.push_back(*i);
	}
	kitchenItems.clear();

	//main floor
	for (auto i = mainSpaceItems.begin(); i != mainSpaceItems.end(); i++)
	{
		mainSpace->addItem(*i);
		allItems.push_back(*i);
	}
	mainSpaceItems.clear();

	//parents room
	for (auto i = parentsRoomItems.begin(); i != parentsRoomItems.end(); i++)
	{
		parentsBedroom->addItem(*i);
		allItems.push_back(*i);
	}
	parentsRoomItems.clear();

	//living room
	for (auto i = livingRoomItems.begin(); i != livingRoomItems.end(); i++)
	{
		livingSpace->addItem(*i);
		allItems.push_back(*i);
	}
	livingRoomItems.clear();


	/* Link spaces */
	//parentsBedroom 
	parentsBedroom->setSpaceAdjacent('d', mainSpace);
	parentsBedroom->setSpaceAdjacent('r', parentsBalcony);

	//b (Bathroom)
	bathRoomSpace->setSpaceAdjacent('l', mainSpace);

	//kids (Kidsroom)
	kidsBedRoom->setSpaceAdjacent('r', mainSpace);

	//main space
	mainSpace->setSpaceAdjacent('r', bathRoomSpace);
	mainSpace->setSpaceAdjacent('l', kidsBedRoom);
	mainSpace->setSpaceAdjacent('u', parentsBedroom);
	mainSpace->setSpaceAdjacent('d', livingSpace);

	//livingSpace (Mainfloor)
	livingSpace->setSpaceAdjacent('u', mainSpace);
	livingSpace->setSpaceAdjacent('l', mainPatio);
	livingSpace->setSpaceAdjacent('d', kitchenSpace);

	//kitch (Kitchen)
	kitchenSpace->setSpaceAdjacent('u', livingSpace);
	kitchenSpace->setSpaceAdjacent('l', backyard);

	/* Put player in beginning location */
	curSpace = bathRoomSpace;
	bathRoomSpace->setCurPlayer(&p);
}


/*********************************************************************
** Game::beginGame() - outputs game beginning title, objectives sequence
** and sets stage for player
*********************************************************************/
void Game::beginGame()
{
	string indent = "          ";

	//begin game sequences
	helpers::clearScreen();
	printGameTitle();
	printObjectives();

	//begin in bathroom
	helpers::clearScreen();
	curSpace->printSpaceMap();
	cout << "\n::::::::::::::::::::::::::YAWN::::::::::::::::::::::::::\n" << endl;
	cout << indent << "You begin your day in the bathroom. " << endl;
	cout << "    There is a cream you need but ... where did you leave it?" << endl;
	cout << indent << "    Exploring can help jog your memory.\n" << endl;
	helpers::enterKeyToContinue("Continue [ENTER]");

	playGame();
}

/*********************************************************************
** Game::printGameTitle() - prints title sequence for game
*********************************************************************/
void Game::printGameTitle()
{
	//prints Diaper Bag Dash game title
	printFileText(titleFile);

	string indent = "          ";

	//print objectives for the game
	cout << "[BACKGROUND]" << endl;
	cout << indent << "You are the loving, caring parent to two wonderful children under the age of 3." << endl;
	cout << indent << "What a fun age!" << endl;
	helpers::enterKeyToContinue("Press enter...");

	cout << indent << "There's story time, playing make believe, cuddles and giggles!" << endl;
	cout << indent << "Which balance out potty training, cleaning spit-up, and changing diapers." << endl;
	helpers::enterKeyToContinue("Press enter...");

	helpers::clearScreen();
	cout << "[DILLEMMA] " << endl;
	cout << indent << "Today you have JUST REALIZED you forgot about Teddy Bear Club" << endl;
	cout << indent << indent << "AND your sitter called and is sick!" << endl;
	helpers::enterKeyToContinue("Press enter...");

	cout << indent << "It's 7:45 a.m. and you need to get out of the door ASAP!" << endl;
	helpers::enterKeyToContinue("Press enter...");

	cout << indent << "BUT your limit isn't time..." << endl;
	helpers::enterKeyToContinue("Press enter...");

	cout << indent << indent << "It's *PATIENCE*" << endl;
	helpers::enterKeyToContinue("Press enter...");

}

/*********************************************************************
** Game::printObjectives() - function to print in beginning and whenver
** player needs reminder of goals of the game
*********************************************************************/
void Game::printObjectives()
{
	string indent = "          ";
	
	helpers::clearScreen();
	
	cout << "[OBJECTIVE] " << endl;
	cout << "Your goal is to fill your diaper bag with the following 5 items " << endl; 
	cout << "     scattered throughout the house: " << endl;
	cout << indent << "[1] Rash cream " << endl;
	cout << indent << "[2] Baby Clothes " << endl;
	cout << indent << "[3] Shakey Elephant Toy" << endl;
	cout << indent << "[4] Lunch " << endl;
	cout << indent << "[5] Diapers" << endl;

	cout << "[OBSTACLES] " << endl;
	cout << indent << "Each move from room to room will subtract 1 patience point." << endl;
	cout << indent << "You will also encounter surprises as you search the house " << endl;
	cout << indent << "that may add or subtract from your patience." << endl;

	cout << "[HOW] " << endl;
	cout << indent << "Collect all the required items, and move to an outdoor (locked)" << endl;
	cout << indent << "space on the map to get on your way to Teddy Bear Club!" << endl;

	helpers::enterKeyToContinue();

}


/*********************************************************************
** Game::printMainMenu() - main driver menu for player to interact
** with spaces, actions and items in the game
*********************************************************************/
void Game::printMainMenu()
{
	cout << "What would you like to do?" << endl;
	cout << "[1] Explore Space" << endl;
	cout << "[2] Pick Up Items" << endl;
	cout << "[3] Move to new room" << endl;
	cout << "[4] Manage items in your bag" << endl;
	cout << "[5] Exit Game" << endl;
	cout << "[0] Print Objectives" << endl;

}



/*********************************************************************
** Game::playGame() - main logic for game. Loops through menu and executes
** game logic based on player choices
*********************************************************************/
void Game::playGame()
{
	int mainGameMenuChoice = 0;

	do
	{
		helpers::clearScreen();
		printStats();
		printMainMenu();

		helpers::getValidInteger(0, &mainGameMenuChoice, "> ", -1, 6);

		if (mainGameMenuChoice == 0) //print objectives (reminder)
		{
			helpers::clearScreen();
			printObjectives();
		}

		else if (mainGameMenuChoice == 1) //explore space
		{
			curSpace->printMenu();

		}
		else if (mainGameMenuChoice == 2) //pick up items
		{
			pickUpItems();

		}
		else if (mainGameMenuChoice == 3) //Move to new space
		{
			helpers::clearScreen();
			curSpace->printSpaceMap();
			movePlayer();
			p.adjustPatience(-1);
		}
		else if (mainGameMenuChoice == 4) //manage inventory
		{
			manageInventory();
	
		}
		else //choice == 5 to exit
		{
			char response;
			
			helpers::clearScreen();
			curSpace->printSpaceMap();
			cout << "\n----------- EXIT GAME -----------" << endl;
			cout << "      Are you sure? Y/N" << endl;
			if (diaperBag.size() > 0)
			{
				cout << "You have " << diaperBag.size() << " items in your Diaper Bag!" << endl;
			}
			
			response = helpers::getyesNo();

			if (response == 'N')
			{
				//reset menu choice
				mainGameMenuChoice = 0;
			}
			else
			{
				//exit and drop out of loop
			}
		}
	} while ((mainGameMenuChoice != 5) &&  p.getHasPatienceLeft() && (!gameWon));
	
	if (!(p.getHasPatienceLeft())) //patience has dropped to 0 and out of loop
	{
		printFileText(gameOverFile);

		cout << "\nYou have run out of patience!! Game over!!" << endl;
		cout << "       Better luck next time." << endl;
	}

	else if (gameWon) //player collected all the items & made it to an external space
	{
		printFileText(wonFile);
	}
	else
	{
		//player wants to exit
		cout << "Goodbye!" << endl;
	}

}


/*********************************************************************
** Game::pickUpItems() - menu & logic to check if there are items to 
** pick up. Items need to have been "collectable" (unlocked by action)
** & available (haven't been removed from room by user)
*********************************************************************/
void Game::pickUpItems()
{
	int itemToPickUp = 0;
	Item *tempItem = nullptr;

	string indentText = "          ";

	spaceType pType = curSpace->getSpaceType();

	helpers::clearScreen();
	curSpace->printSpaceMap();

	if (pType == _MAINFLOOR || pType == _PATIO) 
	{
		cout << "\nNothing to pick up in this area!" << endl;
		helpers::enterKeyToContinue("Hit [ENTER]");
	}

	else
	{
		if (diaperBag.size() == MAX_ITEMS)
		{
			cout << indentText << "You have the maximum amount of items!" << endl;
			cout << indentText << "If you think you have all the requried items, " << endl;
			cout << indentText << "try a locked exit to get out of the house!" << endl;
			cout << indentText << "Or, discard items that you may not need for the day." << endl;
			helpers::enterKeyToContinue("Hit [ENTER]");
		}
		else //less than max items
		{
			if ((curSpace->getSpaceCollectable()) && (curSpace->getAmountOfItems() == 0))
			{
				cout << indentText << "All items have been removed from this space!" << endl;
					cout << indentText << "Find them elsewhere!" << endl;
				helpers::enterKeyToContinue("Hit [ENTER]");
			}
			else //at least 1 item
			{
				curSpace->printItems(); //if not collectable, this prints the collectable hint message

				if (curSpace->getSpaceCollectable()) //items have printed out
				{
					cout << "[" << curSpace->getAmountOfItems() + 1 << "] Go back" << endl;

					helpers::getValidInteger(0, &itemToPickUp, "> ", 0, curSpace->getAmountOfItems() + 2);

					if (itemToPickUp == curSpace->getAmountOfItems() + 1)
					{
						//user chose to go back
					}
					else {	//grab that item
						tempItem = curSpace->removeItem(itemToPickUp);
						diaperBag.push_back(tempItem);
					}
				}
				else //hint has already printed, ENTER returns to menu
				{
					helpers::enterKeyToContinue("Hit [ENTER]");
				}
			}
		}

	} //carrying maximum items already
}

/*********************************************************************
** Game::manageInventory() - can view/go back or remove item
** from inventory. Items will be put in whatever the current space is
** if that space accepts items.
*********************************************************************/
void Game::manageInventory()
{
	int itemToRemoveChoice = 0;
	helpers::clearScreen();
	curSpace->printSpaceMap();

	spaceType t = curSpace->getSpaceType();

	if (t == _MAINFLOOR || t == _PATIO )
	{
		cout << "Cannot discard items in this space. Sorry!" << endl;
		helpers::enterKeyToContinue("Hit [ENTER]");
	}
	else
	{
		if (diaperBag.empty())
		{
			cout << "There are no items in your diaper bag! You can carry up to 5 items." << endl;
			helpers::enterKeyToContinue("Hit [ENTER]");
		}
		else
		{
			cout << "Which item do you want to remove from your diaper bag?" << endl;
			printBagContentsToManage();

			helpers::getValidInteger(0, &itemToRemoveChoice, "> ", 0, diaperBag.size() + 2);
		}
		if (itemToRemoveChoice == diaperBag.size() + 1)
		{
			//go back
		}
		else //remove an item
		{
			int removerCounter = 1;
			Item *tempRemoveItem = nullptr;
			for (auto it = diaperBag.begin(); it != diaperBag.end(); it++, removerCounter++)
			{
				if (removerCounter == itemToRemoveChoice)
				{
					tempRemoveItem = (*it);
				}
			}

			if (tempRemoveItem) //if not nullptr
			{
				//put in current space
				curSpace->addItem(tempRemoveItem);
				diaperBag.remove(tempRemoveItem);
				tempRemoveItem = nullptr; //free pointer
			}
		}
	}
}




/*********************************************************************
** Game::printFileText(string file) - prints file with name passed as param
*********************************************************************/
void Game::printFileText(string file)
{
	//prints map of spaces
	string lines;
	string filename = file;
	ifstream mapFile;

	mapFile.open(filename);

	if (mapFile)
	{
		while (mapFile)
		{
			string curLine;
			getline(mapFile, curLine);
			curLine += "\n";
			lines += curLine;
		}
		cout << lines << endl;
		mapFile.close();
	}
	else
	{
		cout << "Error! Could not find file " << filename << "!" << endl;
	}
}



/*********************************************************************
** Game::printStats() - prints current space map including patience
*********************************************************************/
void Game::printStats()
{
	helpers::clearScreen();
	curSpace->printSpaceMap();
	
	cout << "Diaper Bag: ";

	if (diaperBag.empty())
	{
		cout << "empty\n" << endl;
	}
	else
	{
		int itemCount = 1;

		for (auto it = diaperBag.begin(); it != diaperBag.end(); it++, itemCount++)
		{
			cout << (*it)->getItemDesc();
			if (diaperBag.size() == itemCount)
			{
				//do not display ending pipe character
			}
			else
			{   //pipe diliminate
				cout << " | ";
			}
		}
		cout << "\n" << endl;
	}


}



/*********************************************************************
** Game::printBagContentsToManage() - Print what has been collected 
**
*********************************************************************/
void Game::printBagContentsToManage()
{
	if (diaperBag.empty())
	{
		cout << "There are no items in your diaper bag!" << endl;
		cout << "You can carry up to " << MAX_ITEMS << " items." << endl;
	}
	else
	{
		int itemCount = 1;

		for (auto it = diaperBag.begin(); it != diaperBag.end(); it++, itemCount++)
		{
			cout << "[" << itemCount << "] " << (*it)->getItemDesc() << endl;
		}
		cout << "[" << itemCount << "] Go back" << endl;
	}
}




/*********************************************************************
** Game::checkGameStatus() - function called when player tries to go
** into locked room. Checks if they have all required items
*********************************************************************/
void Game::checkGameStatus()
{
	int requiredCount = 0;

	if (!p.getHasPatienceLeft())
	{
		gameOver = true;
	}
	else //player still has patience
	{
		//check if bag is full
		if (diaperBag.size() == 5) //count how many of the items are required
		{
			for (auto it = diaperBag.begin(); it != diaperBag.end(); it++)
			{
				if ((*it)->getRequired())
				{
					requiredCount++;
				}
			}
			if (requiredCount == 5) //and all items gathered are required
			{
				gameWon = true;
				gameOver = true;
			}
		}
	}//player doesn't have all required items & drops out of loop
}



/*********************************************************************
** Game::movePlayer() - use player's space choice to move them to that space
*********************************************************************/
void Game::movePlayer()
{
	//move player to chosen location
	char placeToMove = moveMenu();

	if (curSpace->getSpaceAdjacent(placeToMove)->getSpaceLocked())
	{
		if (curSpace->getSpaceAdjacent(placeToMove)->getSpaceType() == _PATIO)
		{
			checkGameStatus();
			if (gameOver) {
				//either patience has run out or player wins!!
			}
			else
			{
				helpers::clearScreen();
				curSpace->printSpaceMap();
				cout << "You want to move to " << curSpace->getSpaceAdjacent(placeToMove)->getSpaceName() << endl;
				cout << "Sorry, that area is currently locked." << endl;
				cout << "Come back when you've collected all your items!" << endl;
				helpers::enterKeyToContinue("Hit [ENTER]");
			}
		} //only patios are locked spaces
	}
	else { //move
		curSpace->setCurPlayer(nullptr);
		prevSpace = curSpace;

		curSpace = curSpace->getSpaceAdjacent(placeToMove);
		curSpace->setCurPlayer(&p);
	}
}



/*********************************************************************
** Game::moveMenu - present player with options for where they can move
*********************************************************************/

char Game::moveMenu()
{
	int tempInt = 0;
	int choice = 0;
	std::vector<Space*> tempList;
	std::map<int, char> tempMap;
	
	//menu offering available spaces to move to
	cout << "\nYour current location is " << curSpace->getSpaceName() << endl;
	cout << "Where would you like to go?" << endl;
	
	if (curSpace->getSpaceAdjacent('r'))
	{
		tempList.push_back(curSpace->getSpaceAdjacent('r'));
		tempInt++;
		tempMap.insert(std::pair<int, char>(tempInt, 'r'));
	}

	if (curSpace->getSpaceAdjacent('l'))
	{
		tempList.push_back(curSpace->getSpaceAdjacent('l'));
		tempInt++;
		tempMap.insert(std::pair<int, char>(tempInt, 'l'));
	}

	if (curSpace->getSpaceAdjacent('u'))
	{
		tempList.push_back(curSpace->getSpaceAdjacent('u'));
		tempInt++;
		tempMap.insert(std::pair<int, char>(tempInt, 'u'));
	}

	if (curSpace->getSpaceAdjacent('d'))
	{
		tempList.push_back(curSpace->getSpaceAdjacent('d'));
		tempInt++;
		tempMap.insert(std::pair<int, char>(tempInt, 'd'));
	}
	
	for (int i = 0; i < tempInt; i++)
	{
		cout << "[" << i + 1 << "] " << (tempList.at(i))->getSpaceName() << endl;
	}
	
	helpers::getValidInteger(0, &choice, "> ", 0, tempInt+1);

	//cout << tempMap.find(choice)->first << endl; //testing
	//cout << tempMap.find(choice)->second << endl; //testing
	
	return tempMap.find(choice)->second;
}

