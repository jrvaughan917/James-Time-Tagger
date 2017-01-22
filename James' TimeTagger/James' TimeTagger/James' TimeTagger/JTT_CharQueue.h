/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_CharQueue.h
	JTT_CharQueue class header

	This class creates a char queue with the following functions:
		Constructor
		empty
		push
		top
		pop
		display
		erase

********************************************************************************/

#include <string>
using namespace std;

const int CHAR_QUEUE_CAPACITY = 1000;

class JTT_CharQueue
{
public:
	JTT_CharQueue();
	bool empty();
	bool full();
	void push(char pushChar);
	void display();
	string stringout();
	char top();
	void pop();
	void erase();
private:
	int myFront;
	int myBack;
	int newBack;
	char myArray[CHAR_QUEUE_CAPACITY];
};

