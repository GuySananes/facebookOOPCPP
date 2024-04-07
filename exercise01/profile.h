#ifndef __PROFILE_H
#define __PROFILE_H
using namespace std;

//includes
#include "date.h"
#include "status.h"
#include <map>
#include <list>

class FanPage;

class Profile
{
private:
	string name_;
	Date date_of_birth_;
	list<Status*> status_list_;
	map<string, Profile*> friends_list_;
	map<string, FanPage*> liked_pages_;
	
	
public:
	// Constructor
	
	Profile(const string name_, Date& dateOfBirth);

	// Member function
	void addStatus();
	void addStatus(const string status);
	const string& getProfileName() const { return this->name_; };
	void showAllStatus();
	void addFriend(Profile* newFriend);
	Profile& operator+=(Profile* newFriend) { this->addFriend(newFriend); return *newFriend; }
	void showAllFriends();
	void removeFriend(const string& f_name);
	void showLast10Status();
	bool isFriend(Profile* profile);	
	void addFanPage(FanPage* newFanPage);
	FanPage& operator+=(FanPage* newFanPage) { this->addFanPage(newFanPage); return *newFanPage; };
	bool operator>(const Profile& other) const { return this->friends_list_.size() > other.friends_list_.size(); }
	bool operator<(const Profile& other) const { return this->friends_list_.size() < other.friends_list_.size(); }


	//Destructor
	~Profile();


};

#endif // !__PROFILE_H