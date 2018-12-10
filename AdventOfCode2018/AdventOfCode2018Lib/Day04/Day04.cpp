#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include "Day04.h"
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

Day04::Day04()
{
}


Day04::~Day04()
{
}

int Day04::Part1(vector<string> claims)
{
	// Guard ID, <total sleep min, <minute, total for that minute>>
	map<int, pair<int, map<int, int>>> guardsTotalTimeAsleepAndMinutesAsleep;

	auto guardLine = [](string line) { return line.find("Guard") != string::npos; };
	auto fellAsleepLine = [](string line) { return line.find("falls asleep") != string::npos; };
	auto wokeUpLine = [](string line) { return line.find("wakes up") != string::npos; };

	int currentGuardId(0);
	int currentDay(0);
	int currentMonth(0);
	int currentHour(0);
	int currentMinute(0);
	bool awake = true;
	for (auto l : claims)
	{
		istringstream iss(l);
		vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());

		// 01234567890 012345
		// [1518-02-24 23:58] Guard #853 begins shift
		currentMonth = stoi(tokens[0].substr(6, 2));
		currentDay = stoi(tokens[0].substr(9, 2));
		currentHour = stoi(tokens[1].substr(0, tokens[1].find(':')));
		currentMinute = stoi(tokens[1].substr(tokens[1].find(':') + 1, 2));

		if (guardLine(l))
		{
			// [1518-02-24 23:58] Guard #853 begins shift
			string guardIdString(tokens[3].substr(1));
			int guardId(stoi(guardIdString));
			currentGuardId = guardId;
			guardsTotalTimeAsleepAndMinutesAsleep[guardId] = {};
		}
		else if (fellAsleepLine(l))
		{
			// [1518-02-25 00:20] falls asleep
		}
		else if (wokeUpLine(l))
		{
			// [1518-02-25 00:43] wakes up
		}
	}

	return 0;
}

int Day04::Part2(vector<string> claims)
{
	return 0;
}

vector<string> Day04::ReadInput()
{
	vector<string> result;
	ifstream file;
	string currentGuardLine;
	//chrono::system_clock::time_point
	//vector<chrono::system_clock::time_point> timePoints;

	file.open("Day04.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	std::tm tm = {};
	while (getline(file, currentGuardLine))
	{
		result.push_back(currentGuardLine);
		//string timeString(currentGuardLine.substr(1, currentGuardLine.find(']')));
		//std::stringstream ss(timeString);
		//ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
		//tm.tm_year += 500;
		////if (tm.tm_yday >= 70 && tm.tm_yday <= 308) // Mar 11 = 70 Nov 4 = 308
		////{
		////	tm.tm_isdst = 0;
		////}
		////else
		////{
		////	tm.tm_isdst = 1;
		////}

		//time_t timet = _mkgmtime(&tm);
		//auto tp = std::chrono::system_clock::from_time_t(timet);
		//result.push_back(tp);

		//std::time_t t = chrono::system_clock::to_time_t(tp);
		//std::cout << std::put_time(gmtime(&t), "%F %T") << std::endl;

	}

	file.close();

	sort(result.begin(), result.end());
	return result;
}

vector<string> Day04::ReadInputRaw()
{
	vector<string> result;
	ifstream file;

	string currentGuardLine;

	file.open("Day04.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	std::tm tm = {};
	while (getline(file, currentGuardLine))
	{
		result.push_back(string("20").append(currentGuardLine.substr(3, currentGuardLine.find(']') - 3)));
	}

	file.close();

	return result;
}
