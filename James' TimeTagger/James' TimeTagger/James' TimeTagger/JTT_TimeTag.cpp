/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_TimeTag.cpp
	JTT_TimeTag class file

	For full documentation, see the header file.

********************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype> // for char tolower
#include "boost\xpressive\xpressive.hpp"
#include <boost/algorithm/string.hpp>

#include "JTT_TimeTag.h"
#include "JTT_CharQueue.h"
#include "JTT_StringQueue.h"
#include "JTT_IntQueue.h"

using namespace std;
using namespace boost::xpressive;

/*** Search word arrays ***/

string numeralSearch[] = 
{
	"1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
};

string numberSearch[] = 
{
	"1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
	"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth",
	"tenth", "eleventh", "twelfth", "thirteenth", "fourteenth", "fifteenth", "sixteenth",
	"seventeenth", "eighteenth", "nineteenth", "twentieth", "thirtieth", "fiftieth",
	"sixtieth", "seventieth", "eightieth", "ninetieth", "hundredth", "thousandth", "millionth", "billionth", "trillionth",
	"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", 
	"19th", "20th", "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st", "32nd", "33rd", "34th", 
	"35th", "36th", "37th", "38th", "39th", "40th", "41st", "42nd",
	"ninety", "eighty", "seventy", "sixty", "fifty", "forty", "thirty", "twenty", "nineteen", "eighteen", "seventeen", "sixteen",
	"fifteen", "fourteen", "thirteen", "twelve", "eleven", "ten", "nine", "eight", "seven", "six", "five", "four", "three", "two", "one",
	"zero", "hundred", "thousand", "million", "trillion",
	"infinite"
};

string yearSearch[] = 
{
	"year"
};
string monthSearch[] = 
{
	"month", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december", 
	"jan", "feb", "mar", "apr", "jun", "jul", "aug", "sept", "oct", "nov", "dec"
};
string weekSearch[] = 
{
	"week", "weekend", "weekday", "fortnight"
};
string daySearch[] = 
{
	"day",
	"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday", 
	"yesterday", "tomorrow", "sabbath", "eve"
};
string seasonSearch[] = 
{
	"summer", "winter", "fall", "autumn", "spring"
};
string epochSearch[] = 
{
	"ad", "bc", "bce",
	"past", "present", "future",
	"decade", "bicentennial", 
	"centennial", "century", "centuries", "millennia", "millennium", "era",
	"stone", "copper", "bronze", "iron", "modern", "post", "post modern", "middle", "ancient", "classical",
	"age", "time", "era", "period", "history", "antiquity", "ages", "times", "eras", "periods", "histories",
	"antiquities",
	"hadean", "archean", "proterozoic", "phanerozic", "paleoarchean", "mesoarchean", "neoarchean", "paleoproterozoic", 
	"mesoproterozoic", "neoproterozoic", "paleozoix", "mesozoic", "phanerozoix", "paleolithic", "paleozoic", "mesozoic", 
	"cenozoic", "cambrian", "ordovician", "silurian", "devonian", "carboniferous", "permian", "triassic", "jurassic", 
	"cretaceous", "paleogene", "neogene", "cenozoic", "paleogene", "neogene", "paleocene", "eocene", "neanderthal", 
	"oligocene", "miocene", "quaternary", "renaissance", "baroque", "medieval", "pliocene", "pleistocene"
};
string hourSearch[] = 
{
	"clock",
	"millisecond", "microsecond", "second", "minute", "hour", "nanosecond",
	"am", "pm", "bc", "a m", "p m", "a d", "b c", "b c e", "ad", "bce", "acdt", "acst", "adt", "aedt", "aest", "akdt", 
	"akst", "ast", "awdt", "awst", "bst", "cdt", "cedt", "cest", "cet", "cst", "cxt", 
	"edt", "eedt", "eest", "eet", "est", "gmt", "hadt", "hae", "hap", "hna", "hnc", "hne", "hnp", "hnr", "hnt", "hny", 
	"mdt", "mesz", "msd", "msk", "mst", "ndt", 
	"nft", "nst", "pdt", "pst", "utc", "wdt", "wedt", "wst",
	"noon", "midnight", "night", "day", "afternoon", "morning", "evening", "dusk", "dawn"
};
string holidaySearch[] = 
{
	"holiday", "christmas", "easter", "thanksgiving", "good friday", "boxing", "new year",
	"labor", "holy", "patrick", "advent", "saints", "souls", "lent", "hanukkah", "chanukah", 
	"passover", "purim", "yom", "kippur", "shabbat", "ramadan", "black", "kwanzaa", "valentine",
	"valentines", "labour", "labor", "father", "mother", "halloween", "martin", "luther", "king",
	"groundhog", "presidents", "earth", "memorial", "boxing", "guy", "fawkes", "fools", "superbowl"
};
string otherSearch[] = 
{
	"old", "new", "every", "during"
};
string dateJoinersSearch[] = 
{
	"before", "after", "ago", "time", "beginning", "end", "start", "was", "had", "been",
	"will", "going", "next", "last", "past",
	"earlier", "later", "mid", "sooner", "recent", "early", "late",
	"number"
};
string nonDateJoinersSearch[] = 
{
	"of", "and", "in", "the", "a", "few", "least", "most", "than", "less", "more", "over", "under", "about", "approximately", 
	"a", "an", "point", "at", "many",
	"s", "is", "o", "a", "m", "b", "c", "e",
	"to", "from",
	"another", "all", "our", "that", "this", "their", "apart", "aside", "away", "hence",
	"aboard", "about", "above", "absent", "across", "after", "against", "along", "alongside", 
	"amid", "amidst", "among", "amongst", "around", "as", "aslant", "astride", "at", "athwart", 
	"atop", "barring", "before", "behind", "below", "beneath", "beside", "besides", "between", 
	"beyond", "but", "by", "concerning", "despite", "down", "during", "except", "failing", 
	"following", "for", "from", "in", "inside", "into", "like", "minus", "near", "next", 
	"notwithstanding", "of", "off", "on", "onto", "opposite", "out", "outside", "over", 
	"past", "per", "plus", "regarding", "round", "save", "since", "than", "through", "throughout", 
	"till", "times", "to", "toward", "towards", "under", "underneath", "unlike", "until", "up", "upon",
	"via", "with", "within", "without", "worth", "did", "didn",
};

string quantitySearch[] = 
{
	"cup", "quart", "gallon", "tbs", "tsp", "dash", "pound", "pinch", "tablespoon", "teaspoon", "gram", 
	"ounce", "oz", "lb", "pint", "mile", "kilometer", "kilometre", "lightyear", "foot", "inch", "meter", "yard"
};
string currencySearch[] = 
{
	"dollar", "cent", "coin", "cash", "money", "fund", "rupee", "shilling", "peso", "pound", "franc", "yen", "yuan", "euro"
};

JTT_TimeTag::JTT_TimeTag()
{
	
}

/*** Search word IS functions ***/
int found;


bool JTT_TimeTag::isNumeral(string numeralString)
{
	for (int zz = 0; zz < (sizeof(numeralSearch)/sizeof(numeralSearch[0])); zz++)
	{
		if (numeralSearch[zz] == "")
		{return false;}

		found = numeralString.find(numeralSearch[zz]);

		if (found != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

bool JTT_TimeTag::isNumber(string numberString)
{
	for (int zz = 0; zz < (sizeof(numberSearch)/sizeof(numberSearch[0])); zz++)
	{
		if (numberSearch[zz] == "")
		{return false;}

		if (numberString == numberSearch[zz])
		{return true;}
	}
	return false;
}
bool JTT_TimeTag::isYear(string yearString)
{
	for (int zz = 0; zz <  (sizeof(yearSearch)/sizeof(yearSearch[0])); zz++)
	{
		if (yearSearch[zz] == "")
		{return false;}

		if (yearString == yearSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isMonth(string monthString)
{
	for (int zz = 0; zz <  (sizeof(monthSearch)/sizeof(monthSearch[0])); zz++)
	{
		if (monthSearch[zz] == "")
		{return false;}

		if (monthString == monthSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isWeek(string weekString)
{
	for (int zz = 0; zz <  (sizeof(weekSearch)/sizeof(weekSearch[0])); zz++)
	{
		if (weekSearch[zz] == "")
		{return false;}

		if (weekString == weekSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isDay(string dayString)
{
	for (int zz = 0; zz <  (sizeof(daySearch)/sizeof(daySearch[0])); zz++)
	{
		if (daySearch[zz] == "")
		{return false;}

		if (dayString == daySearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isSeason(string seasonString)
{
	for (int zz = 0; zz <  (sizeof(seasonSearch)/sizeof(seasonSearch[0])); zz++)
	{
		if (seasonSearch[zz] == "")
		{return false;}

		if (seasonString == seasonSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isEpoch(string epochString)
{
	for (int zz = 0; zz <  (sizeof(epochSearch)/sizeof(epochSearch[0])); zz++)
	{
		if (epochSearch[zz] == "")
		{return false;}

		if (epochString == epochSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isHour(string hourString)
{
	for (int zz = 0; zz <  (sizeof(hourSearch)/sizeof(hourSearch[0])); zz++)
	{
		if (hourSearch[zz] == "")
		{return false;}

		if (hourString == hourSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isHoliday(string holidayString)
{
	for (int zz = 0; zz <  (sizeof(holidaySearch)/sizeof(holidaySearch[0])); zz++)
	{
		if (holidaySearch[zz] == "")
		{return false;}

		if (holidayString == holidaySearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isOther(string otherString)
{
	for (int zz = 0; zz <  (sizeof(otherSearch)/sizeof(otherSearch[0])); zz++)
	{
		if (otherSearch[zz] == "")
		{return false;}

		if (otherString == otherSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isDateJoiners(string dateJoinersString)
{
	for (int zz = 0; zz <  (sizeof(dateJoinersSearch)/sizeof(dateJoinersSearch[0])); zz++)
	{
		if (dateJoinersSearch[zz] == "")
		{return false;}

		if (dateJoinersString == dateJoinersSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isNonDateJoiners(string nonDateJoinersString)
{
	for (int zz = 0; zz <  (sizeof(nonDateJoinersSearch)/sizeof(nonDateJoinersSearch[0])); zz++)
	{
		if (nonDateJoinersSearch[zz] == "")
		{return false;}

		if (nonDateJoinersString == nonDateJoinersSearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isQuantity(string quantityString)
{
	for (int zz = 0; zz <  (sizeof(quantitySearch)/sizeof(quantitySearch[0])); zz++)
	{
		if (quantitySearch[zz] == "")
		{return false;}

		if (quantityString == quantitySearch[zz])
		{return true;}
	}
	return false;
}	
bool JTT_TimeTag::isCurrency(string currencyString)
{
	for (int zz = 0; zz <  (sizeof(currencySearch)/sizeof(currencySearch[0])); zz++)
	{
		if (currencySearch[zz] == "")
		{return false;}

		if (currencyString == currencySearch[zz])
		{return true;}
	}
	return false;
}	




/*** Search word HAS functions ***/
bool JTT_TimeTag::hasNumeral(string numeralString)
{
	for (int zz = 0; zz < (sizeof(numeralSearch)/sizeof(numeralSearch[0])); zz++)
	{
		if (numeralSearch[zz] == "")
		{return false;}

		/*
		found = numeralString.find(numeralSearch[zz]);

		if (found != std::string::npos)
		{
			return true;
		}
		*/

		string word;
		stringstream ss(numeralString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isNumeral(word)) { return true; }
		}
	}
	return false;
}

bool JTT_TimeTag::hasNumber(string numberString)
{
	for (int zz = 0; zz < (sizeof(numberSearch)/sizeof(numberSearch[0])); zz++)
	{
		if (numberSearch[zz] == "")
		{return false;}

		/*
		found = numberString.find(numberSearch[zz]);

		if (found != std::string::npos)
		{
			return true;
		}
		*/

		string word;
		stringstream ss(numberString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isNumber(word)) { return true; }
		}
	}
	return false;
}
bool JTT_TimeTag::hasYear(string yearString)
{
	for (int zz = 0; zz <  (sizeof(yearSearch)/sizeof(yearSearch[0])); zz++)
	{
		if (yearSearch[zz] == "")
		{return false;}

		/*
		found = yearString.find(yearSearch[zz]);

		if (found != std::string::npos)
		{
			return true;
		}
		*/

		string word;
		stringstream ss(yearString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isYear(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasMonth(string monthString)
{
	for (int zz = 0; zz <  (sizeof(monthSearch)/sizeof(monthSearch[0])); zz++)
	{
		if (monthSearch[zz] == "")
		{return false;}

		/*
		found = monthString.find(monthSearch[zz]);

		if (found != std::string::npos)
		{
			return true;
		}
		*/

		string word;
		stringstream ss(monthString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isMonth(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasWeek(string weekString)
{
	for (int zz = 0; zz <  (sizeof(weekSearch)/sizeof(weekSearch[0])); zz++)
	{
		
		if (weekSearch[zz] == "")
		{return false;}

		/*
		found = weekString.find(weekSearch[zz]);

		if (found != std::string::npos)
		{
			return true;
		}
		*/

		string word;
		stringstream ss(weekString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isWeek(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasDay(string dayString)
{
	for (int zz = 0; zz <  (sizeof(daySearch)/sizeof(daySearch[0])); zz++)
	{
		if (daySearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(dayString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isDay(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasSeason(string seasonString)
{
	for (int zz = 0; zz <  (sizeof(seasonSearch)/sizeof(seasonSearch[0])); zz++)
	{
		if (seasonSearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(seasonString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isSeason(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasEpoch(string epochString)
{
	for (int zz = 0; zz <  (sizeof(epochSearch)/sizeof(epochSearch[0])); zz++)
	{
		if (epochSearch[zz] == "")
		{return false;}

		/*
		if (sizeof(epochSearch) < 4)
		{
			found = epochString.find(epochSearch[zz]);

			if (found != std::string::npos)
			{
				return true;
			}
		}
		else
		{
			if (epochString == epochSearch[zz]) { return true; }
		}
		*/
		string word;
		stringstream ss(epochString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isEpoch(word)) { return true; }
		}

	}
	return false;
}	
bool JTT_TimeTag::hasHour(string hourString)
{
	for (int zz = 0; zz <  (sizeof(hourSearch)/sizeof(hourSearch[0])); zz++)
	{
		if (hourSearch[zz] == "")
		{return false;}

		/*
		found = hourString.find(hourSearch[zz]);

		if (found != std::string::npos)
		{
			return true;
		}
		*/

		string word;
		stringstream ss(hourString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isHour(word)) { return true; }
		}

	}
	return false;
}	
bool JTT_TimeTag::hasHoliday(string holidayString)
{
	for (int zz = 0; zz <  (sizeof(holidaySearch)/sizeof(holidaySearch[0])); zz++)
	{
		if (holidaySearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(holidayString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isHoliday(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasOther(string otherString)
{
	for (int zz = 0; zz <  (sizeof(otherSearch)/sizeof(otherSearch[0])); zz++)
	{
		if (otherSearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(otherString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isOther(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasDateJoiners(string dateJoinersString)
{
	for (int zz = 0; zz <  (sizeof(dateJoinersSearch)/sizeof(dateJoinersSearch[0])); zz++)
	{
		if (dateJoinersSearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(dateJoinersString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isDateJoiners(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasNonDateJoiners(string nonDateJoinersString)
{
	for (int zz = 0; zz <  (sizeof(nonDateJoinersSearch)/sizeof(nonDateJoinersSearch[0])); zz++)
	{
		if (nonDateJoinersSearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(nonDateJoinersString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isNonDateJoiners(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasQuantity(string quantityString)
{
	for (int zz = 0; zz <  (sizeof(quantitySearch)/sizeof(quantitySearch[0])); zz++)
	{
		if (quantitySearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(quantityString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isQuantity(word)) { return true; }
		}
	}
	return false;
}	
bool JTT_TimeTag::hasCurrency(string currencyString)
{
	for (int zz = 0; zz <  (sizeof(currencySearch)/sizeof(currencySearch[0])); zz++)
	{
		if (currencySearch[zz] == "")
		{return false;}

		string word;
		stringstream ss(currencyString);
		for (int ii = 0; ss >> word; ii++)
		{
			if (isCurrency(word)) { return true; }
		}
	}
	return false;
}	


void JTT_TimeTag::PerformTimeTagOperation(string InputFilePath, string OutputFilePath)
{	
	string testInput;

	/*** File items ***/
	ifstream myInputFile(InputFilePath);
	ofstream myOutputFile(OutputFilePath);

	/*** Char read items ***/
	JTT_CharQueue charParseQueue;
	JTT_CharQueue charRewriteQueue;
	char inputChar;
	char parseChar;
	string parseCharString;

	/*** Word read items ***/
	int currentChar;
	string myWord = "";
	JTT_StringQueue wordQueue;
	JTT_IntQueue wordStartQueue;
	JTT_IntQueue wordEndQueue;

	/*** Date word read items ***/
	string topWord;
	int topStart;
	int topEnd;
	int lastTopEnd;
	bool haveDatePhrase = false;
	bool isDateWord = false;
	bool wasDateWord = false;
	string datePhrase = "";
	JTT_StringQueue datePhraseQueue;
	JTT_IntQueue datePhraseStartQueue;
	JTT_IntQueue datePhraseEndQueue;
	bool haveWord = false;

	/*** Marked output items ***/
	int markingCurrentChar;
	char topMarkedChar;
	int topMarkedStart = -1;
	int topMarkedEnd = -1;

	/*** Annotated output items ***/
	int annotatedPhraseStart = -1;
	int annotatedPhraseEnd = -1;
	JTT_IntQueue annotatedPhraseStartQueue;
	JTT_IntQueue annotatedPhraseEndQueue;
	string annotatedDatePhrase = "";
	JTT_StringQueue annotatedDatePhraseQueue;

	myOutputFile << "Original file: " << InputFilePath << endl;
	myOutputFile << "This file was annotated by James' TimeTagger." << endl;
	myOutputFile << endl;

	string TestString = "";
	string TestStringAdd = "";

	for (;;) // Program loop, loop continues until eof
	{

		//  1. Empty the char queues.
		//charParseQueue.empty();
		//charRewriteQueue.empty();
		//charParseQueue.erase();
		//charRewriteQueue.erase();

		//	2. Fill up the char queues, max 500 chars:

		for (int bb = 0; bb < 600; bb++)
		{
			myInputFile.get(inputChar);

			if (myInputFile.eof())
			{
				break;
			}

			charParseQueue.push(inputChar);
			charRewriteQueue.push(inputChar);
		}

		//	3 Parsing all the chars into a word queue, start char queue, and end char queue

		currentChar = 0;

		while (!charParseQueue.empty())
		{
			parseChar = charParseQueue.top();
			charParseQueue.pop(); // take the char

			parseChar = tolower(parseChar);

			if (	((parseChar >= 'a') && (parseChar <= 'z'))	||	((parseChar >= '0') && (parseChar <= '9'))	)	// parseChar is letter or number
			{
				if (haveWord == false) // It is the start of a word
				{
					haveWord = true; // we now have a word
					wordStartQueue.push(currentChar); // push this char location as the start of a word
				}

				parseCharString = parseChar; // put the char into a string
				myWord.append(parseCharString); // add the char to myWord
			}
			else // parseChar is not a letter or number
			{
				if (haveWord == true) // the word has ended
				{
					haveWord = false; // we no longer have a word.
					wordQueue.push(myWord); // put myWord into the queue.
					myWord = ""; // make room for a new word.
					wordEndQueue.push(currentChar -1); // push last char as the end of a word
				}

				// if we have no current word, ignore the char and proceed to the next char.
			}

			currentChar++; // move on to the next char
		}

		if (myInputFile.eof() && (haveWord == true))
		{
			wordQueue.push(myWord);
			wordEndQueue.push(currentChar - 1);
			haveWord = false;
			myWord = "";

			// If it's the last word, and the last char, push it.
		}

		// Now the 500 chars have been divided into words.
		// Words are in the queue wordQueue, their starting positions are in queue wordStartQueue
		// Their ending positions are in wordEndQueue
		// Now will search for date words, date words will be combined into a date word string, once a date
		// word string is complete it will be loaded into the string queue

		//	4. Searching for date words

		while (!wordQueue.empty()) // Searching for datewords
		{
			topWord = wordQueue.top();
			wordQueue.pop(); // take the word

			topStart = wordStartQueue.top();
			wordStartQueue.pop(); // take the top starting char

			topEnd = wordEndQueue.top();
			wordEndQueue.pop(); // take the top ending char

			// Analyze the word, see if it is a date word or not

			boost::algorithm::to_lower(topWord);

			isDateWord = false;

			if (isNumeral(topWord)) {isDateWord = true; cout << "1=";}
			if (isNumber(topWord)) {isDateWord = true; cout << "2=";}
			if (isYear(topWord)) {isDateWord = true; cout << "3=";}
			if (isMonth(topWord)) {isDateWord = true; cout << "4=";}
			if (isWeek(topWord)) {isDateWord = true; cout << "5=";}
			if (isDay(topWord)) {isDateWord = true; cout << "6=";}
			if (isSeason(topWord)) {isDateWord = true; cout << "7=";}
			if (isEpoch(topWord)) {isDateWord = true; cout << "8=";}
			if (isHour(topWord)) {isDateWord = true; cout << "9=";}
			if (isHoliday(topWord)) {isDateWord = true; cout << "10=";}
			if (isOther(topWord)) {isDateWord = true; cout << "11=";}
			if (isDateJoiners(topWord)) {isDateWord = true; cout << "12=";}
			if (isNonDateJoiners(topWord) && haveDatePhrase) {isDateWord = true; cout << "13=";}
			if (isQuantity(topWord)) {isDateWord = true; cout << "14=";}
			if (isCurrency(topWord)) {isDateWord = true; cout << "15=";}

			cout << "  ";

			if (isDateWord) // is a date word
			{
				if (haveDatePhrase == true)
				{
					datePhrase.append(" "); // add a space to the date phrase
				}

				if (haveDatePhrase == false) // we are starting a new date phrase
				{
					haveDatePhrase = true; // we now have a date phrase in construction

					datePhraseStartQueue.push(topStart); // push the start of the phrase.
				}
				
				datePhrase.append(topWord); // add the top word to current date phrase
			
				lastTopEnd = topEnd; // this end char may be the end of the whole phrase
			}
			else // is not a date word
			{
				if (haveDatePhrase == true) // we had a date phrase in construction
				{
					haveDatePhrase = false; // we no longer have a date phrase
					datePhraseQueue.push(datePhrase); // push the date phrase
					datePhrase = ""; // make room for a new date phrase

					datePhraseEndQueue.push(lastTopEnd); // last ending is the end of the phrase.
				}

				// if there was no date phrase going on, skip to the next word.
			}
		} // End searching for date words

		if (myInputFile.eof() && (haveDatePhrase == true)) // end of file, and still have date phrase
		{
			datePhraseQueue.push(datePhrase); // push the final date phrase into the queue
			datePhraseEndQueue.push(lastTopEnd); // push final end into end queue
			haveDatePhrase = false;
			datePhrase = "";
			
			// If it's the last word, and the last char, push it.
		}

		// At current, we now have three queues:
		// Queue 1: A list of date phrases
		// Queue 2: A list of the starts of the date phrases
		// Queue 3: A a list of the ends of the date phrases

		// First we will output the date phrases with <<< and >>> around them.
		// To do this we will make use of the datePhraseStartQueue and the datePhraseEndQueue
		// We will use the charRewriteQueue to provide the original text.

		// We will also put the datePhraseStartQueue and datePhraseEndQueue data into the
		// phraseAnalysisStartQueue and phraseAnalysisEndQueues; this will be used later.


		markingCurrentChar = 0;

		//myOutputFile << datePhraseStartQueue.stringout(); // Testing purposes

		//myOutputFile << sizeof(nonDateJoinersSearch) << endl << sizeof(nonDateJoinersSearch[0]); // Testing purposes

		

		while (!charRewriteQueue.empty())
		{
			//TestStringAdd = std::to_string(markingCurrentChar) + ":" + std::to_string(topMarkedStart) + ":" + std::to_string(datePhraseStartQueue.top());
			//if (datePhraseStartQueue.empty()) { TestStringAdd.append(" StartEmpty "); }
			//if (datePhraseEndQueue.empty()) { TestStringAdd.append(" EndEmpty "); }
			//TestStringAdd.append("\n");
			//TestString.append(TestStringAdd);
			
			//myOutputFile << datePhraseStartQueue.display();
			//myOutputFile << datePhraseStartQueue.display();
			
			if (	(topMarkedStart == -1) && (!datePhraseStartQueue.empty())	) // we don't have a "start" char
			{
				topMarkedStart = datePhraseStartQueue.top();
				datePhraseStartQueue.pop(); // load the start char

				if ((topMarkedStart > datePhraseStartQueue.top()) && !(datePhraseStartQueue.empty()))
				{
					topMarkedStart = datePhraseStartQueue.top();
					datePhraseStartQueue.pop();
				}

				//myOutputFile << "TopMarkedStart: " << topMarkedStart;
				annotatedPhraseStartQueue.push(topMarkedStart); // push the start char, this is for annotated output.
				
				TestStringAdd = std::to_string(markingCurrentChar) + ":" + std::to_string(topMarkedStart) + std::to_string(datePhraseStartQueue.top());
				if (datePhraseStartQueue.empty()) { TestStringAdd.append(" StartEmpty "); }
				if (datePhraseEndQueue.empty()) { TestStringAdd.append(" EndEmpty "); }
				TestStringAdd.append("\n");
				TestString.append(TestStringAdd);
			}

			if (	(topMarkedEnd == -1) && (!datePhraseEndQueue.empty())	) // we don't have a "end" char
			{
				topMarkedEnd = datePhraseEndQueue.top();
				datePhraseEndQueue.pop();

				if ((topMarkedEnd > datePhraseEndQueue.top()) && !(datePhraseEndQueue.empty()))
				{
					topMarkedEnd = datePhraseEndQueue.top();
					datePhraseEndQueue.pop();
				}

				//myOutputFile << "TopMarkedEnd: " << topMarkedEnd;
				annotatedPhraseEndQueue.push(topMarkedEnd); // push the end char, this is for annotated output. All end chars will be placed into annotated end char queue.
			}

			topMarkedChar = charRewriteQueue.top();
			charRewriteQueue.pop(); // take the char

			if (markingCurrentChar == topMarkedStart) // current char is a "start" char
			{
				myOutputFile << "<<<";
				//if (datePhraseStartQueue.empty()) { myOutputFile << "EmptyStart" << endl; }
				
				topMarkedStart = -1; // done with that marker
			}

			myOutputFile << topMarkedChar;

			if (markingCurrentChar == topMarkedEnd) // current char is an "end" char
			{
				myOutputFile << ">>>";
				//if (datePhraseEndQueue.empty()) { myOutputFile << "EmptyEnd" << endl; myOutputFile << "TopMarkedStart: " << topMarkedStart;
				//}

				topMarkedEnd = -1; // done with that marker
			}

			markingCurrentChar++;
		}

		// Now that we've output the original text, we can get to outputting the
		// Annotated text.

		datePhrase = "";

		while (!datePhraseQueue.empty()) // for all date phrases // under testing
		{
			
			datePhrase = datePhraseQueue.top();
			datePhraseQueue.pop(); // bring out the top date phrase

			annotatedPhraseStart = annotatedPhraseStartQueue.top(); 
			annotatedPhraseStartQueue.pop(); // start of phrase

			annotatedPhraseEnd = annotatedPhraseEndQueue.top(); 
			annotatedPhraseEndQueue.pop(); // end of phrase

			annotatedDatePhrase = ""; // clear the annotated date phrase
			annotatedDatePhrase.append("</Time:"); // beginning of the annotated phrase

			if (hasNumeral(datePhrase)) {annotatedDatePhrase.append("Numeral,");}
			if (hasNumber(datePhrase)) {annotatedDatePhrase.append("Number,");}
			if (hasYear(datePhrase)) {annotatedDatePhrase.append("Year,");}
			if (hasMonth(datePhrase)) {annotatedDatePhrase.append("Month,");}
			if (hasWeek(datePhrase)) {annotatedDatePhrase.append("Week,");}
			if (hasDay(datePhrase)) {annotatedDatePhrase.append("Day,");}
			if (hasSeason(datePhrase)) {annotatedDatePhrase.append("Season,");}
			if (hasEpoch(datePhrase)) {annotatedDatePhrase.append("Epoch,");}
			if (hasHour(datePhrase)) {annotatedDatePhrase.append("Hour,");}
			if (hasHoliday(datePhrase)) {annotatedDatePhrase.append("Holiday,");}
			if (hasOther(datePhrase)) {annotatedDatePhrase.append("Other,");}
			if (hasDateJoiners(datePhrase)) {annotatedDatePhrase.append("DateJoiner,");}
			if (hasNonDateJoiners(datePhrase)) { annotatedDatePhrase.append("NonDateJoiner,"); } // Under testing
			if (hasQuantity(datePhrase)) {annotatedDatePhrase.append("Quantity,");}
			if (hasCurrency(datePhrase)) {annotatedDatePhrase.append("Currency,");}

			annotatedDatePhrase.append(":\""); // begin quote
			annotatedDatePhrase.append(datePhrase); // the actual phrase
			annotatedDatePhrase.append("\">\n"); // end of annotation

			annotatedDatePhraseQueue.push(annotatedDatePhrase); // push the annotated date phrase

			datePhrase = "";
		}


		// Currently have a queue full of annotated data, need to output that queue

		myOutputFile << endl << endl;


		
		while (!annotatedDatePhraseQueue.empty()) // for all annotated date phrases
		{
			myOutputFile << annotatedDatePhraseQueue.top();
			annotatedDatePhraseQueue.pop(); // outputting the data.
			myOutputFile << "";
		}
		

		myOutputFile << endl << endl;

		if (myInputFile.eof())
		{break;}
	} // End Program Loop

	// myOutputFile << TestString; // Testing purposes
}