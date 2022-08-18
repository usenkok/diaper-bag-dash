/*********************************************************************
** Program name:
** Author: Kelly Usenko
** Date: 6/12/2018
** Description:
*********************************************************************/


#include "patio.hpp"

/*********************************************************************
** Patio::
**
*********************************************************************/


/*********************************************************************
** Patio::
**
*********************************************************************/


Patio::Patio()
{
	//default constructor

	//default constructor
	this->sType = _PATIO;
	this->spaceName = "Patio Default Name";

	this->collectable = false;
	this->locked = true;


	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;

}
/*********************************************************************
** Patio::
**
*********************************************************************/


Patio::Patio(string pName)
{
	//set name
	this->spaceName = pName;

	this->sType = _PATIO;

	this->collectable = false;
	this->locked = true;

	this->collectableMessage = "Uh Oh. You hear a click and turn around.";

	//set pointers to null
	this->left = nullptr;
	this->right = nullptr;
	this->down = nullptr;
	this->up = nullptr;



}
/*********************************************************************
** Patio::
**
*********************************************************************/


Patio::~Patio()
{
	//destructor
}


/*********************************************************************
** Patio::
**
*********************************************************************/
void Patio::printMenu()
{
	//patio menu
	int spaceChoice = 0;

	do {
		cout << "\nPatio Action Menu" << endl;
		cout << "1. Panic!!!" << endl;
		cout << "2. Start yelling really loudly hoping the neighbors hear you" << endl;
		cout << "3. Feed the stray cat" << endl;
		cout << "4. Coach your kid through unlocking the door" << endl;

		helpers::getValidInteger(&spaceChoice, "Choose 1-4", 0, 4);

		if (spaceChoice == 1) {
			cout << "User chose 1" << endl;
			//searchInCloset();
		}
		else if (spaceChoice == 2)
		{
			cout << "User chose 2" << endl;
			//searchUnderBed();

		}
		else if (spaceChoice == 3)
		{
			cout << "user chose 3" << endl;
		}
	} while (spaceChoice != 4);




}
