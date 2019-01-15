#pragma once
#include "../AdventOfCode2018Lib.h"

using namespace std;

class ADVENTOFCODE2018LIB_API Day01
{
public:
	Day01();
	~Day01();
	int Part1(vector<int> frequencies);
	int Part2(vector<int> frequencies);
	vector<int> ReadInput();
};

