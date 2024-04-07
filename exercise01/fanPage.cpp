#include "fanPage.h"
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


//constructor

FanPage::FanPage(const string page_name)
{
	this->page_name_ = page_name;
}

//Destructor
FanPage::~FanPage() 
{
	/*for(auto profile: this->fans_list_)
	{
		if(this->fans_list_.find(profile) != this->fans_list_.end())
			delete profile;
	}*/

	for (auto status : this->status_list_)
	{
		delete status;
	}
}

//member function

const string& FanPage::getFanPageName() const
{
	return this->page_name_;
}

void FanPage::addStatus()
{
	string status;
	cout << "Please enter new status:" << endl;
	ws(cin);
	cin >> status;
	this->addStatus(status);
}

void FanPage::addStatus(const string status)
{
	this->status_list_.push_front(new Status(status));
}

void FanPage::showAllStatus()
{
	
	for (auto status : this->status_list_)
	{
		status->showStatus();
	}
	system("pause");
}


void FanPage::showLast10Status()
{
	int counter = 1;
	for (auto status : this->status_list_)
	{
		if (counter++ == 10) break;
		status->showStatus();
	}

	system("pause");
}

bool FanPage::isFan(Profile* profile)
{
	return this->fans_list_.find(profile) != this->fans_list_.end();
}

void FanPage::addFan(Profile* fan)
{
	this->fans_list_.insert(fan);
	fan->addFanPage(this);
}

void FanPage::showAllFans()
{
	string name;
	int index = 0;
	
	for(auto profile:this->fans_list_)
	{				
		cout << "Fan " << index + 1 << " : " << profile->getProfileName() << endl;
		index++;
	}
}

void FanPage::removeFan(Profile* fan)
{
	this->fans_list_.erase(fan);
	
}

int FanPage::getNumOfStatus()
{
	return (int)this->status_list_.size();
}
