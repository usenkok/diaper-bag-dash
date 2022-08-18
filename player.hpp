/*********************************************************************
** Program name: player.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: definition of player class
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
private:
	const int MAX_PATIENCE = 50;	//maximum amount patience
	int patience;					//current level patience
	bool hasPatienceLeft;			//flag to indicate if patience has run out

public:
	Player();
	~Player();
	void adjustPatience(int amount);
	int getPatienceAmnt();
	bool getHasPatienceLeft();
};
#endif


