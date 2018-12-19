#include <string>
#include <vector>
#include "../AdventOfCode2018Lib.h"
#pragma once

class ADVENTOFCODE2018LIB_API Day06
{
public:
	Day06();
	~Day06();
	size_t Part1(std::vector<std::string> coords);
	size_t Part2(std::vector<std::string> coords);
	std::vector<std::string> ReadInput();
};

