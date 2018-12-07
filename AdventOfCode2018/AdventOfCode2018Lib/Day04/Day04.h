#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>

using namespace std;

class ADVENTOFCODE2018LIB_API Day04
{
public:
	Day04();
	~Day04();
	int Part1(vector<string> claims);
	int Part2(vector<string> claims);
	vector<string> ReadInput();
};
