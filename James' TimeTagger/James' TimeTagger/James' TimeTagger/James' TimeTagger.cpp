/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	James' TimeTagger.cpp
	Main Project file

	This program reads an input text file.
	It outputs two files.
	One file is the original input file with all date and time phrases marked.
	The other file is a list of all time data found in the input text. 

	For complete documentation see the header files.

********************************************************************************/

#include "iostream"
#include "fstream"
#include "string"

#include "JTT_Utility.h"
#include "JTT_TimeTag.h"

using namespace std;
using namespace System;

int main()
{
	int InterfaceStatus = 0;
	string InterfaceInput = "0";
	JTT_Utility my_JTT_Utility;
	string InputFilePath;
	string OutputFilePath;
	ifstream MyInputFile;
	ofstream MyOutputFile;

	/*******
	InterfaceStatus:
	0 Main Menu
	1 Load input file
	2 About
	3 Exit
	4 Load input file error
	5 Load output file
	6 Load output file error
	7 Load output file success
	8 Beginning Time Tagging operation
	9 Completed Time Tagging operation
	*******/
	
	while (InterfaceStatus != 3) // Program loop
	{
		if (InterfaceStatus == 0) // Main menu
		{
			// Cleaning up (in case a successful operation has already been accomplished):
			InputFilePath = "";
			OutputFilePath = "";

			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Main Menu" << endl;
			cout << endl;
			cout << "1. Load Input File" << endl;
			cout << "2. About This Program" << endl;
			cout << "3. Exit" << endl;
			cout << endl;
			cout << "Please enter your selection followed by the ENTER key. ";

			cin >> InterfaceInput;

			if (InterfaceInput == "1")
			{InterfaceStatus = 1;}
			else if (InterfaceInput == "2")
			{InterfaceStatus = 2;}
			else if (InterfaceInput == "3")
			{InterfaceStatus = 3;}
			else
			{InterfaceStatus = 0;}
		} // End main menu

		if (InterfaceStatus == 1) // Load input file
		{
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Load Input File" << endl;
			cout << endl;
			cout << "To return to the Main Menu, press 1 followed by the ENTER key." << endl;
			cout << endl;
			cout << "Please enter the full filepath of the file in the space below:" << endl;
			cout << "(For example, C:\\Users\\James\\Desktop\\FILENAME.txt)" << endl; // \\ comes out as a single slash			
			cout << endl;

			cout << "     ";
			cin >> InputFilePath;

			if (InputFilePath == "1")
			{InterfaceStatus = 0;} // Return to main menu

			if (InterfaceStatus != 0) // Loading input file
			{
				MyInputFile.open(InputFilePath);

				if (MyInputFile.is_open() == 0) // Failed to load
				{InterfaceStatus = 4;}

				if (MyInputFile.is_open() == 1) // Successfully loaded
				{InterfaceStatus = 5;}
			} // End loading input file

		} // End load input file

		if (InterfaceStatus == 2) // About
		{
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "About This Program" << endl;
			cout << endl;
			cout << "This program is able to load a text file, and then search that file for time or" << endl;
			cout << "date related words and phrases. Then, it can an output a file. The output file" << endl;
			cout << "contains the original text, with all time phrases outlined with <<< and >>>" << endl;
			cout << "marks. The output file also annotates all the date and time phrases. This" << endl;
			cout << "program makes use of the Queue data structure." << endl;
			cout << endl;
			cout << "To return to the Main Menu, press 1 followed by the ENTER key. ";

			cin >> InterfaceInput;

			if (InterfaceInput == "1")
			{InterfaceStatus = 0;}
			else
			{InterfaceStatus = 2;}
		} // End about

		if (InterfaceStatus == 4) // Load input file error
		{
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Load Input File" << endl;
			cout << endl;
			cout << "Attempted to load file:" << endl;
			cout << endl;
			cout << "     ";
			cout << InputFilePath << endl;
			cout << endl;
			cout << "Error! Unable to load the input file!" << endl;
			cout << endl;
			cout << "To return to the Load Input File screen, press 1 followed by the ENTER key. ";

			cin >> InterfaceInput;

			if (InterfaceInput == "1")
			{InterfaceStatus = 1;}
			else 
			{InterfaceStatus = 4;}
		} // End load input file error

		if (InterfaceStatus == 5) // Load output file
		{
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Load Output File" << endl;
			cout << endl;
			cout << "Successfully loaded input file:" << endl;
			cout << endl;
			cout << "     ";
			cout << InputFilePath << endl;
			cout << endl;
			cout << "To return to the Main Menu, press 1 followed by the ENTER key." << endl;
			cout << endl;
			cout << "Please enter the full filepath of the output file in the space below:" << endl;
			cout << "(For example, C:\\Users\\James\\Desktop\\OUTPUTFILENAME.txt)" << endl; // \\ comes out as a single slash
			cout << endl;

			cout << "     ";
			cin >> OutputFilePath;

			if (OutputFilePath == "1")
			{InterfaceStatus = 0;} // Return to main menu

			if (InterfaceStatus != 0) // Loading output file
			{
				MyOutputFile.open(OutputFilePath);

				if (MyOutputFile.is_open() == 0) // Failed to load
				{InterfaceStatus = 6;}
				else if (OutputFilePath == InputFilePath) // Input and output files cannot be the same file
				{InterfaceStatus = 6;}
				else // Successfully loaded
				{InterfaceStatus = 7;}
			} // End loading output file

		} // End load output file

		if (InterfaceStatus == 6) // Load output file error
		{
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Attempted to load output file:" << endl;
			cout << endl;
			cout << "     ";
			cout << OutputFilePath << endl;
			cout << endl;
			cout << "Error! Unable to load the output file!" << endl;
			cout << endl;
			cout << "To return to the Load Output File screen, press 1 followed by the ENTER key. ";

			cin >> InterfaceInput;

			if (InterfaceInput == "1")
			{InterfaceStatus = 5;}
			else 
			{InterfaceStatus = 6;}
		} // End load output file error

		if (InterfaceStatus == 7) // Load output file success
		{
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Successfully loaded input file:" << endl;
			cout << endl;
			cout << "     ";
			cout << InputFilePath << endl;
			cout << endl;
			cout << "Successfully loaded output file:" << endl;
			cout << endl;
			cout << "     ";
			cout << OutputFilePath << endl;
			cout << endl;
			cout << "Would you like to proceed with the time tagging operation?" << endl;
			cout << endl;
			cout << "To perform the time tagging operation, press Y followed by the ENTER Key." << endl;
			cout << "To return to the Main Menu, press 1 followed by the ENTER key. ";

			cin >> InterfaceInput;

			if ((InterfaceInput == "Y") || (InterfaceInput == "y"))
			{InterfaceStatus = 8;}
			else if (InterfaceInput == "1") //
			{InterfaceStatus = 0;}
			else
			{InterfaceStatus = 7;}
		} // End load output file success

		if (InterfaceStatus == 8) // Beginning Time Tagging Operation
		{
			// Operation begins below:
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Performing Time Tagging Operation" << endl;
			cout << endl;
			cout << "Input file:" << endl;
			cout << endl;
			cout << "     ";
			cout << InputFilePath << endl;
			cout << endl;
			cout << "Output file:" << endl;
			cout << endl;
			cout << "     ";
			cout << OutputFilePath << endl;
			cout << endl;
			cout << "Operation in progress, please wait... ";

			// Operation code below:
			MyInputFile.close();
			MyOutputFile.close();

			JTT_TimeTag my_JTT_TimeTag;
			
			my_JTT_TimeTag.PerformTimeTagOperation(InputFilePath, OutputFilePath);

			// Operation complete interface:
			InterfaceStatus = 9;
		} // End Beginning Time Tagging Operation

		if (InterfaceStatus == 9) // Completed Time Tagging Operation
		{
			system("CLS");

			my_JTT_Utility.MainMenuBanner();
			cout << endl;
			cout << "Performing Time Tagging Operation" << endl;
			cout << endl;
			cout << "Input file:" << endl;
			cout << endl;
			cout << "     ";
			cout << InputFilePath << endl;
			cout << endl;
			cout << "Output file:" << endl;
			cout << endl;
			cout << "     ";
			cout << OutputFilePath << endl;
			cout << endl;
			cout << "Time tagging operation is complete. The output file is ready for use." << endl;
			cout << endl;
			cout << "To return to the Main Menu, press 1 followed by the ENTER key." << endl;
			cout << "To exit, press 3 followed by the ENTER key. ";
			
			cin >> InterfaceInput;

			if (InterfaceInput == "1")
			{InterfaceStatus = 0;}
			else if (InterfaceInput == "3")
			{InterfaceStatus = 3;}
			else
			{InterfaceStatus = 9;}

		} // End Completed Time Tagging Operation

	} // End program loop

    return 0;
}
