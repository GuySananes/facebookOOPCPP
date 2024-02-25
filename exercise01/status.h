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

public:
	//constructor
	Status() {};



};



#endif // !__STATUS_H

