#include "fanPage.h"
#include <string.h>


//constructor
FanPage::FanPage(char* page_name) 
{
	this->page_name_ = strdup(page_name);
	this->fans_list_ = new Profile*;
	this->number_of_fans_ = this->size_of_fans_list_ = 0;
}

//distructor
FanPage::~FanPage() 
{
	for (int i = 0; i < this->number_of_fans_; i++)
	{
		delete this->fans_list_[i];
	}
	delete[] this->fans_list_;
	delete this->page_name_;
}
