#include "fanPage.h"
#include <iostream>
#include <string.h>

using namespace std;


//constructor
FanPage::FanPage(char* page_name) 
{
	strcpy(this->page_name_, page_name);
	size_of_fans_list_ = 1;
	this->fans_list_ = new Profile*[size_of_fans_list_]();
	this->number_of_fans_ = this->size_of_fans_list_ = 0;
	size_of_status_list_ = 1;
	this->status_list_ = new Status*[size_of_status_list_]();
	this->number_of_status_ = this->size_of_status_list_ = 0;
}

FanPage::FanPage(const char* page_name)
{
	strcpy(page_name_, page_name);
	size_of_fans_list_ = 1;
	fans_list_ = new Profile * [size_of_fans_list_]();
	number_of_fans_ = 0;
	size_of_status_list_ = 1;
	status_list_ = new Status * [size_of_status_list_]();
	number_of_status_ =  0;
}

//distructor
FanPage::~FanPage() 
{
	for (int i = 0; i < this->number_of_fans_; i++)
	{
		delete this->fans_list_[i];
	}
	delete[] this->fans_list_;
}

//member function

void FanPage::getFanPageName(char* name)
{
	strncpy(name, this->page_name_, 20);
	name[19] = '\0';
}

void FanPage::addStatus()
{
	char status[100];
	cout << "Please enter new status:" << endl;
	ws(cin);
	cin.getline(status, 100);
	Status* newStatus = new Status(status);
	if (this->number_of_status_ == this->size_of_status_list_)
	{
		this->increaseSizeOfStatusList();
	}
	this->status_list_[this->number_of_status_++] = newStatus;
}

void FanPage::addStatus(const char* status)
{
	Status* newStatus = new Status(status);
	if (this->number_of_status_ == this->size_of_status_list_)
	{
		this->increaseSizeOfStatusList();
	}
	this->status_list_[this->number_of_status_++] = newStatus;
}

void FanPage::showAllStatus()
{
	for (int i = 0; i < this->number_of_status_; i++)
	{
		this->status_list_[i]->showStatus();
	}
	system("pause");
}

void FanPage::sortStatusesByDate()
{
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < number_of_status_ - 1; i++) {

			if (status_list_[i]->getDate().compareTo(status_list_[i + 1]->getDate()) > 0) {

				Status* temp = status_list_[i];
				status_list_[i] = status_list_[i + 1];
				status_list_[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

void FanPage::showLast10Status()
{
	for (int i = 1; i <= 10; i++)
	{
		this->status_list_[this->number_of_status_ - i]->showStatus();
	}
	system("pause");
}

bool FanPage::isFan(Profile* profile)
{
	for (int i = 0; i < this->number_of_fans_; i++)
	{
		if (this->fans_list_[i] == profile)
		{
			return true;
		}
	}
	return false;
	
}

void FanPage::addFan(Profile* fan)
{
	if (this->number_of_fans_ == this->size_of_fans_list_)
	{
		this->increaseSizeOfFansList();
	}
	this->fans_list_[this->number_of_fans_++] = fan;
}

void FanPage::increaseSizeOfFansList()
{
	this->size_of_fans_list_ *= 2;
	Profile** temp = new Profile * [this->size_of_fans_list_]();
	for (int i = 0; i < this->number_of_fans_; i++)
	{
		temp[i] = this->fans_list_[i];
	}
	delete[] this->fans_list_;
	this->fans_list_ = temp;
}

void FanPage::increaseSizeOfStatusList()
{
	this->size_of_status_list_ *= 2;
	Status** temp = new Status * [this->size_of_status_list_]();
	for (int i = 0; i < this->number_of_status_; i++)
	{
		temp[i] = this->status_list_[i];
	}
	delete[] this->status_list_;
	this->status_list_ = temp;
}

void FanPage::showAllFans()
{
	char name[USER_NAME_LEN];
	for (int i = 0; i < this->number_of_fans_; i++)
	{
		this->fans_list_[i]->getProfileName(name);
		cout << "Fan " << i + 1 << " : " << name << endl;
	}
}

void FanPage::removeFan(Profile* fan)
{
	for (int i = 0; i < this->number_of_fans_; i++)
	{
		if (this->fans_list_[i] == fan)
		{
			for (int j = i; j < this->number_of_fans_; j++)
			{
				this->fans_list_[j] = this->fans_list_[j + 1];
			}
			this->number_of_fans_--;
			return;
		}
	}
}

int FanPage::getNumOfStatus()
{
	return this->number_of_status_;
}

Status * FanPage::getStatus(int index)
{
	return this->status_list_[index];
}