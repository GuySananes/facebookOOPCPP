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
	this->num_of_friends_ = 0;
	this->size_of_friends_list_ = 1;
	this->friends_list_ = new Profile * [size_of_friends_list_]();
	this->size_of_status_list_ = 1;
	this->status_list_ = new Status * [size_of_status_list_]();
	this->num_of_status_ = 0;
	this->num_of_liked_pages_ = 0;
	this->size_of_liked_pages_ = 1;
	this->liked_pages_ = new FanPage * [size_of_liked_pages_]();

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

void Profile::getProfileName(string& name)
{
	name = this->name_;
}

void Profile::addStatus()
{
	string status;
	cout << "Please enter new status:" << endl;
	ws(cin);
	cin >> status;
	if (this->num_of_status_ == this->size_of_status_list_)
		increaseSizeOfStatusList();
	Status* newStatus = new Status(status);
	this->status_list_[this->num_of_status_++] = newStatus;
}

void Profile::addStatus(const string status)
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
	string name;
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

void Profile::addFanPage(FanPage* page)
{
	if (this->num_of_liked_pages_ == this->size_of_liked_pages_)
		increseSizeOfFanPageList();
	this->liked_pages_[this->num_of_liked_pages_++] = page;
}

void Profile::showLast10Status()
{
	Status** latest = new Status * [10]();
	int size = 0;
	for (int i = 0; i < this->num_of_friends_;i++) {
		for (int j = 0; j < this->friends_list_[i]->num_of_status_; j++) {
			if (this->friends_list_[i]->status_list_[j] != nullptr) {
				if (size< 10) {
					latest[size] = this->friends_list_[i]->status_list_[j];
					size++;
				}
				else if(latest[9]->getDate().compareTo(this->friends_list_[i]->status_list_[j]->getDate()) < 0)
				{
					latest[9] = this->friends_list_[i]->status_list_[j];
					sortStatusesByDate(latest, 10);
				}
			}
		}
	}
	Status* temp = nullptr;
	for (int i = 0; i < this->num_of_liked_pages_; i++) {
		for (int j = 0; j < this->liked_pages_[i]->getNumOfStatus(); j++) {
			temp= this->liked_pages_[i]->getStatus(j);
			if (temp != nullptr) {
				if (size < 10) {
					latest[size] = temp;
					size++;
				}
				else if (latest[9]->getDate().compareTo(temp->getDate()) < 0)
				{
					latest[9] = temp;
					sortStatusesByDate(latest, 10);
				}
			}
		}
	
	}
	cout << "Top 10 latest statuses:" << endl;

	for (int i=0;i<size;i++)
	{
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

void Profile::increseSizeOfFanPageList(){
	this->size_of_liked_pages_ *= 2;
	FanPage** temp = new FanPage * [this->size_of_liked_pages_];
	for (int i = 0; i < this->num_of_liked_pages_; i++)
	{
		temp[i] = this->liked_pages_[i];
	}
	delete[] this->liked_pages_;
	this->liked_pages_ = temp;
}