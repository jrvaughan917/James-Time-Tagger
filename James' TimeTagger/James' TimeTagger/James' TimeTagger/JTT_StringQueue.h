/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_StringQueue.h
	JTT_StringQueue class header

	This class creates a string queue with the following functions:
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

const int STRING_QUEUE_CAPACITY = 1000;

class JTT_StringQueue
{
public:
	JTT_StringQueue();
	bool empty();
	bool full();
	void push(string pushString);
	void display();
	string top();
	void pop();
	void erase();
private:
	int myFront;
	int myBack;
	int newBack;
	string myArray[STRING_QUEUE_CAPACITY];
};

