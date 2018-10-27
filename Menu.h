#ifndef MENU_H
#define MENU_H

#include <string.h>
#include <fstream>
#include <iostream>


using namespace std;

const int OPTION_TEXT_SIZE=50;
const int OPTION_NUMBER_LEN=35;
const int LINE_SIZE=100;
const int MENU_SIZE=50;

class Menu {
	
	struct options {
		char optionNumber[OPTION_NUMBER_LEN];
		char optionText[OPTION_TEXT_SIZE];
		int hasSubMenu;
	} optionArr[MENU_SIZE];
	int noOfMenuItems;
	
	public:

		int readMenu();	
		int chooseOption(char *m);
		//int chooseOption();
		int action(int opt);
		int isSubmenu(int opt);
		char *getOptionNumber(int opt);
};


#endif
