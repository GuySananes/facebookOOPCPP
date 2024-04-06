#include "status.h"
#include <iostream>
#include <ctime>

using namespace std;

//constructor

Status::Status(const string status)
{
	this->type_ = StatusType::text;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	this->date_ = Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
	this->size_of_text_ = (int)status.length();
	this->text_ = status;
}

//member function

void Status::showStatus()
{
	this->date_.showDate();
	cout << " " << this->text_ << endl;
}

Date Status::getDate()
{
	return this->date_;
}