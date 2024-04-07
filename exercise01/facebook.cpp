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
	/*this->usersList_ = new Profile* [USER_ARRAY_SIZE]();
	this->numOfUser_ = 0;
	this->numOfFanPage_ = 0;
	this->fanPagesList_ = new FanPage * [USER_ARRAY_SIZE]();
	this->numOfUser_ = 0;*/

}

//Destructor
Facebook::~Facebook() {
	/*for (int i=0; i < this->numOfUser_; i++) {
		delete this->usersList_[i];
	}
	delete this->usersList_;*/
	for (auto user : this->usersList_) 
	{
		delete user.second;
	}
	
	for (auto fanPage : this->fanPagesList_)
	{
		delete fanPage.second;
	}
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
	auto profile = new Profile(name_, DateOfBirth);
	this->usersList_.insert({profile->getProfileName(),profile});
	
}  // add user

void Facebook::addExistUsers()
{
	
	Date DateOfBirth(31, 7, 1980);
	auto harry = new Profile("Harry Potter", DateOfBirth);
	harry->addStatus("THE BOY WHO LIVED");
	harry->addStatus("I'm the chosen one");
	this->usersList_.insert({ harry->getProfileName(), harry });

	DateOfBirth.setDate(19, 9, 1979);
	auto hermione = new Profile("Hermione Granger", DateOfBirth);
	hermione->addStatus("It's LeviOsa, not LevioSA");
	hermione->addStatus("I'm going to the library");
	this->usersList_.insert({ hermione->getProfileName(), hermione });

	DateOfBirth.setDate(1, 3, 1980);
	auto ronald = new Profile("Ronald Weasley", DateOfBirth);
	hermione->addFriend(ronald);
	ronald->addStatus("Why does it always have to be me?");
	ronald->addStatus("I'm hungry");
	this->usersList_.insert({ ronald->getProfileName(), ronald });

	auto hogwarts = new FanPage("Hogwarts");
	hogwarts->addStatus("Welcome to Hogwarts");
	hogwarts->addStatus("The best school of witchcraft and wizardry");
	this->fanPagesList_.insert({hogwarts->getFanPageName(), hogwarts});
	
	auto quidditch = new FanPage("Quidditch");
	quidditch->addFan(harry);
	quidditch->addStatus("The best game in the world");
	quidditch->addStatus("Lets see who can find the snitch");
	this->fanPagesList_.insert({ quidditch->getFanPageName(), quidditch });

	auto army = new FanPage("Dumbledore's Army");
	army->addFan(harry);
	army->addStatus("We are the army of the light");
	army->addStatus("We will fight against the dark lord");
	this->fanPagesList_.insert({ army->getFanPageName(), army });
	
}  // add exist users  

void Facebook::addFanPage()
{
	system("cls");
	gotoxy(0, 0);
	string name;
	cout << "Please enter new fan page name:" << endl;
	ws(cin);
	cin >> name;
	
	this->fanPagesList_.insert({ name, new FanPage(name) });
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
		string user_name;
		showAllProfile();
		cout << "Please enter user name:" << endl;
		cin >> user_name;
		auto it = this->usersList_.find(user_name);
		if(it != this->usersList_.end()) {
			it->second->addStatus();
		}
		else {
			cout << "user: " << user_name << " not found!" << endl;
		}

	}
	else
	{
		string page_name;
		showAllFanPage();
		cout << "Please enter fan page name:" << endl;
		cin >> page_name;
		auto it = this->fanPagesList_.find(page_name);
		if (it != this->fanPagesList_.end()) {
			it->second->addStatus();
		}
		else {
			cout << "fan page: " << page_name << " not found!" << endl;
		}
	}
}

void Facebook::showAllunlinkedProfile(Profile* profile)
{
	system("cls");
	gotoxy(0, 0);
	string name;
	int i = 1;
	for (auto user : this->usersList_)
	{

		if ((!profile->isFriend(user.second)) && !(profile == user.second))
		{
			cout << "User["<<i++<<"]: " << user.second->getProfileName() << endl;
		}
	}
}

void Facebook::showAllPotentialFan(FanPage* page)
{
	system("cls");
	gotoxy(0, 0);
	string name;
	int i = 1;
	for (auto user : this->usersList_)	{
		
		if (!page->isFan(user.second)) {

			cout << "Fan page[" << i++ << "]: " << user.second->getProfileName() << endl;
		}
	}
}

void Facebook::showAllFriends()
{
	system("cls");
	gotoxy(0, 0);
	showAllProfile();
	cout << "Please enter user name:" << endl;
	string user_name;
	cin >> user_name;
	auto it = this->usersList_.find(user_name);
	if (it != this->usersList_.end()) {
		it->second->showAllFriends();
	}
	else {
		cout << "user: " << user_name << " not found!" << endl;
	}
}

void Facebook::showAllProfile()
{
	int i = 1;
	for (auto user : this->usersList_)
	{
		cout << "User " << i++ << " : " << user.first << endl;
	}
	
}

void Facebook::showAllFanPage()
{
	int i = 1;
	for (auto page : this->fanPagesList_)
	{
		cout << "Fan page " << i++ << " : " << page.first << endl;
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
		string user_name;
		showAllProfile();
		cout << "Please enter user name:" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, user_name);
		auto it = this->usersList_.find(user_name);
		if (it != this->usersList_.end()) {
			it->second->showAllStatus();
		}
		else {
			cout << "user: " << user_name << " not found!" << endl;
			return;
		}

	}
	else
	{
		string page_name;
		showAllFanPage();
		cout << "Please enter fan page name:" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, page_name);
		
		auto it = this->fanPagesList_.find(page_name);
		if (it != this->fanPagesList_.end()) {
			it->second->showAllStatus();
		}
		else {
			cout << "fan page: " << page_name << " not found!" << endl;
		}
	}
	
}

void Facebook::linkFriendship()
{
	system("cls");
	gotoxy(0, 0);
	showAllProfile();
	cout << "Please enter user name:" << endl;
	string choice1, choice2;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, choice1);
	auto it = this->usersList_.find(choice1);
	if (it != this->usersList_.end())
	{
		showAllunlinkedProfile(it->second);
	}
	else {
		cout << "user " << choice1 << " not found" << endl;
		return;
	}
	
	cout << "Please enter user name:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, choice2);
	it = this->usersList_.find(choice2);
	if (it != this->usersList_.end())
	{
		usersList_[choice1]->addFriend(it->second);
		it->second->addFriend(usersList_[choice1]);
	}
	else {
		cout << "user " << choice2 << " not found" << endl;
	}

}

void Facebook::cancelFriendship() {
	system("cls");
	gotoxy(0, 0);
	showAllProfile();
	cout << "Please enter user name:" << endl;
	string choice1, choice2;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, choice1);
	auto it = this->usersList_.find(choice1);
	if (it != this->usersList_.end())
	{
		it->second->showAllFriends();
	}
	else
	{
		cout << "user " << choice1 << " not found" << endl;
		return;
	}
	
	cout << "Please enter user name:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, choice2);
	it = this->usersList_.find(choice2);
	if (it != this->usersList_.end())
	{
		this->usersList_[choice1]->removeFriend(choice2);
	}
	else
	{
		cout << "user " << choice2 << " not a friend" << endl;
		return;
	}

}

void Facebook::showLast10Status()
{
	system("cls");
	gotoxy(0, 0);
	string choice;
	cout << "Profile list:" << endl;
	showAllProfile();
	cout << "Please enter user name:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, choice);
	auto it = this->usersList_.find(choice);
	if (it != this->usersList_.end())
	{
		it->second->showLast10Status();
	}
	else
	{
		cout << "user " << choice << " not found" << endl;
	}
	
}

void Facebook::addFanToPage()
{
	system("cls");
	gotoxy(0, 0);
	showAllFanPage();
	cout << "Please enter fan page name:" << endl;
	string choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, choice);
	auto it = this->fanPagesList_.find(choice);
	if (it != this->fanPagesList_.end())
	{
		showAllPotentialFan(this->fanPagesList_[choice]);
	}
	else
	{
		cout << "user " << choice << " not found" << endl;
	}
	
	string user_name;
	cout << "Please enter user name:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, user_name);
	auto user_it = this->usersList_.find(user_name);
	if (user_it != this->usersList_.end()) {
		user_it->second->showAllFriends();
	}
	else {
		cout << "user: " << user_name << " not found!" << endl;
		return;
	}
	this->fanPagesList_[choice]->addFan(user_it->second);
}

void Facebook::removeFanFromPage()
{
	
	system("cls");
	gotoxy(0, 0);
	showAllFanPage();
	cout << "Please enter fan page name:" << endl;
	string page_name;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, page_name);
	auto it = this->fanPagesList_.find(page_name);
	if (it != this->fanPagesList_.end())
	{
		showAllPotentialFan(this->fanPagesList_[page_name]);
	}
	else
	{
		cout << "page " << page_name << " not found" << endl;
		return;
	}

	this->fanPagesList_[page_name]->showAllFans();
	string fan_name;

	cout << "Please enter fan name:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, fan_name);

	

	auto itr = this->usersList_.find(fan_name);
	if (itr != this->usersList_.end())
	{
		this->fanPagesList_[page_name]->removeFan(itr->second);
	}
	else
	{
		cout << "page " << fan_name << " not found" << endl;
		return;
	}
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
		string user_name;
		showAllProfile();
		cout << "Please enter user name:" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, user_name);
		this->usersList_[user_name]->showAllFriends();
		system("pause");
	}
	else
	{
		string page_name;
		showAllFanPage();
		cout << "Please enter fan page name:" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, page_name);
		this->fanPagesList_[page_name]->showAllFans();
		system("pause");
	}
}

void Facebook::exit()
{
	system("cls");
	gotoxy(0, 0);
	cout << "Goodbye!" << endl;
}
