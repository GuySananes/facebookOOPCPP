#ifndef __PROFILE_H
#define __PROFILE_H

//includes
#include "date.h"

class Profile
{
private:
	char name[20];
	Date birth_date;
	//status_list home_page;
	Profile* friends;
	//pages_list liked_pages;

public:
	// Constructor
	Profile(char name[20], Date& dateOfBirth);

	
};

#endif // !__PROFILE_H