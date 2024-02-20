#include "profile.h"
#include <string.h>

Profile::Profile(char name[USER_NAME_LEN],Date& dateOfBirth){
	this->birth_date = dateOfBirth;
	strncpy(this->name, name, USER_NAME_LEN - 1);
	
}