#include "fanPage.h"
#include <iostream>
#include <string.h>

using namespace std;


//constructor
FanPage::FanPage(char* page_name) 
{
	strcpy(this->page_name_, page_name);
	this->fans_list_ = new Profile*;
	this->number_of_fans_ = this->size_of_fans_list_ = 0;
	this->status_list_ = new Status*;
	this->number_of_status_ = this->size_of_status_list_ = 0;
}

FanPage::FanPage(const char* page_name)
{
	strcpy(this->page_name_, page_name);
	this->fans_list_ = new Profile*;
	this->number_of_fans_ = this->size_of_fans_list_ = 0;
	this->status_list_ = new Status*;
	this->number_of_status_ = this->size_of_status_list_ = 0;
}

//distructor
FanPage::~FanPage() 
{
	for (int i = 0; i < this->number_of_fans_; i++)
	{
		delete this->fans_list_[i];
	}
	delete[] this->fans_list_;
	delete this->page_name_;
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
	this->status_list_[this->number_of_status_++] = newStatus;
}

void FanPage::addStatus(const char* status)
{
	Status* newStatus = new Status(status);
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