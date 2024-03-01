#include "status.h"
#include <iostream>
#include <ctime>

using namespace std;

//constructor

Status::Status(char* status)
{
	this->type_ = StatusType::text;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	this->date_ = Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
	this->size_of_text_ = strlen(status);
	this->text_ = new char[this->size_of_text_ + 1];
	strcpy(this->text_, status);
	this->text_[this->size_of_text_] = '\0';

}

//member function

void Status::showStatus()
{
	this->date_.showDate();
	cout << " " << this->text_ << endl;
}