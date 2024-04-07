#ifndef __STATUS_H
#define __STATUS_H
using namespace std;

//include
#include "date.h"
#include <string>

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
	string text_;
	int size_of_text_;

public:
	//constructor
	Status(const string status);
	Status(const Status& other) = delete;

	//Destructor
	~Status(){}

	//member function

	void showStatus();
	const Date& getDate();
	
	bool operator==(Status* other)
	{
		return this->text_ == other->text_/*&&this->image_ == other->image_ && this->vid_ == other->vid_*/;
	}
	bool operator!=(Status* other) { return !(*this == other); }

};



#endif // !__STATUS_H

