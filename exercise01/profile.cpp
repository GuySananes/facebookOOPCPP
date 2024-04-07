#include "profile.h"
#include <string.h>
#include <iostream>
#include "general.h"
#include "status.h"
#include "fanPage.h"
using namespace std;


//constructor

Profile::Profile (const string name_, Date& dateOfBirth)
{
	this->date_of_birth_ = dateOfBirth;
	this->name_ = name_;	

}

//Destructor
Profile::~Profile()
{
	for (auto status : this->status_list_)
	{
		delete status;
	}

	/*for (auto profile :this->friends_list_)
	{
		if (this->friends_list_.find(profile.second->getProfileName()) != this->friends_list_.end())
			delete profile.second;
	}*/

	/*for (auto page : this->liked_pages_)
	{
		if (this->liked_pages_.find(page.second->getFanPageName()) != this->liked_pages_.end())
			delete page.second;
	}*/
}



void Profile::addStatus()
{
	string status;
	cout << "Please enter new status:" << endl;
	ws(cin);
	cin >> status;
	this->addStatus(status);
	
}

void Profile::addStatus(const string status)
{
	Status* newStatus = new Status(status);
	this->status_list_.push_front(newStatus);
	
}

void Profile::showAllStatus()
{
	for (auto status : this->status_list_)
	{
		status->showStatus();
	}
	
	system("pause");
}

void Profile::addFriend(Profile* newFriend)
{
	this->friends_list_.insert({newFriend->name_, newFriend});
}

void Profile::showAllFriends() {
	system("cls");
	gotoxy(0, 0);
	int i = 1;
	for (auto profile: this->friends_list_) {
		cout << "User " << i++ << " : " << profile.first << endl;
	}
}

void Profile::removeFriend(const string& f_name)
{
	this->friends_list_.erase(f_name);
}



void Profile::addFanPage(FanPage* page)
{
	this->liked_pages_.insert({ page->getFanPageName(), page });
}

void Profile::showLast10Status()
{
	cout << "Top 10 latest statuses:" << endl;

	int counter = 1;
	for (auto status : this->status_list_)
	{
		if (counter++ == 10) break;
		status->showStatus();
	}

	system("pause");
}

bool Profile::isFriend(Profile* profile)
{
	string name = profile->getProfileName();
	auto it = this->friends_list_.find(name);
	return it != this->friends_list_.end();
}

