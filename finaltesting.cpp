/*********************************************************************
** Program name:
** Author: Kelly Usenko
** Date:
** Description:
*********************************************************************/

#include "finaltesting.hpp"


/******************************************************************
* runTests()
*
/******************************************************************/
void runTests() {






}

void itemListTesting()
{
	int BAG_CAPACITY = 5;

	//put items in lists
	Item thing1("Shakey Elephant", true);
	Item thing2("Cracker sleeve full of ants", false);
	Item thing3("Dirty Diaper", false);
	Item thing4("Baby Bottle", true);

	//create list of items
	std::list<Item*> diaperBag;

	diaperBag.push_back(&thing1);
	diaperBag.push_back(&thing2);
	diaperBag.push_back(&thing3);
	diaperBag.push_back(&thing4);

	helpers::clearScreen();
	helpers::printPacifier();

	cout << "\nHow many items are in the diaper bag? " << diaperBag.size() << endl;

	assert(diaperBag.size() == 4);

	helpers::enterKeyToContinue();
	helpers::clearScreen();
	helpers::printPacifier();

	cout << "\nItems in the bag: " << endl;

	int itemCounter = 1;
	
	Item *tempItem;
	std::list<Item*>::iterator tempInt;

	for (auto it : diaperBag)
	{
		cout << itemCounter << ". ";
		cout << (*it).getItemDesc() << endl;

		if (itemCounter == 2)
		{
			tempItem = it;
		}
		itemCounter++;
	}

	helpers::enterKeyToContinue();
	helpers::clearScreen();
	helpers::printPacifier();

	cout << "\nremoving item 2" << endl;

	helpers::enterKeyToContinue();
	helpers::clearScreen();
	helpers::printPacifier();

	diaperBag.remove(tempItem);

	cout << "\nNow there are this many items: " << diaperBag.size() << endl;
	
	//helpers::enterKeyToContinue();

	itemCounter = 1;

	helpers::enterKeyToContinue("Printing bag contents again. Enter any key to continue.");
	helpers::clearScreen();
	helpers::printPacifier();

	for (auto it : diaperBag)
	{
		cout << itemCounter << ". ";
		cout << (*it).getItemDesc() << endl;

		if (itemCounter == 2)
		{
			tempItem = it;
		}
		itemCounter++;
	}

}





/******************************************************************
* runItemTests()
* 
/******************************************************************/
void runItemTests()
{
	//test creating items

	Item fuzzyBear("FUZZY BEAR", true);

	//cout << "Item created: " << fuzzyBear.getItemDesc() << endl;

	//cout << "Is fuzzy bear required to win? " << fuzzyBear.getRequired() << endl;

	assert(fuzzyBear.getItemDesc() == "FUZZY BEAR");
	assert(fuzzyBear.getItemDesc() != "");

	assert(fuzzyBear.getRequired() == 1);
	assert(fuzzyBear.getRequired() != 0);

	//if we get here, all testing passed!
	cout << "All item tests passed" << endl;

}



/******************************************************************
* runSpaceTests()
*
/******************************************************************/
void runSpaceTests()
{
	
	cout << "\n*****************Testing Space Classes*****************" << endl;
	//test space class
	Space * spacePtr1;
	Space * spacePtr2;

	Bathroom b1;
	Bathroom b2("Bathroom Name");

	cout << "Created Space * spacePtr, Bathroom b1, Bathroom b2(Bathroom Name)" << endl;

	cout << "b1 getSpaceName: " << b1.getSpaceName() << endl;
	cout << "b2 getSpaceName: " << b2.getSpaceName() << endl;

	spacePtr1 = &b1;
	spacePtr2 = &b2;

	//cout << "Pointer for b1 name: " << spacePtr1->getSpaceName() << endl;
	//cout << "Pointer for b2 name: " << spacePtr2->getSpaceName() << endl;

	assert(spacePtr2->getSpaceName() == "Bathroom Name");


	std::list<Space*> spaceList;
	spaceList.push_back(spacePtr1);
	spaceList.push_back(spacePtr2);

	int itemToRemove = 1;
	int counter = 1;

	for (std::list<Space*>::iterator it = spaceList.begin(); it != spaceList.end(); it++)
	{
		cout << "Space# " << counter << " ";
		cout << " " << (*it)->getSpaceName() << endl;
		counter++;
	}

	cout << "Size: " << spaceList.size() << endl;

	//cout << "Null? " << (b2.getSpaceAdjacent('u') == nullptr) << endl;
	assert((b2.getSpaceAdjacent('u') == nullptr));


	b2.setSpaceAdjacent('u', &b1);

	//cout << "Still Null? " << (b2.getSpaceAdjacent('u') == nullptr) << endl;
	assert(!(b2.getSpaceAdjacent('u') == nullptr));

}


// basic tests for all spaces
void testBasicSpaces()
{
	std::vector<Space*> spaceVector;

	Bathroom bathR("Upstairs Bathroom");
	Kidsroom kids("Baby's Room");
	Kitchen k("Kitchen");
	Mainfloor main("Main Floor");
	Mainfloor livingSpace("Living Room");
	Parentsroom parentBRoom("Parent's Room");
	Patio backyard("Backyard");
	Patio mainPatio("Main Floor Patio");
	Patio balcony("Parent's Balcony");


	spaceVector.push_back(&bathR);
	spaceVector.push_back(&kids);
	spaceVector.push_back(&k);
	spaceVector.push_back(&main);
	spaceVector.push_back(&livingSpace);
	spaceVector.push_back(&parentBRoom);
	spaceVector.push_back(&backyard);
	spaceVector.push_back(&mainPatio);
	spaceVector.push_back(&balcony);


	cout << "The following spaces exist: " << endl;

	for (auto i = spaceVector.begin(); i != spaceVector.end(); i++)
	{
		cout << (*i)->getSpaceName() << ",\n";
	}
	cout << endl;
}


//check action menus for child classes
void testSpaceMenus()
{

	Item rashCream("Rash Cream", true);

	Bathroom b("Bathroom");

	b.addItem(&rashCream);

	cout << "printing items in bathroom" << endl;

	b.printItems();

	cout << "\nPrinting Bathroom Menu" << endl;

	b.printMenu();

	b.printItems();

	cout << "have exited menu" << endl;

}



//test creation and adjustments of player attributes
void testPlayerBasics()
{
	Player p1;

	cout << "Beginning patience amount: " << p1.getPatienceAmnt() << endl;

	cout << "Is there patience left? " << p1.getHasPatienceLeft() << endl;
	
	assert(p1.getPatienceAmnt() == 50);
	assert(p1.getHasPatienceLeft() == true);

	cout << "\nremoving 10 points from patience now" << endl;

	p1.adjustPatience(-10);

	cout << "Patience amount: " << p1.getPatienceAmnt() << endl;
	assert(p1.getPatienceAmnt() == 40);

	cout << "\nAdding 20 points to patience (should not go above 50)" << endl;

	p1.adjustPatience(20);

	cout << "Patience amount: " << p1.getPatienceAmnt() << endl;
	assert(p1.getPatienceAmnt() < 51);

	cout << "Removing 70 patience points. Should not go < 0 & should flip hasPatienceLeft to 0" 
		 << endl;
	
	p1.adjustPatience(-70);
	assert(p1.getPatienceAmnt() > -1);
	assert(p1.getHasPatienceLeft() == false);

	cout << "Patience amount: " << p1.getPatienceAmnt() << endl;
	cout << "Is there patience left? " << p1.getHasPatienceLeft() << endl;

}

void testPlayerInventory()
{
	//test creating items and adding to Player Inventory
	Item * itemPtr1 = nullptr;
	Item * itemPtr2 = nullptr;

	Item thingy1("blue cup", false);
	Item thingy2("orange cup", true);

	itemPtr1 = &thingy1;
	itemPtr2 = &thingy2;

	size_t maxSize = 7;

	std::list<Item *> thingyList;

	//add to list
	thingyList.push_back(itemPtr1);
	thingyList.push_back(itemPtr2);

	cout << "ThingyList has " << thingyList.size() << " items." << endl;

	int nbr = 1;

	for (auto it = thingyList.begin(); it != thingyList.end(); it++)
	{
		cout << nbr << ". ";
		cout << (*it)->getItemDesc() << "  " << endl;
		nbr++;
	}

	int countRequired = 0; //How many required items are in our list?

	for (auto i = thingyList.begin(); i != thingyList.end(); i++)
	{
		if ((*i)->getRequired() == true)
		{
			countRequired++;
		}
	}

	cout << "Count of required items: " << countRequired << endl;
	assert(countRequired == 1);
}

//test space/player interaction
void testSpacePlayers()
{
	
	Player bob;

	Bathroom bath("Upstairs Bathroom");

	Kidsroom kRoom("Baby's Room");

	bath.setSpaceAdjacent('r', &kRoom);
	kRoom.setSpaceAdjacent('l', &bath);

	bath.setCurPlayer(&bob);

	cout << "Where can bob move to?" << endl;

	Space * tempSpace;

	tempSpace = bath.getSpaceAdjacent('r');

	cout << "tempSpace name: " << tempSpace->getSpaceName() << endl;

}

void testInventoryMenu()
{



}
//testing game class
void gameTests()
{
	Game g;

	g.beginGame();

}

void menuTests()
{
	//testing yes/no
	cout << "Testing yes/no" << endl;

	cout << "Continue? Y/N" << endl;

	cout << "response: " << helpers::getyesNo() << endl;



}


