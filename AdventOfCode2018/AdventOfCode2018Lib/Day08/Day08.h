#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>

class ADVENTOFCODE2018LIB_API Day08
{
public:
	Day08();
	~Day08();
	std::vector<int> ReadInput();
	std::string Part1(std::vector<int> value);
	std::string Part2(std::vector<int> value);
};

