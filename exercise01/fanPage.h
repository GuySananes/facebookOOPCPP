#ifndef __FAN_PAGE_H
#define __FAN_PAGE_H
using namespace std;

#include "profile.h"
#include "baseProfile.h"
#include <string>
#include <list>
#include <set>

class FanPage : public baseProfile
{
private:
	set<Profile*> fans_list_;

public:
	//constructor
	
	FanPage(const string page_name):baseProfile(page_name) {};
	FanPage(const FanPage& other) = delete;

	//Destructor
	~FanPage();

	//member function
	void addFan(Profile* fan);
	Profile& operator+=(Profile* fan) { addFan(fan); return *fan; };
	void removeFan(Profile* fan);
	void showAllFans();
	//void showPageName();
	bool isFan(Profile* profile);
	int getNumOfStatus();
	bool operator>(const FanPage& other) const { return this->fans_list_.size() > other.fans_list_.size(); }
	bool operator<(const FanPage& other) const { return this->fans_list_.size() < other.fans_list_.size(); }


};


#endif // !__FAN_PAGE_H
