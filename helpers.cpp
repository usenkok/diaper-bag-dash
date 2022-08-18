/*********************************************************************
** Program name: helpers.cpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: Helper functions useful utilities like input validation
** and randon number generation
*********************************************************************/


#include "helpers.hpp"

/*********************************************************************
**printMainMenuTitle() - prints title to screen for main program
*********************************************************************/
void helpers::printMainMenuTitle()
{
	cout << "\n - - - Menu Title- - - \n" << endl;

}


/*********************************************************************
** printMenuOptions() - displays main menu options to choose or quit
*********************************************************************/
void helpers::printMenuOptions()
{
	string menuChoice1 = "1. ";
	string menuChoice2 = "2. ";
	string menuChoice3 = "3. Exit";

	cout << menuChoice1 << endl;
	cout << menuChoice2 << endl;
	cout << menuChoice3 << endl;
}


/*********************************************************************
** printMenuPlayAgain() Prints play again or exit menu
*********************************************************************/
void helpers::printMenuPlayAgain()
{
	string menuPlayChoice1 = "1. Play again";
	string menuPlayChoice2 = "2. Exit";

	cout << menuPlayChoice1 << endl;
	cout << menuPlayChoice2 << endl;
}



/*********************************************************************
** getValidInteger(int *result)
** Function that uses generic question to get user input integer
*********************************************************************/
void helpers::getValidInteger(int *result)
{
	string requestText = "Please enter an integer.";
	string tryAgainText = "Invalid entry. Please try again.";
	string stringInput;
	bool isValid = false;

	cout << requestText << endl;

	do {
		getline(cin, stringInput);

		if (validateInt(stringInput, -1, 100000))
		{
			isValid = true;
		}
		else {

			cout << tryAgainText << endl;
		}

	} while (!isValid);

	*result = stoi(stringInput);
}


/*********************************************************************
** getValidInteger(int *result, string promptForUser, int minInt, int maxInt)
** Function that takes string prompt for user and range of integer needed
*********************************************************************/
void helpers::getValidInteger(int *result, string promptForUser, int minInt, int maxInt)
{
	string requestText = promptForUser;
	string tryAgainText = "Invalid entry. Please try again.";
	string stringInput;
	bool isValid = false;

	cout << requestText << endl;

	do {
		getline(cin, stringInput);

		if (validateInt(stringInput, minInt, maxInt))
		{
			isValid = true;
		}
		else {

			cout << tryAgainText << endl;
		}
	} while (!isValid);

	*result = stoi(stringInput);
}

/*********************************************************************
** getValidInteger(int mode, int *result, string promptForUser, int minInt, int maxInt)
** this version does not include end line at string end
*********************************************************************/
void helpers::getValidInteger(int mode, int *result, string promptForUser, int minInt, int maxInt)
{
	string requestText = promptForUser;
	string tryAgainText = "Invalid entry. Please try again.";
	string stringInput;
	bool isValid = false;

	cout << requestText;

	do {
		getline(cin, stringInput);

		if (validateInt(stringInput, minInt, maxInt))
		{
		isValid = true;
		}
		else {

			cout << tryAgainText << endl;
		}
	} while (!isValid);

	*result = stoi(stringInput);
	//clear input buffer
	cout << endl;
}



/*********************************************************************
** validateInt(string userInput, int minVal, int maxVal)
** Adapted from stingstream document from piazza post 146
*********************************************************************/
bool helpers::validateInt(string userInput, int minVal, int maxVal)
{
	bool isInputValid = false;
	string input;
	stringstream text(userInput);
	int integerTest;

	//checks that text goes completely into integer variable
	//and that there isn't anything left in buffer
	if ((text >> integerTest) && !(text >> input))
	{
		if (integerTest > minVal && integerTest < maxVal)
		{
			isInputValid = true;
		}
	}
	return isInputValid;
}


/*********************************************************************
** getString(string promptForUser, string * stringToStore)
**
*********************************************************************/
void helpers::getString(string promptForUser, string * stringToStore)
{
	string tempString;
	cout << promptForUser << endl;

	do {
		cin.clear();

		getline(cin, tempString);
		if (tempString.size() == 0) {
			cout << "String cannot be empty" << endl;
		}
	} while (!validateStringResponse(&tempString, 0, 250));

	*stringToStore = tempString;
}


/*********************************************************************
** getString(string promptForUser, string * stringToStore, int minCharS, int maxCharS)
** Overloaded function allowing custom entry of string size if needed
*********************************************************************/
void helpers::getString(string promptForUser, string * stringToStore, int minCharS, int maxCharS)
{
	string tempString;
	cout << promptForUser << endl;

	do {
		cin.clear();

		getline(cin, tempString);
		if (tempString.size() == 0) {
			cout << "String cannot be empty" << endl;
		}
	} while (!validateStringResponse(&tempString, minCharS, maxCharS));

	*stringToStore = tempString;
}


/*********************************************************************
** helpers::getyesNo() - gets yes or no from user
**
*********************************************************************/
char helpers::getyesNo()
{
	//
	bool validResponse = false;
	string promptForYesNo = "Y/N?";
	string response;

	do
	{	//cin.clear();
		getline(cin, response);

		if (response.size() == 1 && (toupper(response[0]) == 'Y' || toupper(response[0]) == 'N'))
		{
			validResponse = true;
		}
		else
		{
			cout << "Invalid response. Please enter Y or N." << endl;
		}

	} while (!validResponse);

	return toupper(response[0]);
}

/*********************************************************************
** helpers::getyesNo(string yesNoPrompt) - gets yes or no from user
** overloaded allows argument for user prompt
*********************************************************************/
char helpers::getyesNo(string yesNoPrompt)
{
	bool validResponse = false;
	string promptForYesNo = yesNoPrompt;
	string response;

	cout << yesNoPrompt << endl;

	do
	{	//cin.clear();
		getline(cin, response);

		if (response.size() == 1 && (toupper(response[0]) == 'Y' || toupper(response[0]) == 'N'))
		{
			validResponse = true;
		}
		else
		{
			cout << "Invalid response. Please enter Y or N." << endl;
		}

	} while (!validResponse);

	return toupper(response[0]);
}

/*********************************************************************
** validateStringResponse(string * stringInput, int minChar, int maxChar)
** Returns true/false if user entered a non-empty string within size limits
*********************************************************************/

bool helpers::validateStringResponse(string * stringInput, int minChar, int maxChar)
{
	bool isStringValid = false;

	if (stringInput->size() > minChar && stringInput->size() < maxChar)
	{
		isStringValid = true;
	}

	//else too long or short
	return isStringValid;
}

/*********************************************************************
* generateRandomNumber function to get random numbers for do_work functions
*********************************************************************/
int helpers::generateRandomNumber(int minNbr, int maxNbr)
{
	int nbrToReturn = 0;

	nbrToReturn = (rand() % (maxNbr - minNbr + 1)) + minNbr;
	return nbrToReturn;
}


/*********************************************************************
* helpers::clearScreen() - escape sequence to clear console screen
* 002 Updated to work across platforms
* https://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
*********************************************************************/
void helpers::clearScreen()
{
	//cout << "\033[2J\033[1;1H"; //001
	#ifdef WINDOWS
		system("cls"); //001
	#else
		system("clear"); //002
	#endif 
}


/*********************************************************************
* enterKeyToContinue() - Function to pause output until user enters any character
*********************************************************************/
void helpers::enterKeyToContinue()
{
	char ch;
	cout << "Press any key to continue." << endl;
	cin.get(ch);
}

/*********************************************************************
* enterKeyToContinue() - Function to pause output until user enters any character
*********************************************************************/
void helpers::enterKeyToContinue(string outputString)
{
	char ch;
	cout << outputString << endl;
	cin.get(ch);
}

/*********************************************************************
* enterKeyToContinue() - Function to pause output until user enters any character
* override
*********************************************************************/
void helpers::enterKeyToContinue(string outputString, int i)
{
	char ch;
	cout << outputString;
	cin.get(ch);
	cout << endl;
}


/*********************************************************************
* printPacifier() 
*********************************************************************/
void helpers::printPacifier()
{
	cout << "\n       __" << endl;
	cout << "      (  )" << endl;
	cout << "       )(" << endl;
	cout << "    ,;/  \\:." << endl;
	cout << "   ( `.__,' )" << endl;
	cout << "    `-.__,-'" << endl;
	cout << "     ((__))" << endl;
	cout << "      `--'" << endl;

}