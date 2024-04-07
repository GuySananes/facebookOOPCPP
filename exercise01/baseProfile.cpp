#include "baseProfile.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

baseProfile::baseProfile(const string name)
{
	this->name_ = name;
}

baseProfile::~baseProfile()
{
	for (list<Status*>::iterator it = this->status_list_.begin(); it != this->status_list_.end(); it++)
	{
		delete *it;
	}
}

void baseProfile::addStatus(const string status)
{
	Status* newStatus = new Status(status);
	this->status_list_.push_front(newStatus);
}

void baseProfile::showAllStatus()
{
	for (list<Status*>::iterator it = this->status_list_.begin(); it != this->status_list_.end(); it++)
	{
		(*it)->showStatus();
	}
	system("pause");
}

void baseProfile::showLast10Status()
{
	int i = 0;
	for (list<Status*>::iterator it = this->status_list_.begin(); it != this->status_list_.end() && i < 10; it++, i++)
	{
		(*it)->showStatus();
	}
}





