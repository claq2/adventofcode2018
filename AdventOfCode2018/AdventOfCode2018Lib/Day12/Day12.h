#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day12
{
public:
	Day12();
	~Day12();
	std::tuple< std::vector<bool>, std::vector<std::map<int, bool>>> ReadInput();
	std::string Part1(std::tuple< std::vector<bool>, std::vector<std::map<int, bool>>> initialStateAndRules);
	std::string Part2(std::tuple< std::vector<bool>, std::vector<std::map<int, bool>>> initialStateAndRules);
};

