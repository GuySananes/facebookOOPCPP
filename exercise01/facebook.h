#ifndef __FACEBOOK_H
#define __FACEBOOK_H

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


	void addUser();

	void addExistUsers();

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
