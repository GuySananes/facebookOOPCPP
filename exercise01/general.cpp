#include "general.h"
#include <Windows.h>
#include <iostream>
using namespace std;


void gotoxy(int x, int y)
{
	COORD c = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


