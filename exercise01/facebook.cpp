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


int Facebook::mainMenu()
{
	int return_val;
	cout << "Welcome To FaceBook" << endl
		<< "What do you want to do next?" << endl
		<< "1 - Add new user" << endl
		<< "2 - Add new fan page" << endl
		<< "3 - Add status to a friend or fan page" << endl
		<< "4 - Show all status of friend of fan page" << endl
		<< "5 - Show last 10 status of friend or fan page" << endl
		<< "6 - Link friendship for two friends" << endl
		<< "7 - Cancel friendship between two friends" << endl
		<< "8 - Add fan to page" << endl
		<< "9 - Remove fan from page" << endl
		<< "10 - Show all system's enteties" << endl
		<< "11 - Show all friends of a friend or fans of a page" << endl
		<< "12 - Exit" << endl;

	cin >> return_val;
	return return_val;

}

void Facebook::fDo(int command)
{
	switch (command)
	{
	case (int)Command::ADD_USER:
		addUser();
		break;
	case (int)Command::ADD_FAN_PAGE:
		//addFanPage();
		break;
	case (int)Command::ADD_STATUS:
		//addStatus();
		break;
	case (int)Command::SHOW_ALL_STATUS:
		//showAllStatus();
		break;
	case (int)Command::SHOW_LAST_10_STATUS:
		//showLast10Status();
		break;
	case (int)Command::LINK_FRIENDSHIP:
		//linkFriendship();
		break;
	case (int)Command::CANCEL_FRIENDSHIP:
		//cancelFriendship();
		break;
	case (int)Command::ADD_FAN_TO_PAGE:
		//addFanToPage();
		break;
	case (int)Command::REMOVE_FAN_FROM_PAGE:
		//removeFanFromPage();
		break;
	case (int)Command::SHOW_ALL_SYSTEM_ENTETIES:
		//showAllSystemEnteties();
		break;
	case (int)Command::SHOW_ALL_FRIENDS:
		//showAllFriends();
		break;
	case (int)Command::EXIT:
		//exit();
		break;

	default:
		break;
	}
}

void Facebook::addUser()
{	
	char name[USER_NAME_LEN];
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
	
	this->usersList_[this->numOfUser_++] = newProfile;
}

void Facebook::addExistUsers()
{
	
	Date DateOfBirth(11, 11, 1969);
	//Profile* newProfile = new Profile("Doron Sananes", DateOfBirth);

	//this->usersList_[this->numOfUser_++] = newProfile;
}