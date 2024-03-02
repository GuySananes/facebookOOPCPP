#include "profile.h"
#include <string.h>
#include <iostream>
#include "general.h"
using namespace std;


//constructor
Profile::Profile (char name_[USER_NAME_LEN],Date& dateOfBirth)
{
	this->date_of_birth_ = dateOfBirth;
	strncpy(this->name_, name_, USER_NAME_LEN - 1);
	this->name_[USER_NAME_LEN - 1] = '\0';
	this->num_of_friends_ = 0;
	this->size_of_friends_list_ = 1;
	this->friends_list_ = new Profile*[size_of_friends_list_]();	
	this->size_of_status_list_ = 1;
	this->status_list_ = new Status*[size_of_status_list_]();
	this->num_of_status_ = 0;

}

Profile::Profile (const char name_[USER_NAME_LEN], Date& dateOfBirth)
{
	this->date_of_birth_ = dateOfBirth;
	strncpy(this->name_, name_, USER_NAME_LEN - 1);
	this->name_[USER_NAME_LEN - 1] = '\0';
	this->num_of_friends_ = 0;
	this->size_of_friends_list_ = 1;
	this->friends_list_ = new Profile * [size_of_friends_list_]();
	this->size_of_status_list_ = 1;
	this->status_list_ = new Status * [size_of_status_list_]();
	this->num_of_status_ = 0;
}

//distructor
Profile::~Profile()
{
	for (int i = 0; i < this->num_of_friends_; i++)
	{
		delete this->friends_list_[i];
	}
	delete[] this->friends_list_;
}

void Profile::getProfileName(char* name)
{
	strncpy(name, this->name_, USER_NAME_LEN);
	name[USER_NAME_LEN - 1] = '\0';
}

void Profile::addStatus()
{
	char status[STATUS_LEN];
	cout << "Please enter new status:" << endl;
	ws(cin);
	cin.getline(status, STATUS_LEN);
	if (this->num_of_status_ == this->size_of_status_list_)
		increaseSizeOfStatusList();
	Status* newStatus = new Status(status);
	this->status_list_[this->num_of_status_++] = newStatus;
}

void Profile::addStatus(const char* status)
{
	Status* newStatus = new Status(status);
	if (this->num_of_status_ == this->size_of_status_list_)
		increaseSizeOfStatusList();
	this->status_list_[this->num_of_status_++] = newStatus;
	Profile::sortStatusesByDate(this->status_list_, this->num_of_status_);
}

void Profile::showAllStatus()
{
	for (int i = 0; i < this->num_of_status_; i++)
	{
		this->status_list_[i]->showStatus();
	}
	system("pause");
}

void Profile::addFriend(Profile* newFriend)
{
	if (this->num_of_friends_ == this->size_of_friends_list_)
		increaseSizeOfFriendsList();
	if (newFriend->num_of_friends_ == newFriend->size_of_friends_list_)
		newFriend->increaseSizeOfFriendsList();
	newFriend->friends_list_[newFriend->num_of_friends_++] = this;
	this->friends_list_[this->num_of_friends_++] = newFriend;
}

void Profile::showAllFriends() {
	system("cls");
	gotoxy(0, 0);
	char name[USER_NAME_LEN];
	for (int i = 0; i < num_of_friends_;i++) {
		friends_list_[i]->getProfileName(name);
		cout << "User " << i + 1 << " : " << name << endl;
	}
}

void Profile::removeFriend(int numOfFriend)
{
	if (numOfFriend < 0 || numOfFriend > this->num_of_friends_)
	{
		cout << "Invalid friend number" << endl;
		return;
	}
	for (int i = numOfFriend; i <= this->num_of_friends_; i++)
	{
		this->friends_list_[i] = this->friends_list_[i + 1];
	}
	this->num_of_friends_--;
}

void Profile::sortStatusesByDate(Status** status_list, int num_of_status)
{
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < num_of_status - 1; i++) {
			
			if (status_list[i]->getDate().compareTo(status_list[i + 1]->getDate()) > 0) {
				
				Status* temp = status_list[i];
				status_list[i] = status_list[i + 1];
				status_list[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

void Profile::showLast10Status()
{
	Status** latest = new Status * [(1 + this->num_of_friends_)* 10];
	int i = 0, size = (1 + this->num_of_friends_) * 10;
	while( i < 10 && this->num_of_status_ - 1 - i >= 0)
	{
		latest[i] = this->status_list_[this->num_of_status_ - 1 - i];
		i--;
	}

	for ( i = 10; i < size; i+=10)
	{
		int j = 0;
		while(j < 10 && this->friends_list_[i/10 - 1]->num_of_status_ - 1 - j >=0)
		{
			latest[i] = this->friends_list_[i / 10 - 1]->status_list_[this->friends_list_[i / 10 - 1]->num_of_status_ - 1 - j];
			i--;
		}
	}

	Profile::sortStatusesByDate(latest, size);

	cout << "Top 10 latest statuses:" << endl;

	for(i = size - 11; i < size; i++)
	{
		latest[i]->getDate().showDate();
		cout << " ";
		latest[i]->showStatus();
		cout << endl;
	}
	system("pause");
}

bool Profile::isFriend(Profile* profile)
{
	for (int i = 0; i < this->num_of_friends_; i++)
	{
		if (this->friends_list_[i] == profile)
		{
			return true;
		}
	}
	return false;
}

void Profile::increaseSizeOfFriendsList()
{
	this->size_of_friends_list_ *= 2;
	Profile** temp = new Profile * [this->size_of_friends_list_];
	for (int i = 0; i < this->num_of_friends_; i++)
	{
		temp[i] = this->friends_list_[i];
	}
	delete[] this->friends_list_;
	this->friends_list_ = temp;
}

void Profile::increaseSizeOfStatusList()
{
	this->size_of_status_list_ *= 2;
	Status** temp = new Status * [this->size_of_status_list_];
	for (int i = 0; i < this->num_of_status_; i++)
	{
		temp[i] = this->status_list_[i];
	}
	delete[] this->status_list_;
	this->status_list_ = temp;
}