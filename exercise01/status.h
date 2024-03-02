#ifndef __STATUS_H
#define __STATUS_H

//include
#include "date.h"

//enum
enum class StatusType
{
	text //, image, video
};

class Status
{
private:
	StatusType type_;
	Date date_;
	char* text_;
	int size_of_text_;

public:
	//constructor
	Status(char* status);
	Status(const char* status);

	//distructor
	~Status()
	{
		delete[] this->text_;
	}

	//member function

	void showStatus();
	Date getDate();



};



#endif // !__STATUS_H

