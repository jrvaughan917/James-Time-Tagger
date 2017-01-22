/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_TimeTag.h
	JTT_TimeTag class header

	This class performs the time tagging operation.
	It receives data from an input file and puts data into an output file.

********************************************************************************/

#include <string>
#include <fstream>

using namespace std;


class JTT_TimeTag
{
public:
	JTT_TimeTag();
	void PerformTimeTagOperation(string MyInputFile, string MyOutPutFile);

	bool isNumeral(string numberString);
	bool isNumber(string numberString);
	bool isYear(string yearString);
	bool isMonth(string monthString);
	bool isWeek(string weekString);
	bool isDay(string dayString);
	bool isSeason(string seasonString);
	bool isEpoch(string epochString);
	bool isHour(string hourString);
	bool isHoliday(string holidayString);
	bool isOther(string otherString);
	bool isDateJoiners(string dateJoinersString);
	bool isNonDateJoiners(string nonDateJoinersString);
	bool isQuantity(string quantityString);
	bool isCurrency(string currencyString);

	bool hasNumeral(string numberString);
	bool hasNumber(string numberString);
	bool hasYear(string yearString);
	bool hasMonth(string monthString);
	bool hasWeek(string weekString);
	bool hasDay(string dayString);
	bool hasSeason(string seasonString);
	bool hasEpoch(string epochString);
	bool hasHour(string hourString);
	bool hasHoliday(string holidayString);
	bool hasOther(string otherString);
	bool hasDateJoiners(string dateJoinersString);
	bool hasNonDateJoiners(string nonDateJoinersString);
	bool hasQuantity(string quantityString);
	bool hasCurrency(string currencyString);

private:
	ifstream myInputFile;
	ofstream myOutputFile;


};