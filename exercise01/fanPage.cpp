#include "fanPage.h"
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;



//Destructor
FanPage::~FanPage() 
{
	
}

//member function


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
		cout << "Fan " << index + 1 << " : " << profile->getName() << endl;
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
