#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <chrono>
#include "Day04.h"
#include <iomanip>

Day04::Day04()
{
}


Day04::~Day04()
{
}

int Day04::Part1(vector<string> claims)
{
	return 0;
}

int Day04::Part2(vector<string> claims)
{
	return 0;
}

vector<string> Day04::ReadInput()
{
	ifstream file;
	string currentGuardLine;
	//chrono::system_clock::time_point
	vector<chrono::system_clock::time_point> timePoints;

	file.open("Day04.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	std::tm tm = {};
	while (getline(file, currentGuardLine))
	{
		string timeString(currentGuardLine.substr(1, currentGuardLine.find(']')));
		std::stringstream ss(timeString);
		ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
		tm.tm_isdst = 1;
		tm.tm_year += 500;
		time_t timet = std::mktime(&tm);
		auto tp = std::chrono::system_clock::from_time_t(timet);

		std::time_t t = chrono::system_clock::to_time_t(tp);
		std::cout << std::ctime(&t) << std::endl;
	}

	file.close();

	return {};
}
