/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_CharQueue.cpp
	JTT_CharQueue class file

	For complete documentation, see the header file.

********************************************************************************/

#include "JTT_CharQueue.h"
#include "boost\xpressive\xpressive.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace boost::xpressive;

JTT_CharQueue::JTT_CharQueue()
{
	myFront = 0;
	myBack = 0;
	newBack = 0;
}

bool JTT_CharQueue::empty()
{
	return (myFront == myBack);
}

bool JTT_CharQueue::full()
{
	newBack = (myBack+1) % CHAR_QUEUE_CAPACITY;
	if (newBack == myFront)
	{return 1;} // Queue is full
	else
	{return 0;} // Queue is not full
}



void JTT_CharQueue::push(char pushChar)
{
	newBack = (myBack+1) % CHAR_QUEUE_CAPACITY;
	if (newBack != myFront) // Queue is not full
	{
		myArray[myBack] = pushChar;
		myBack = newBack;
	}
	else
	{
		cerr << "*** Queue full -- can't add new value\n"
			"Must increase value of CHAR_QUEUE_CAPACITY in JTT_CharQueue.h\n";
		exit(1);
	}
}

void JTT_CharQueue::display()
{
	for (int kk = myFront; kk != myBack; kk = (kk+1) % CHAR_QUEUE_CAPACITY)
	{
		cout << myArray[kk] << "  ";
		cout << endl;
	}
}

string JTT_CharQueue::stringout()
{
	string returnString;
	for (int kk = myFront; kk != myBack; kk = (kk + 1) % CHAR_QUEUE_CAPACITY)
	{
		returnString.append(std::to_string(myArray[kk]) + "  \n");
	}

	return returnString;
}

char JTT_CharQueue::top()
{
	if (!empty())
	{
		return (myArray[myFront]);
	} 
	else
	{
		cerr << "*** Char Queue is empty -- returning 0 ***\n";
		return '0';
	}
}

void JTT_CharQueue::pop()
{
	if (!empty())
	{
		myFront = (myFront + 1) % CHAR_QUEUE_CAPACITY;
	}
	else
	{
		cerr << "*** Queue is empty --"
			"can't remove a value ***\n";
	}
}

void JTT_CharQueue::erase()
{
	myFront = 0;
	myBack = 0;
}

