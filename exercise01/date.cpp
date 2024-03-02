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

int Date::compareTo(const Date& other) const {
	if (year < other.year) return -1;
	if (year > other.year) return 1;
	
	if (month < other.month) return -1;
	if (month > other.month) return 1;
	
	if (day < other.day) return -1;
	if (day > other.day) return 1;
	
	return 0;
}