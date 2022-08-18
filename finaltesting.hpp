/*********************************************************************
** Program name: finaltesting.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: File to run functional tests on various components of classes
*********************************************************************/

#ifndef FINALTESETING_HPP
#define FINALTESETING_HPP

//#include "space.hpp"
#include "bathroom.hpp"
#include "player.hpp"
#include "kidsroom.hpp"
#include "kitchen.hpp"
#include "mainfloor.hpp"
#include "parentsroom.hpp"
#include "patio.hpp"
#include "game.hpp"

void runTests();	//generic function to run tests in from Main

void itemListTesting();

void runItemTests();	//function to test item class

void runSpaceTests();	//function to test space class

void testBasicSpaces();

void testSpaceMenus();	//test space action menus

void testPlayerBasics();

void testPlayerInventory();

void testSpacePlayers();

void testInventoryMenu();

void gameTests();

void menuTests();

#endif