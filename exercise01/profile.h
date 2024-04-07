#ifndef __PROFILE_H
#define __PROFILE_H

//includes
#include "date.h"
#include "status.h"
#include "baseProfile.h"
#include <map>
#include <list>

class FanPage;

class Profile : public baseProfile
{
private:
	Date date_of_birth_;
	map<string, Profile*> friends_list_;
	map<string, FanPage*> liked_pages_;
	
	
public:
	// Constructor
	
	Profile(const string name_, Date& dateOfBirth);
	Profile(const Profile& other) = delete;

	// Member function
	void addFriend(Profile* newFriend);
	Profile& operator+=(Profile* newFriend) { this->addFriend(newFriend); return *newFriend; }
	void showAllFriends();
	void removeFriend(const string& f_name);
	bool isFriend(Profile* profile);	
	void addFanPage(FanPage* newFanPage);
	FanPage& operator+=(FanPage* newFanPage) { this->addFanPage(newFanPage); return *newFanPage; };
	bool operator>(const Profile& other) const { return this->friends_list_.size() > other.friends_list_.size(); }
	bool operator<(const Profile& other) const { return this->friends_list_.size() < other.friends_list_.size(); }


	//Destructor
	~Profile();


};

#endif