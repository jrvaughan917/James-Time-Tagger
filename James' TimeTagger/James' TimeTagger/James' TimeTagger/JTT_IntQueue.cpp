/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_IntQueue.cpp
	JTT_IntQueue class file

	For complete documentation, see the header file.

********************************************************************************/

#include "JTT_IntQueue.h"
#include "boost\xpressive\xpressive.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace boost::xpressive;

JTT_IntQueue::JTT_IntQueue()
{
	myFront = 0;
	myBack = 0;
	newBack = 0;
}

bool JTT_IntQueue::empty()
{
	return (myFront == myBack);
}

bool JTT_IntQueue::full()
{	
	newBack = (myBack+1) % INT_QUEUE_CAPACITY;
	if (newBack == myFront)
	{return 1;} // Queue is full
	else
	{return 0;} // Queue is not full
}

void JTT_IntQueue::push(int pushInt)
{
	newBack = (myBack+1) % INT_QUEUE_CAPACITY;
	if (newBack != myFront) // Queue is not full
	{
		myArray[myBack] = pushInt;
		myBack = newBack;
	}
	else
	{
		cerr << "*** Queue full -- can't add new value\n"
			"Must increase value of INT_QUEUE_CAPACITY in JTT_IntQueue.h\n";
		exit(1);
	}
}

void JTT_IntQueue::display()
{
	for (int kk = myFront; kk != myBack; kk = (kk+1) % INT_QUEUE_CAPACITY)
	{
		cout << myArray[kk] << "  ";
		cout << endl;
	}
}

string JTT_IntQueue::stringout()
{
	string returnString;
	for (int kk = myFront; kk != myBack; kk = (kk + 1) % INT_QUEUE_CAPACITY)
	{
		returnString.append(std::to_string(myArray[kk]) + "  \n");
	}

	return returnString;
}

int JTT_IntQueue::top()
{
	if (!empty())
	{
		return (myArray[myFront]);
	} 
	else
	{
		cerr << "*** Int Queue is empty -- returning -1 ***\n";
		return -1;
	}
}

void JTT_IntQueue::pop()
{
	if (!empty())
	{
		myFront = (myFront + 1) % INT_QUEUE_CAPACITY;
	}
	else
	{
		cerr << "*** Queue is empty --"
			"can't remove a value ***\n";
	}
}

void JTT_IntQueue::erase()
{
	myFront = 0;
	myBack = 0;
}

