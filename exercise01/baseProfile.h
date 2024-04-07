#ifndef __BASE_PROFILE_H
#define __BASE_PROFILE_H
#include <string>
#include <list>
#include <map>
#include "status.h"

class baseProfile
{	
	protected:
	string name_;
	list <Status*> status_list_;
	public:
		baseProfile(const string name);
		~baseProfile();
		baseProfile(const baseProfile& other)=delete;
		void addStatus(const string status);
		const string& getName() const { return this->name_; };
		void showAllStatus();
		void showLast10Status();
};

#endif // !__BASE_PROFILE_H
