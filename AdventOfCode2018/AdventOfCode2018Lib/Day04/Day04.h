#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class ADVENTOFCODE2018LIB_API Day04
{
public:
	Day04();
	~Day04();
	int Part1(vector<string> guardEntries);
	int Part2(vector<string> guardEntries);
	vector<string> ReadInput();
	vector<string> ReadInputRaw();
private:
	vector<tuple<int, int, int, int, int>> AllMinutes(string first, string last);
	map<int, pair<int, map<int, int>>> GuardsTotalTimeAsleepAndMinutesAsleep(vector<string> guardEntries);
};
