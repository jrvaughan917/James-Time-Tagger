/********************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	Test Driver.cpp
	Test driver file

	This program allows me to run tests on my function
	files.

********************************************************/

#include "iostream"
#include "fstream"
#include "string"

#include "JTT_CharQueue.h"
#include "JTT_StringQueue.h"
#include "JTT_TimeTag.h"


#include "JTT_Utility.h"

using namespace std;
using namespace System;

JTT_TimeTag my_JTT_TimeTag;

int main()
{
	string inputString;

	cout << "T/F " << my_JTT_TimeTag.isNumber("1") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("one") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("a") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber(" ") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("x") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("11") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("111") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("11111") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("y1") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("y123") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("twelfth") << endl;
	cout << "T/F " << my_JTT_TimeTag.isNumber("1") << endl;
	

	cout << "Month " << my_JTT_TimeTag.isMonth("january") << endl;
	cout <<  "Month" << my_JTT_TimeTag.isMonth("JanuaRy") << endl;
	cout  << "Month" << my_JTT_TimeTag.isMonth("Januar") << endl;
	cout  << "Month" << my_JTT_TimeTag.isMonth("slsl") << endl;
	cout  << "Month" << my_JTT_TimeTag.isMonth("1") << endl;
	cout  << "Month" << my_JTT_TimeTag.isMonth("month") << endl;
	cout  << "Month" << my_JTT_TimeTag.isMonth("January") << endl;
	cout  << "Month" << my_JTT_TimeTag.isMonth("January") << endl;
	cout  << "Month" << my_JTT_TimeTag.isMonth("January") << endl;

	cin >> inputString;


    return 0;
}
