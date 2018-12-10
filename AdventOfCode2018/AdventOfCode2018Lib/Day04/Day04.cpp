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
	int currentGuardId = 0;
	for (auto l : claims)
	{
		istringstream iss(l);
		vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());

		if (guardLine(l))
		{
			// [1518-11-06 00:02] Guard #3467 begins shift
			string guardIdString(tokens[3].substr(1));
			int guardId(stoi(guardIdString));
			currentGuardId = guardId;
			guardsTotalTimeAsleepAndMinutesAsleep[guardId] = {};
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
