#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day05
{
public:
	Day05();
	~Day05();
	size_t Part1(std::string polymer);
	size_t Part2(std::string polymer);
	std::string ReadInput();
	std::string ReactPolymer(std::string polymer);
};

