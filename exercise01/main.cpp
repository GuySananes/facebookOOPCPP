#include <iostream>
using namespace std;

void main()
{

}

int printMenu()
{
	int return_val;
	cout << "Welcome To FaceBook" << endl
		<< "What do you want to do next?" << endl
		<< "1 - Add a frienf" << endl
		<< "2 - Add a fan page" << endl
		<< "3 - Add status to a friend or fan page" << endl
		<< "4 - Show all status of friend of fan page" << endl
		<< "5 - Show last 10 status of friend or fan page" << endl
		<< "6 - Link friendship for to friends" << endl
		<< "7 - Cancel friendship between two friends" << endl
		<< "8 - Add fan to page" << endl
		<< "9 - Remove fan from page" << endl
		<< "10 - Show all system's enteties" << endl
		<< "11 - Show all friends of a friend or fans of a page" << endl
		<< "12 - Exit" << endl; 
	
	cin >> return_val;
	return return_val;

}

