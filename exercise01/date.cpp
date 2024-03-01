#include "date.h"
#include <iostream>
#include <ctime>
using namespace std;

void Date::showDate()
{
	cout << this->day << "/" << this->month << "/" << this->year;
}

void Date::setDate(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}
