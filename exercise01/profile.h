#ifndef __PROFILE_H
#define __PROFILE_H

//includes
#include "date.h"
#include "status.h"

#define USER_NAME_LEN 20
#define STATUS_LEN 100

class Profile
{
private:
	char name_[USER_NAME_LEN];
	Date date_of_birth_;
	Status** status_list_;
	Profile** friends_list_;
	//pages_list liked_pages;
	int num_of_friends_;
	int size_of_friends_list_;
	int size_of_status_list_;
	int num_of_status_;
	

public:
	// Constructor
	Profile(char name_[USER_NAME_LEN], Date& dateOfBirth);
	Profile(const char name_[USER_NAME_LEN], Date& dateOfBirth);

	// Member function
	void addStatus();
	void getProfileName(char* name);

	//distructor
	~Profile();


};

#endif // !__PROFILE_H