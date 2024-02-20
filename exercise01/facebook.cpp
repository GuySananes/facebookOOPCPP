#include "facebook.h"
#include "profile.h"
#include "date.h"

#include <iostream>

using namespace std;

#define USER_ARRAY_SIZE 10


Facebook::Facebook() 
{
	this->usersList_ = new Profile* [USER_ARRAY_SIZE];
	this->numOfUser_ = 0;

}

Facebook::~Facebook() {
	for (int i; i < this->numOfUser_; i++) {
		delete this->usersList_[i];
	}
	delete this->usersList_;
}

void Facebook::addUser()
{	
	char name[20];
	int year, month, day;
	
	cout << "Please enter user name:" << endl;
	cin >> name;
	cout << "Please enter birth year:" << endl;
	cin >> year;
	cout << "Please enter birth month:" << endl;
	cin >> month;
	cout << "Please enter birth day in the month:" << endl;
	cin >> day;

	Date DateOfBirth(day,month,year);
	Profile* newProfile = new Profile(name, DateOfBirth);
	
	this->usersList_[this->numOfUser_] = newProfile;
}