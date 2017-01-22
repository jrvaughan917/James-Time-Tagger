/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_StringQueue.cpp
	JTT_StringQueue class file

	For complete documentation, see the header file.

********************************************************************************/

#include "JTT_StringQueue.h"
#include "boost\xpressive\xpressive.hpp"
#include <iostream>

using namespace std;
using namespace boost::xpressive;

JTT_StringQueue::JTT_StringQueue()
{
	myFront = 0;
	myBack = 0;
	newBack = 0;
}

bool JTT_StringQueue::empty()
{
	return (myFront == myBack);
}

bool JTT_StringQueue::full()
{	
	newBack = (myBack+1) % STRING_QUEUE_CAPACITY;
	if (newBack == myFront)
	{return 1;} // Queue is full
	else
	{return 0;} // Queue is not full
}

void JTT_StringQueue::push(string pushString)
{
	newBack = (myBack+1) % STRING_QUEUE_CAPACITY;
	if (newBack != myFront) // Queue is not full
	{
		myArray[myBack] = pushString;
		myBack = newBack;
	}
	else
	{
		cerr << "*** Queue full -- can't add new value\n"
			"Must increase value of STRING_QUEUE_CAPACITY in JTT_StringQueue.h\n";
		exit(1);
	}
}

void JTT_StringQueue::display()
{
	for (int kk = myFront; kk != myBack; kk = (kk+1) % STRING_QUEUE_CAPACITY)
	{
		cout << myArray[kk] << "  ";
		cout << endl;
	}
}

string JTT_StringQueue::top()
{
	if (!empty())
	{
		return (myArray[myFront]);
	} 
	else
	{
		cerr << "*** String Queue is empty -- returning -1 ***\n";
		return "-1";
	}
}

void JTT_StringQueue::pop()
{
	if (!empty())
	{
		myFront = (myFront + 1) % STRING_QUEUE_CAPACITY;
	}
	else
	{
		cerr << "*** Queue is empty --"
			"can't remove a value ***\n";
	}
}

void JTT_StringQueue::erase()
{
	myFront = 0;
	myBack = 0;
}

