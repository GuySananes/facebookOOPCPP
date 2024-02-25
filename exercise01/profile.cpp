#include "profile.h"
#include <string.h>


//constructor
Profile::Profile(char name_[USER_NAME_LEN],Date& dateOfBirth)
{
	this->date_of_birth_ = dateOfBirth;
	strncpy(this->name_, name_, USER_NAME_LEN - 1);
	
}

//distructor
Profile::~Profile()
{

}