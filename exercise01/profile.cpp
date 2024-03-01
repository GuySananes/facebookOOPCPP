#include "profile.h"
#include <string.h>
#include <iostream>
using namespace std;


//constructor
Profile::Profile (char name_[USER_NAME_LEN],Date& dateOfBirth)
{
	this->date_of_birth_ = dateOfBirth;
	strncpy(this->name_, name_, USER_NAME_LEN - 1);
	this->name_[USER_NAME_LEN - 1] = '\0';
	this->num_of_friends_ = 0;
	this->size_of_friends_list_ = 1;
	this->friends_list_ = new Profile*[size_of_friends_list_];	
	this->size_of_status_list_ = 1;
	this->status_list_ = new Status*[size_of_status_list_];
	this->num_of_status_ = 0;

}

Profile::Profile (const char name_[USER_NAME_LEN], Date& dateOfBirth)
{
	this->date_of_birth_ = dateOfBirth;
	strncpy(this->name_, name_, USER_NAME_LEN - 1);
	this->name_[USER_NAME_LEN - 1] = '\0';
	this->num_of_friends_ = 0;
	this->size_of_friends_list_ = 1;
	this->friends_list_ = new Profile * [size_of_friends_list_];
	this->size_of_status_list_ = 1;
	this->status_list_ = new Status * [size_of_status_list_];
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
	delete this->name_;

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
	Status* newStatus = new Status(status);
	this->status_list_[this->num_of_status_++] = newStatus;
}