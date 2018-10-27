// Project		: HR Management System
// Description	: Project manages employees information for a company. Design supports the enhancement of the project to support
//				: multiple complanies
// Author 		: Himanshu Singh
// Class		: XII A
// Roll No		: 15


#include <iostream>


// Header files for classes
#include "Menu.h"
#include "ProjectConstants.h"

const int HR_QUIT=-1;
const int HR_ERROR_MAXWRONGOPTION=0;
const int HR_SUCCESS=1;
const int HR_FILE_NOT_FOUND=-1;
const int HR_INCORRECT_MENU_FORMAT=-2;


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	Menu m;
	int opt;
	char menuNumber[OPTION_NUMBER_LEN];
	
	strcpy(menuNumber,"");
	if ((opt=m.readMenu())==HR_SUCCESS){
		
		//while ((opt=m.chooseOption())!=HR_QUIT){
		
		while (1){
				
			while ((opt=m.chooseOption(menuNumber))!=HR_QUIT){
				cout << "Option chosen = " << opt<<endl;
				if (!m.isSubmenu(opt))	{
					//cout<<"Not a Submenu"<<endl;
					m.action(opt);
				}
				else {
					strcpy(menuNumber,m.getOptionNumber(opt));
					//cout << "Its a submenu, menuNumber being passed = " << menuNumber <<endl;
					continue;
				}
			}
			if (opt==HR_QUIT && strlen(menuNumber)>0)
			{
				strcpy(menuNumber,"");
			}
			else if (opt==HR_QUIT && strlen(menuNumber)==0)
			{
				cout << "Thanks for using HRSystem :)\n";
				return -1;
			}
		}
	}	
	else if (opt==HR_FILE_NOT_FOUND){	
		cout << "Configure Menu File.\nFilename should be menu.txt - made using notepad. A sample menu.txt is provided with the project\n";
		return -1;
	}
	else if (opt==HR_INCORRECT_MENU_FORMAT){
		cout << "Please check the menu file format. Menu and submenu should be in hierarchical format. Each menu must have a menu option number\n";
		return -1;	
	}

	return 0;
}
