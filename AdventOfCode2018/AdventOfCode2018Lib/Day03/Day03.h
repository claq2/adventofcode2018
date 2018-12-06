#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>

using namespace std;

class ADVENTOFCODE2018LIB_API Day03
{
public:
	Day03();
	~Day03();
	int Part1(vector<string> claims);
	string Part2(vector<string> claims);
	vector<string> ReadInput();
};
