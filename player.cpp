/*********************************************************************
** Program name:
** Author: Kelly Usenko
** Date: 6/12/2018
** Description:
*********************************************************************/


/*********************************************************************
** Player::
**
*********************************************************************/

#include "player.hpp"


/*********************************************************************
** Player::Player()
**
*********************************************************************/
Player::Player()
{
	//default constructor
	patience = MAX_PATIENCE;
	hasPatienceLeft = true;

}



/*********************************************************************
** Player::~Player()
**
*********************************************************************/
Player::~Player()
{
	//destructor
}


/*********************************************************************
** Player::adjustPatience(int amount)
**
*********************************************************************/
void Player::adjustPatience(int amount)
{
	//+ add to patience
	//-remove from patience
	patience = patience + amount; //test negative number here

	if (patience <= 0)
	{
		patience = 0;
		hasPatienceLeft = false;
	}

	else if (patience > MAX_PATIENCE)
	{
		patience = MAX_PATIENCE;
	}
}

/*********************************************************************
** Player::getPatienceAmnt()
**
*********************************************************************/
int Player::getPatienceAmnt()
{
	return patience;
}

/*********************************************************************
** Player::getHasPatienceLeft()
**
*********************************************************************/
bool Player::getHasPatienceLeft()
{
	return hasPatienceLeft;
}
