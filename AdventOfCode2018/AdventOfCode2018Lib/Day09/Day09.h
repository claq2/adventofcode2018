#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day09
{
public:
	Day09();
	~Day09();
	std::pair<int, int> ReadInput();
	std::string Part1(std::pair<int, int> values);
	std::string Part2(std::pair<int, int> values);
};

