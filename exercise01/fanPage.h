#ifndef __FAN_PAGE_H
#define __FAN_PAGE_H

#include "profile.h"

class FanPage
{
private:
	char page_name_[20];
	Profile** fans_list_;
	int number_of_fans_;
	int size_of_fans_list_;
	Status** status_list_;
	int number_of_status_;
	int size_of_status_list_;

public:
	//constructor
	FanPage(char* page_name);
	FanPage(const char* page_name);

	//distructor
	~FanPage();

	//member function
	void addFan(Profile* fan);
	void removeFan(Profile* fan);
	void showAllFans();
	void showPageName();
	void getFanPageName(char* name);
	void addStatus();
	void addStatus(const char* status);
	void showAllStatus();
	void sortStatusesByDate();
	void showLast10Status();
	bool isFan(Profile* profile);
	void increaseSizeOfFansList();
	void increaseSizeOfStatusList();
	int getNumOfStatus();
	Status* getStatus(int index);


};


#endif // !__FAN_PAGE_H
