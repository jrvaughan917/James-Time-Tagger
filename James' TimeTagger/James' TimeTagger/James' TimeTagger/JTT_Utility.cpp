/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_Utility.cpp
	JTT_Utility class file

	This class provides some basic utility functions
	such as displaying the main menu banner.

********************************************************************************/

#include <iostream>
#include "boost\xpressive\xpressive.hpp"

#include "JTT_Utility.h"

using namespace std;
using namespace boost::xpressive;

void JTT_Utility::TestOutput()
{
	cout << "JTT_Utility::TestOutput has successfuly completed.";
}

void JTT_Utility::MainMenuBanner()
{
	cout << "===============================================================================" << endl;
	cout << "                            James' TimeTagger v. 1.0" << endl;
	cout << endl;
	cout << "                                By James Vaughan" << endl;
	cout << endl;
	cout << "                               Professor Ping Chen" << endl;
	cout << "                 CS 3304 Data and Information Structures Tu 8:30" << endl;
	cout << "                                   Spring 2013" << endl;
	cout << "===============================================================================" << endl;
}