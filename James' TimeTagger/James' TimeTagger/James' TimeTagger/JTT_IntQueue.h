/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_IntQueue.h
	JTT_IntQueue class header

	This class creates an int queue with the following functions:
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

const int INT_QUEUE_CAPACITY = 1000;

class JTT_IntQueue
{
public:
	JTT_IntQueue();
	bool empty();
	bool full();
	void push(int pushInt);
	void display();
	string stringout();
	int top();
	void pop();
	void erase();
private:
	int myFront;
	int myBack;
	int newBack;
	int myArray[INT_QUEUE_CAPACITY];
};

