
/*********************************************************************
** Program name:
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: main file for Diaper Bag Dash game. hooks into Game 
** class for most functions
*********************************************************************/

/*
* Revisions
* 001 - 06/17/2018 - update so clear screen works on windows platform
* 002 - 06/17/2018 - add function to print inventory at each screen
*/

#include "helpers.hpp"
#include "finaltesting.hpp"
#include "bathroom.hpp"
#include "player.hpp"
#include "kidsroom.hpp"
#include "kitchen.hpp"
#include "mainfloor.hpp"
#include "parentsroom.hpp"
#include "patio.hpp"
#include "game.hpp"

#include <cstdio>
#include <cstdlib> //001

int main()
{
   
	//seed for random integer generation
	srand((unsigned)time(NULL));


	Game diaperBagDash;

	diaperBagDash.beginGame();


	//runItemTests();

	//itemListTesting();

	//runSpaceTests();

	//testBasicSpaces();

	//testSpaceMenus();

	//testSpacePlayers();

	//testPlayerBasics();

	//gameTests();

	//menuTests();

	//testPlayerInventory();


    return 0;
}