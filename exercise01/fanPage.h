#ifndef __FAN_PAGE_H
#define __FAN_PAGE_H
using namespace std;

#include "profile.h"
#include <string>
#include <list>
#include <set>

class FanPage
{
private:
	string page_name_;
	set<Profile*> fans_list_;
	list<Status*> status_list_;

public:
	//constructor
	
	FanPage(const string page_name);

	//Destructor
	~FanPage();

	//member function
	void addFan(Profile* fan);
	Profile& operator+=(Profile* fan) { addFan(fan); return *fan; };
	void removeFan(Profile* fan);
	void showAllFans();
	//void showPageName();
	const string& getFanPageName() const;
	void addStatus();
	void addStatus(const string status);
	void showAllStatus();
	void showLast10Status();
	bool isFan(Profile* profile);
	int getNumOfStatus();
	bool operator>(const FanPage& other) const { return this->fans_list_.size() > other.fans_list_.size(); }
	bool operator<(const FanPage& other) const { return this->fans_list_.size() < other.fans_list_.size(); }


};


#endif // !__FAN_PAGE_H
