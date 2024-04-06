#include "facebook.h"
#include "profile.h"
#include "date.h"
#include "fanPage.h"
#include "general.h"	

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define USER_ARRAY_SIZE 10

//constructor
Facebook::Facebook() 
{
	this->usersList_ = new Profile* [USER_ARRAY_SIZE]();
	this->numOfUser_ = 0;
	this->numOfFanPage_ = 0;
	this->fanPagesList_ = new FanPage * [USER_ARRAY_SIZE]();
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
	system("cls");
	gotoxy(0, 0);
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
		showAllStatus();
		break;
	case (int)Command::SHOW_LAST_10_STATUS:
		showLast10Status();
		break;
	case (int)Command::LINK_FRIENDSHIP:
		linkFriendship();
		break;
	case (int)Command::CANCEL_FRIENDSHIP:
		cancelFriendship();
		break;
	case (int)Command::ADD_FAN_TO_PAGE:
		addFanToPage();
		break;
	case (int)Command::REMOVE_FAN_FROM_PAGE:
		removeFanFromPage();
		break;
	case (int)Command::SHOW_ALL_SYSTEM_ENTETIES:
		showAllSystemEnteties();
		break;
	case (int)Command::SHOW_ALL_FRIENDS:
		showAllFriendsOrFans();
		break;
	case (int)Command::EXIT:
		exit();
		break;

	default:
		break;
	}
}

void Facebook::addUser()
{	
	system("cls");
	gotoxy(0, 0);
	string name_;
	int year, month, day;
	
	cout << "Please enter user name:" << endl;
	ws(cin);
	cin >> name_;

	cout << "Please enter birth year:" << endl;
	cin >> year;
	cout << "Please enter birth month:" << endl;
	cin >> month;
	cout << "Please enter birth day in the month:" << endl;
	cin >> day;

	Date DateOfBirth(day,month,year);
	Profile* newProfile = new Profile(name_, DateOfBirth);
	
	this->usersList_[this->numOfUser_++] = newProfile;
}  // add user

void Facebook::addExistUsers()
{
	
	Date DateOfBirth(31, 7, 1980);
	Profile* newProfile = new Profile("Harry Potter", DateOfBirth);
	newProfile->addStatus("THE BOY WHO LIVED");
	newProfile->addStatus("I'm the chosen one");
	this->usersList_[this->numOfUser_++] = newProfile;
	DateOfBirth.setDate(19, 9, 1979);
	newProfile = new Profile("Hermione Granger", DateOfBirth);
	newProfile->addStatus("It's LeviOsa, not LevioSA");
	newProfile->addStatus("I'm going to the library");
	this->usersList_[this->numOfUser_++] = newProfile;
	DateOfBirth.setDate(1, 3, 1980);
	newProfile = new Profile("Ronald Weasley", DateOfBirth);
	usersList_[1]->addFriend(newProfile);
	newProfile->addStatus("Why does it always have to be me?");
	newProfile->addStatus("I'm hungry");
	this->usersList_[this->numOfUser_++] = newProfile;
	FanPage* newPage = new FanPage("Hogwarts");
	newPage->addStatus("Welcome to Hogwarts");
	newPage->addStatus("The best school of witchcraft and wizardry");
	this->fanPagesList_[this->numOfFanPage_++] = newPage;
	newPage = new FanPage("Quidditch");
	newPage->addFan(usersList_[0]);
	newPage->addStatus("The best game in the world");
	newPage->addStatus("Lets see who can find the snitch");
	this->fanPagesList_[this->numOfFanPage_++] = newPage;
	newPage = new FanPage("Dumbledore's Army");
	newPage->addFan(usersList_[0]);
	newPage->addStatus("We are the army of the light");
	newPage->addStatus("We will fight against the dark lord");
	this->fanPagesList_[this->numOfFanPage_++] = newPage;
}  // add exist users  

void Facebook::addFanPage()
{
	system("cls");
	gotoxy(0, 0);
	string name;
	cout << "Please enter new fan page name:" << endl;
	ws(cin);
	cin >> name;
	FanPage* newPage = new FanPage(name);

	this->fanPagesList_[this->numOfFanPage_++] = newPage;
}

void Facebook::addStatus()
{
	system("cls");
	gotoxy(0, 0);
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

void Facebook::showAllunlinkedProfile(Profile* profile)
{
	system("cls");
	gotoxy(0, 0);
	string name;
	for (int i = 0; i < this->numOfUser_; i++)
	{
		if ((!profile->isFriend(this->usersList_[i])) && !(profile == this->usersList_[i]))
		{
			this->usersList_[i]->getProfileName(name);
			cout << "User " << i + 1 << " : " << name << endl;
		}
	}
}

void Facebook::showAllPotentialFan(FanPage* page)
{
	system("cls");
	gotoxy(0, 0);
	string name;
	for (int i = 0; i < this->numOfUser_; i++)
	{
		if (!page->isFan(this->usersList_[i]))
		{
			this->usersList_[i]->getProfileName(name);
			cout << "User " << i + 1 << " : " << name << endl;
		}
	}
}

void Facebook::showAllFriends()
{
	system("cls");
	gotoxy(0, 0);
	showAllProfile();
	cout << "Please enter user number:" << endl;
	int choice;
	cin >> choice;
	this->usersList_[choice - 1]->showAllFriends();
}

void Facebook::showAllProfile()
{
	string name;
	for (int i = 0; i < this->numOfUser_; i++)
	{
		this->usersList_[i]->getProfileName(name);
		cout << "User " << i + 1 << " : " << name << endl;
	}
}

void Facebook::showAllFanPage()
{
	string name;
	for (int i = 0; i < this->numOfFanPage_; i++)
	{
		this->fanPagesList_[i]->getFanPageName(name);
		cout << "Fan page " << i + 1 << " : " << name << endl;
	}
}

void Facebook::showAllStatus()
{
	system("cls");
	gotoxy(0, 0);
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
		this->usersList_[choice - 1]->showAllStatus();
	}
	else
	{
		showAllFanPage();
		cout << "Please enter fan page number:" << endl;
		cin >> choice;
		this->fanPagesList_[choice - 1]->showAllStatus();
	}
}

void Facebook::linkFriendship()
{
	system("cls");
	gotoxy(0, 0);
	showAllProfile();
	cout << "Please enter user number:" << endl;
	int choice1, choice2;
	cin >> choice1;
	showAllunlinkedProfile(usersList_[choice1 - 1]);
	cout << "Please enter user number:" << endl;
	cin >> choice2;
	usersList_[choice1 - 1]->addFriend(usersList_[choice2 - 1]);
}

void Facebook::cancelFriendship() {
	system("cls");
	gotoxy(0, 0);
	showAllProfile();
	cout << "Please enter user number:" << endl;
	int choice1,choice2;
	cin >> choice1;
	usersList_[choice1 - 1]->showAllFriends();
	cout << "Please enter user number:" << endl;
	cin >> choice2;
	usersList_[choice2 - 1]->removeFriend(choice2);
}

void Facebook::showLast10Status()
{
	system("cls");
	gotoxy(0, 0);
	int choice;
	cout << "Profile list:" << endl;
	showAllProfile();
	cout << "Please enter user number:" << endl;
	cin >> choice;
	this->usersList_[choice - 1]->showLast10Status();
	
}

void Facebook::addFanToPage()
{
	system("cls");
	gotoxy(0, 0);
	showAllFanPage();
	cout << "Please enter fan page number:" << endl;
	int choice;
	cin >> choice;
	showAllPotentialFan(this->fanPagesList_[choice - 1]);
	cout << "Please enter user number:" << endl;
	cin >> choice;
	this->fanPagesList_[choice - 1]->addFan(this->usersList_[choice - 1]);
	this->usersList_[choice - 1]->addFanPage(this->fanPagesList_[choice - 1]);
}

void Facebook::removeFanFromPage()
{
	system("cls");
	gotoxy(0, 0);
	showAllFanPage();
	cout << "Please enter fan page number:" << endl;
	int choice;
	cin >> choice;
	this->fanPagesList_[choice - 1]->showAllFans();
	cout << "Please enter user number:" << endl;
	cin >> choice;
	this->fanPagesList_[choice - 1]->removeFan(this->usersList_[choice - 1]);
}

void Facebook::showAllSystemEnteties() {
	system("cls");
	gotoxy(0, 0);
	cout << "All users:" << endl;
	showAllProfile();
	cout << "All fan pages:" << endl;
	showAllFanPage();
	system("pause");
}

void Facebook::showAllFriendsOrFans()
{
	system("cls");
	gotoxy(0, 0);
	cout << "Do you want to see all the friends of a friend or the fans of a fan page?" << endl
		<< "1 - Friend" << endl
		<< "2 - Fan page" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		showAllProfile();
		cout << "Please enter user number:" << endl;
		cin >> choice;
		this->usersList_[choice - 1]->showAllFriends();
		system("pause");
	}
	else
	{
		showAllFanPage();
		cout << "Please enter fan page number:" << endl;
		cin >> choice;
		this->fanPagesList_[choice - 1]->showAllFans();
		system("pause");
	}
}

void Facebook::exit()
{
	system("cls");
	gotoxy(0, 0);
	cout << "Goodbye!" << endl;
}
