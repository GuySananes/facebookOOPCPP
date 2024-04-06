#ifndef __FAN_PAGE_H
#define __FAN_PAGE_H
using namespace std;

#include "profile.h"
#include <string>

class FanPage
{
private:
	string page_name_;
	Profile** fans_list_;
	int number_of_fans_;
	int size_of_fans_list_;
	Status** status_list_;
	int number_of_status_;
	int size_of_status_list_;

public:
	//constructor
	
	FanPage(const string page_name);

	//distructor
	~FanPage();

	//member function
	void addFan(Profile* fan);
	Profile& operator+=(Profile* fan) { addFan(fan); return *fan; };
	void removeFan(Profile* fan);
	void showAllFans();
	//void showPageName();
	void getFanPageName(string& name);
	void addStatus();
	void addStatus(const string status);
	void showAllStatus();
	void sortStatusesByDate();
	void showLast10Status();
	bool isFan(Profile* profile);
	void increaseSizeOfFansList();
	void increaseSizeOfStatusList();
	int getNumOfStatus();
	Status* getStatus(int index);
	bool operator>(const FanPage& other) const { return this->number_of_fans_ > other.number_of_fans_; }
	bool operator<(const FanPage& other) const { return this->number_of_fans_ < other.number_of_fans_; }


};


#endif // !__FAN_PAGE_H
