#ifndef __PROFILE_H
#define __PROFILE_H

//includes
#include "date.h"

#define USER_NAME_LEN 20

class Profile
{
private:
	char name[USER_NAME_LEN];
	Date birth_date;
	//status_list home_page;
	Profile* friends;
	//pages_list liked_pages;

public:
	// Constructor
	Profile(char name[USER_NAME_LEN], Date& dateOfBirth);

	
};

#endif // !__PROFILE_H