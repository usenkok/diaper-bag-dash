/*********************************************************************
** Program name: game.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Definition of game class
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "bathroom.hpp"
#include "kidsroom.hpp"
#include "kitchen.hpp"
#include "livingroom.hpp"
#include "mainfloor.hpp"
#include "parentsroom.hpp"
#include "patio.hpp"

class Game {
private:
	bool testingMode;
	Player p;
	const int MAX_ITEMS = 5;
	std::list<Item*> diaperBag;
	std::list<Item*> allItems;
	string mapFile;
	string wonFile;
	string titleFile;
	string gameOverFile;
	
	Space *bathRoomSpace;
	Space *kitchenSpace;
	Space *kidsBedRoom;
	Space *mainSpace;
	Space *livingSpace;
	Space *parentsBedroom;
	Space *parentsBalcony;
	Space *backyard;
	Space *mainPatio;
	
	std::list<Item*> bathRoomItems;
	std::list<Item*> kidsBedRoomItems;
	std::list<Item*> kitchenItems;
	std::list<Item*> mainSpaceItems;
	std::list<Item*> parentsRoomItems;
	std::list<Item*> livingRoomItems;

	Space * curSpace;
	Space * nextSpace;
	Space * prevSpace;
	bool gameWon;
	bool gameOver;

public:
	Game();
	~Game();
	void buildGame();
	void beginGame();
	void printGameTitle();
	void printMainMenu();
	void printObjectives();
	void printFileText(string file);
	void printStats();
	void playGame();
	void pickUpItems();
	void movePlayer();
	char moveMenu();
	void manageInventory();
	void printBagContentsToManage(); //002 renamed
	void checkGameStatus();
};

#endif
