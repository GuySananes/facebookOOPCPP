#include "facebook.h"
#include <iostream>
#include "profile.h"
#include "date.h"
using namespace std;

#define USER_ARRAY_SIZE 10


Facebook::Facebook() 
{
	this->usersList_ = new Profile* [USER_ARRAY_SIZE];
	this->numOfUser_ = 0;

}

void Facebook::addUser()
{	
	char name[20];
	int year, month, day;
	Profile* newProfile=new Profile;
	cout << "Please enter user name:" << endl;
	cin >> name;
	cout << "Please enter birth year:" << endl;
	cin >> year;
	cout << "Please enter birth month:" << endl;
	cin >> month;
	cout << "Please enter birth day in the month:" << endl;
	cin >> day;
	Date DateOfBirth(day,month,year);

	
	this->usersList_[this->numOfUser_] = newProfile;
}