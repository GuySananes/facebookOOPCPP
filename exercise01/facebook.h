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

class Facebook
{
private:

	Profile** usersList_;
	int numOfUser_;

public:
	//constructor
	Facebook();

	//distructor
	~Facebook();

	//member function

	int mainMenu();

	void fDo(int command) {};

	void addExistUsers();

	void addUser();

	void addFanPage()
	{
		//TODO
	}

	void showAllStatus()
	{
		//TODO
	}

	void showLast10Status()
	{
		//TODO
	}

	void linkFriendship()
	{
		//TODO
	}

	void cancelFriendship()
	{
		//TODO
	}

	void addFanToPage()
	{
		//TODO
	}

	void removeFanFromPage()
	{
		//TODO
	}

	void showAllSystemEnteties()
	{
		//TODO
	}

	void showAllFriends()
	{
		//TODO
	}

	void exit()
	{
		//TODO
	}

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
