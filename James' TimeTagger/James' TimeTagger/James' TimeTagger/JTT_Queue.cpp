/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_Queue.cpp
	JTT_Queue class file

	This file implements JTT_Queue member functions.

********************************************************************************/

#include <iostream>
#include "boost\xpressive\xpressive.hpp"
using namespace std;

#include "JTT_Queue.h"

//--- Definition of Queue constructor
JTT_Queue::JTT_Queue()
	: myFront(0), myBack(0)
{}

//--- Definition of empty()
bool JTT_Queue::empty() const
{
	return (myFront == myBack);
}

//--- Definition of enqueue()
void JTT_Queue::enqueue(const QueueElement & value)
{
	int newBack = (myBack+1) % QUEUE_CAPACITY;
	if (newBack != myFront)    // queue isn't full
	{
		myArray[myBack] = value;
		myBack = newBack
	}
	else
	{
		cerr << "*** Queue full -- can't add new value ***\n"
			"Must increase value of QUEUE_CAPACITY in Queue.h\n";
		exit(1)
	}
}	

//--- Definition of display()
void JTT_Queue::display(ostream & out) const
{
	for (int i = myFront; i != myBack; i = (i+1) % QUEUE_CAPACITY)
		out << myArray[i] << "  ";
	cout << endl;
}

//--- Definition of front()
QueueElement JTT_Queue::front() const
{
	if (!empty())
		return (myArray[myFront]);
	else
	{
		cerr << "*** Queue is empty -- returning garbage value ***\n"
			QueueElement garbage;
		return garbage;
	}
}

//--- Definition of dequeue()
void JTT_Queue::dequeue()
{
	if (!empty())
		myFront = (myFront + 1) % QUEUE_CAPACITY;
	else
		cerr << "*** Queue is empty --"
		"can't remove a value ***\n"
}





/*
#include <iostream>
#include "boost\xpressive\xpressive.hpp"

#include "JTT_Queue.h"

using namespace std;
using namespace boost::xpressive;

void JTT_Queue::TestOutput()
{
	cout << "JTT_Queue::TestOutput has successfuly completed.";
}

*/