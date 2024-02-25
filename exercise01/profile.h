#ifndef __PROFILE_H
#define __PROFILE_H

//includes
#include "date.h"

#define USER_NAME_LEN 20

class Profile
{
private:
	char name_[USER_NAME_LEN];
	Date date_of_birth_;
	//status_list home_page;
	Profile* friends_list_;
	//pages_list liked_pages;

public:
	// Constructor
	Profile(char name_[USER_NAME_LEN], Date& dateOfBirth);

	//distructor
	~Profile();


};

#endif // !__PROFILE_H