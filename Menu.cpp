#include <string.h>
#include "Menu.h"
#include "ProjectConstants.h"


using namespace std;


int Menu::readMenu(){
	char l[LINE_SIZE] ;
	ifstream fin ;
	int i,j,k,len,lineno;
	
	fin.open("menu.txt" , ios::in);
	lineno=0;
	j=0;
	
	while(!fin.eof())
	{
		fin.getline(l,LINE_SIZE) ;
		i=k=0;
		len=strlen(l);
		//Parse and store optionNumber
		while(isspace(l[i])) ++i; //skip initial spaces
		strcpy(optionArr[j].optionText,l+i);
		for (k=0;l[i]!=')';++k,++i){
			optionArr[j].optionNumber[k]=l[i];	
			
				
		}
		optionArr[j].optionNumber[k]=l[i]; //copying ")" character.
		optionArr[j].optionNumber[k+1]='\0';
		
		optionArr[j].hasSubMenu=0; //initializing submenu for the current record.
		if (j>0 && strlen(optionArr[j-1].optionNumber)<strlen(optionArr[j].optionNumber)){
			optionArr[j-1].hasSubMenu=1; //Compares with previous menu to see if it is a submenu
		} else 
			optionArr[j-1].hasSubMenu=0;
		
		++j;  
	}
	noOfMenuItems=j; //Stores total number of Menu items including sub menus
	return HR_SUCCESS;
}

int Menu::chooseOption(char *m){
	
	//cout <<"Entering chooseOption" <<endl;
	
	char menuNumber[OPTION_NUMBER_LEN];
	int inpMenuNumberLen=0;
	int i,offset=-1;
	int countOnDisplay,userInput,oneLevelUp=0;
	
	strcpy(menuNumber,m);
	inpMenuNumberLen=strlen(menuNumber);
	
	//cout <<"Just before the for loop in chooseOption" << endl;
	do {
		countOnDisplay=0;
		//system ("CLS"); // Clearing up the screen 
		for (i=0;i<noOfMenuItems;++i)
		{
			//cout << "Inside for loop i="<<i<<endl;
			//cout << " len optionArr.optionNumber = " << strlen(optionArr[i].optionNumber) <<"  inpMenuNumberLen="<<inpMenuNumberLen<<"  "<<optionArr[i].optionNumber<<endl;
			int len=strlen(optionArr[i].optionNumber)-2;
			//cout <<"len = "<<len<<" i = " << i<<"  strlen(optionArr[i].optionNumber) = " << strlen(optionArr[i].optionNumber) << endl;
			//cout << "len= "<<len<<"inpMenuNumberLen = "<<inpMenuNumberLen<<endl;
			if (len==inpMenuNumberLen && !oneLevelUp){//making sure that we are sticking to the next level of submenus and no further.
			
				//if (inpMenuNumberLen==0||strncmp(menuNumber,optionArr[i].optionNumber,inpMenuNumberLen)){
				if (inpMenuNumberLen==0){
					//cout <<"	Inside if condition inpMenuNumberLen = " << inpMenuNumberLen;
					//cout <<"Printing Menu"<<endl;
					cout << optionArr[i].optionText<<endl;
					++countOnDisplay;
					if (offset==-1) offset=i; //records position of submenu in the optionArr
				}else if (strncmp(menuNumber,optionArr[i].optionNumber,inpMenuNumberLen-1)==0){//-1 is so that I don't compare ")"
					//cout << "menuNumber = " <<menuNumber << " i = " << i<< " optionArr[i].optionNumber = "<<optionArr[i].optionNumber<<endl;
					cout << optionArr[i].optionText<<endl;
					++countOnDisplay;
					if (offset==-1) offset=i; //records position of submenu in the optionArr
				}
			}
			
		}
		cout <<"\n Choose Option, Press 0 to quit : ";
		cin >> userInput;
	} while (userInput < 0 || userInput > countOnDisplay);
	cout << "Value of Offset in ChooseOption = " <<offset<<" countOnDisplay = "<<countOnDisplay<<endl;
	if (userInput == 0)
		return HR_QUIT;
	else
		return userInput-1+offset;
}

int Menu::isSubmenu(int opt)
{
	return optionArr[opt].hasSubMenu;
}

char * Menu::getOptionNumber(int opt){
	return optionArr[opt].optionNumber;
}
int Menu::action(int opt){
	cout << "Inside Menu::action()"<<endl;
	
	return 0;
}
	
