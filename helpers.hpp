/*********************************************************************
** Program name: helpers.hpp
** Author: Kelly Usenko
** Date: 6/12/2018
** Description: definition of helper functions for input validation
** and useful utilities
*********************************************************************/

#ifndef HELPERS_HPP
#define HELPERS_HPP


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <climits>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <iterator>
#include <utility>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::cin;
using std::stoi;
using std::stod;
using std::getline;
using std::string;
using std::fixed;
using std::showpoint;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::stringstream;
using std::ifstream;

namespace helpers {


	void printMainMenuTitle();
	void printMenuOptions();
	void printMenuPlayAgain();
	void getString(string promptForUser, string *stringToStore);
	void getString(string promptForUser, string *stringToStore, int minCharS, int maxCharS);
	char getyesNo();
	char getyesNo(string yesNoPrompt);
	bool validateStringResponse(string* stringInput, int minChar, int maxChar);
	void getValidInteger(int *result);
	void getValidInteger(int mode, int *result, string promptForUser, int minInt, int maxInt);
	void getValidInteger(int *result, string promptForUser, int minInt, int maxInt);
	bool validateInt(string input, int minVal, int maxVal);
	int generateRandomNumber(int minNbr, int maxNbr);
	void clearScreen();
	void enterKeyToContinue();
	void enterKeyToContinue(string outputString);
	void enterKeyToContinue(string outputString, int i);
	void printPacifier();
}

#endif
