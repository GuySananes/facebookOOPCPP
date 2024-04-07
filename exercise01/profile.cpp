#include "profile.h"
#include <string.h>
#include <iostream>
#include "general.h"
#include "status.h"
#include "fanPage.h"
using namespace std;


//constructor

Profile::Profile (const string name_, Date& dateOfBirth): baseProfile(name_)
{
	this->date_of_birth_ = dateOfBirth;	
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
	this->liked_pages_.insert({ page->getName(), page });
}

bool Profile::isFriend(Profile* profile)
{
	string name = profile->getName();
	auto it = this->friends_list_.find(name);
	return it != this->friends_list_.end();
}

