#ifndef __FACEBOOK_H
#define __FACEBOOK_H

enum class Command
{
	ADD_USER = 1,
	ADD_FAN_PAGE,
	ADD_STATUS,
	SHOW_ALL_STATUS,
	SHOW_LAST_10_STATUS,
	LINK_FRIENDSHIP,
	CANCEL_FRIENDSHIP,
	ADD_FAN_TO_PAGE,
	REMOVE_FAN_FROM_PAGE,
	SHOW_ALL_SYSTEM_ENTETIES,
	SHOW_ALL_FRIENDS,
	EXIT
};


//include
class Profile;
class FanPage;


class Facebook
{
private:

	Profile** usersList_;
	int numOfUser_;
	FanPage** fanPagesList_;
	int numOfFanPage_;

	FanPage** fanPageList_;
	int numOfPages;

public:
	//constructor
	Facebook();

	//distructor
	~Facebook();

	//member function

	int mainMenu();

	void fDo(int command);

	void addExistUsers();

	void addUser();

	void addFanPage();

	void addStatus();

	void showAllProfile();

	void showAllunlinkedProfile(Profile* profile);

	void showAllFanPage();

	void showAllStatus();

	void showLast10Status();

	void linkFriendship(); 

	void cancelFriendship();

	void addFanToPage();

	void showAllPotentialFan(FanPage* page);

	void removeFanFromPage();

	void showAllSystemEnteties();	

	void showAllFriendsOrFans();

	void showAllFriends();

	void exit();

	void removeUser()
	{
		//TODO
	}

	void updateStatus()
	{
		//TODO
	}
};

#endif //!__FACEBOOK_H
