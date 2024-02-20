#ifndef __STATUS_H
#define __STATUS_H

//include
#include "date.h"

//enum
enum class StatusType
{
	text
};

class Status
{
	StatusType type;
	Date date;

};



#endif // !__STATUS_H

