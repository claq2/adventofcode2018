#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include "Day04.h"
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <tuple>

Day04::Day04()
{
}


Day04::~Day04()
{
}

vector<tuple<int, int, int, int, int>> Day04::AllMinutes(string first, string last)
{
	vector<string> datesAndTimes;
	vector<tuple<int, int, int, int, int>> datesAndHours;
	map<UINT, UINT> monthMaxDays({ {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, {7,31}, {8, 31}, {9,30}, {10, 31}, {11, 30} });

	istringstream iss(first);
	vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());
	UINT firstMonth(stoi(tokens[0].substr(6, 2)));
	UINT firstDay(stoi(tokens[0].substr(9, 2)));
	UINT firstHour(stoi(tokens[1].substr(0, tokens[1].find(':'))));
	UINT firstMinute(stoi(tokens[1].substr(tokens[1].find(':') + 1, 2)));

	iss = istringstream(last);
	tokens = vector<string>(istream_iterator<string>{iss}, istream_iterator<string>());
	UINT lastMonth(stoi(tokens[0].substr(6, 2)));
	UINT lastDay(stoi(tokens[0].substr(9, 2)));
	UINT lastHour(stoi(tokens[1].substr(0, tokens[1].find(':'))));
	UINT lastMinute(stoi(tokens[1].substr(tokens[1].find(':') + 1, 2)));

	UINT currentDay(firstDay);
	UINT currentMonth(firstMonth);
	UINT currentHour(firstHour);
	UINT currentMinute(firstMinute);
	UINT year(1518);

	UINT totalMinutes(0);
	UINT totalDays(0);
	for (UINT i = firstMonth + 1; i < lastMonth; i++)
	{
		totalDays += monthMaxDays[i];
	}

	totalMinutes += totalDays * 24 * 60;

	// Find total seconds from first month
	// [1518-02-24 23:58] Guard #853 begins shift
	UINT completeDaysInFirstMonth = monthMaxDays[firstMonth] - firstDay - 1;
	UINT completeHoursInFirstDay = 24 - firstHour - 1;
	UINT completeMinutesInFirstHour = 60 - firstMinute;
	totalMinutes += completeMinutesInFirstHour;
	totalMinutes += completeHoursInFirstDay * 60;
	totalMinutes += completeDaysInFirstMonth * 24 * 60;

	// Find total seconds from last month
	// [1518-11-23 00:48] wakes up
	UINT completeDaysInLastMonth = lastDay - 1;
	UINT completeHoursInLastDay = lastHour;
	UINT completeMinutesInLastHour = lastMinute + 1;
	totalMinutes += completeMinutesInLastHour;
	totalMinutes += completeHoursInLastDay * 60;
	totalMinutes += completeDaysInLastMonth * 24 * 60;

	for (UINT i = 0; i <= totalMinutes; i++)
	{
		datesAndHours.push_back({ year, currentMonth, currentDay, currentHour, currentMinute });
		currentMinute++;
		if (currentMinute == 60)
		{
			currentMinute = 0;
			currentHour++;
			if (currentHour == 24)
			{
				currentHour = 0;
				currentDay++;
				if (currentDay == monthMaxDays[currentMonth] + 1)
				{
					currentDay = 1;
					currentMonth++;
				}
			}
		}
	}

	return datesAndHours;
}

map<int, pair<int, map<int, int>>> Day04::GuardsTotalTimeAsleepAndMinutesAsleep(vector<string> guardEntries)
{
	// y, M, d, h, m
	vector<tuple<int, int, int, int, int>> allMinutes = AllMinutes(guardEntries.front(), guardEntries.back());
	// map {y,M,d,h,m} to {guardId, state}
	map<tuple<int, int, int, int, int>, pair<int, bool>> entriesVector;

	// map Guard ID to {total sleep min, { map minute to total for that minute}}
	map<int, pair<int, map<int, int>>> guardsTotalTimeAsleepAndMinutesAsleep;

	auto guardLine = [](string line) { return line.find("Guard") != string::npos; };
	auto fellAsleepLine = [](string line) { return line.find("falls asleep") != string::npos; };
	auto wokeUpLine = [](string line) { return line.find("wakes up") != string::npos; };

	int currentGuardId(0);
	int currentDay(0);
	int currentMonth(0);
	int currentHour(0);
	int currentMinute(0);
	int currentYear(1518);
	bool awake = true;

	// {y,M,d,h,m}, guardId, awake
	vector<tuple<tuple<int, int, int, int, int>, int, bool>> dateAndGuardIdAndState;

	for (auto l : guardEntries)
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
			entriesVector[{currentYear, currentMonth, currentDay, currentHour, currentMinute }] = { currentGuardId, true };
		}
		else if (fellAsleepLine(l))
		{
			// [1518-02-25 00:20] falls asleep
			entriesVector[{currentYear, currentMonth, currentDay, currentHour, currentMinute }] = { currentGuardId, false };

		}
		else if (wokeUpLine(l))
		{
			// [1518-02-25 00:43] wakes up
			entriesVector[{currentYear, currentMonth, currentDay, currentHour, currentMinute }] = { currentGuardId, true };
		}
	}

	int currentGuardId2(0);
	bool currentState2(true);
	for (auto m : allMinutes)
	{
		if (entriesVector.count(m) == 1)
		{
			currentGuardId2 = entriesVector[m].first;
			currentState2 = entriesVector[m].second;
		}

		if (currentState2 == false)
		{
			// m = current minute
			// entriesVector[m].first = guard ID
			// entriesVector[m].second = gurard state

			// add 1 minute to guard's total asleep time
			guardsTotalTimeAsleepAndMinutesAsleep[currentGuardId2].first++;
			// add 1 to the current minute for the current guard
			guardsTotalTimeAsleepAndMinutesAsleep[currentGuardId2].second[get<4>(m)]++;
		}
	}

	return guardsTotalTimeAsleepAndMinutesAsleep;
}

int Day04::Part1(vector<string> guardEntries)
{
	// map Guard ID to {total sleep min, { map minute to total for that minute}}
	map<int, pair<int, map<int, int>>> guardsTotalTimeAsleepAndMinutesAsleep(GuardsTotalTimeAsleepAndMinutesAsleep(guardEntries));

	int maxMinutes(0);
	int highestGuard(0);
	for (auto x : guardsTotalTimeAsleepAndMinutesAsleep)
	{
		if (x.second.first > maxMinutes)
		{
			maxMinutes = x.second.first;
			highestGuard = x.first;
		}
	}

	int maxMinutes2(0);
	int highestMinute;
	for (auto x : guardsTotalTimeAsleepAndMinutesAsleep[highestGuard].second)
	{
		if (x.second > maxMinutes2)
		{
			maxMinutes2 = x.second;
			highestMinute = x.first;
		}
	}

	return highestGuard * highestMinute;
}

int Day04::Part2(vector<string> guardEntries)
{
	// map Guard ID to {total sleep min, { map minute to total for that minute}}
	map<int, pair<int, map<int, int>>> guardsTotalTimeAsleepAndMinutesAsleep(GuardsTotalTimeAsleepAndMinutesAsleep(guardEntries));

	// map guardid to {max min, max min count}
	map<int, pair<int, int>> guardsAndMaxMinuteAsleepAndTheMinute;

	for (auto x : guardsTotalTimeAsleepAndMinutesAsleep)
	{
		int countTimesAsleepAtMaxMinAsleep(0);
		int maxMinAsleep(0);
		for (auto y : x.second.second)
		{
			if (y.second > countTimesAsleepAtMaxMinAsleep)
			{
				countTimesAsleepAtMaxMinAsleep = y.second;
				maxMinAsleep = y.first;
			}
		}

		guardsAndMaxMinuteAsleepAndTheMinute[x.first] = { maxMinAsleep, countTimesAsleepAtMaxMinAsleep };
	}

	int guardWithMaxMinuteAsleep(0);
	int maxCountSameMinAsleep(0);
	int maxMinuteAsleep(0);
	for (auto x : guardsAndMaxMinuteAsleepAndTheMinute)
	{
		if (x.second.second > maxCountSameMinAsleep)
		{
			maxMinuteAsleep = x.second.first;
			maxCountSameMinAsleep = x.second.second;
			guardWithMaxMinuteAsleep = x.first;
		}
	}

	return guardWithMaxMinuteAsleep * maxMinuteAsleep;
}

vector<string> Day04::ReadInput()
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

	while (getline(file, currentGuardLine))
	{
		result.push_back(currentGuardLine);
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

	while (getline(file, currentGuardLine))
	{
		result.push_back(string("20").append(currentGuardLine.substr(3, currentGuardLine.find(']') - 3)));
	}

	file.close();

	return result;
}
