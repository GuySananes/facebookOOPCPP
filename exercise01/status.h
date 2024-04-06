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
	
	bool operator==(Status* other)
	{ return strcmp(this->text_, other->text_/*&&strcmp(this->image_, other->image_ && strcmp(this->vid_, other->vid_*/); }
	bool operator!=(Status* other) { return !(*this == other); }
	}

};



#endif // !__STATUS_H

