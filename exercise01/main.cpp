#include <iostream>
using namespace std;
#include "facebook.h"


void main()
{
	Facebook my_facebook;
	my_facebook.addExistUsers();
	int command = 0;
	do{
		command = my_facebook.mainMenu();
		my_facebook.fDo(command);
	} while (command != 12);


}


