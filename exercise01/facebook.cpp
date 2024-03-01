#include "facebook.h"
#include "profile.h"
#include "date.h"
#include "fanPage.h"

#include <string>
#include <iostream>

using namespace std;

#define USER_ARRAY_SIZE 10

//constructor
Facebook::Facebook() 
{
	this->usersList_ = new Profile* [USER_ARRAY_SIZE];
	this->numOfUser_ = 0;
	this->numOfFanPage_ = 0;

	this->fanPagesList_ = new FanPage * [USER_ARRAY_SIZE];
	this->numOfUser_ = 0;

}

//distructor
Facebook::~Facebook() {
	for (int i=0; i < this->numOfUser_; i++) {
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
		addFanPage();
		break;
	case (int)Command::ADD_STATUS:
		addStatus();
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
	char name_[USER_NAME_LEN];
	int year, month, day;
	
	cout << "Please enter user name:" << endl;
	ws(cin);
	cin.getline(name_, USER_NAME_LEN);

	cout << "Please enter birth year:" << endl;
	cin >> year;
	cout << "Please enter birth month:" << endl;
	cin >> month;
	cout << "Please enter birth day in the month:" << endl;
	cin >> day;

	Date DateOfBirth(day,month,year);
	Profile* newProfile = new Profile(name_, DateOfBirth);
	
	this->usersList_[this->numOfUser_++] = newProfile;
}

void Facebook::addExistUsers()
{
	
	Date DateOfBirth(31, 7, 1980);
	Profile* newProfile = new Profile("Harry Potter", DateOfBirth);
	this->usersList_[this->numOfUser_++] = newProfile;
	DateOfBirth.setDate(19, 9, 1979);
	newProfile = new Profile("Hermione Granger", DateOfBirth);
	this->usersList_[this->numOfUser_++] = newProfile;
	DateOfBirth.setDate(1, 3, 1980);
	newProfile = new Profile("Ronald Weasley", DateOfBirth);
	this->usersList_[this->numOfUser_++] = newProfile;
}

void Facebook::addFanPage()
{
	char name[USER_NAME_LEN];
	cout << "Please enter new fan page name:" << endl;
	ws(cin);
	cin.getline(name, USER_NAME_LEN);
	FanPage* newPage = new FanPage(name);

	this->fanPagesList_[this->numOfFanPage_++] = newPage;
}

void Facebook::addStatus()
{
	cout << "Do you want to add status to a friend or a fan page?" << endl
		<< "1 - Friend" << endl
		<< "2 - Fan page" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		showAllProfile();
		cout << "Please enter user number:" << endl;
		cin >> choice;
		this->usersList_[choice - 1]->addStatus();
	}
	else
	{
		showAllFanPage();
		cout << "Please enter fan page number:" << endl;
		cin >> choice;
		this->fanPagesList_[choice - 1]->addStatus();
	}
}

void Facebook::showAllProfile()
{
	char name[USER_NAME_LEN];
	for (int i = 0; i < this->numOfUser_; i++)
	{
		this->usersList_[i]->getProfileName(name);
		cout << "User " << i + 1 << " : " << name << endl;
	}
}

void Facebook::showAllFanPage()
{
	char name[USER_NAME_LEN];
	for (int i = 0; i < this->numOfFanPage_; i++)
	{
		this->fanPagesList_[i]->getFanPageName(name);
		cout << "Fan page " << i + 1 << " : " << name << endl;
	}
}

void Facebook::showAllStatus()
{
	cout << "Do you want to see all the statuses of a friend or a fan page?" << endl
		<< "1 - Friend" << endl
		<< "2 - Fan page" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		showAllProfile();
		cout << "Please enter user number:" << endl;
		cin >> choice;
		this->usersList_[choice - 1]->addStatus();
	}
	else
	{
		showAllFanPage();
		cout << "Please enter fan page number:" << endl;
		cin >> choice;
		this->fanPagesList_[choice - 1]->addStatus();
	}
}
