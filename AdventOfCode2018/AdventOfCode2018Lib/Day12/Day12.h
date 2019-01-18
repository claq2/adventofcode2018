#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day12
{
public:
	Day12();
	~Day12();
	std::tuple<std::vector<bool>, std::map<int, bool>> ReadInput();
	std::string Part1(std::tuple<std::vector<bool>, std::map<int, bool>> initialStateAndRules);
	std::string BuildString(std::vector<bool> state);
	std::string Part2(std::tuple<std::vector<bool>, std::map<int, bool>> initialStateAndRules);
	long long CalculatePotsTotal(std::vector<bool> state);
	std::vector<bool> CalculateNextGeneration(std::vector<bool> state, std::map<int, bool> rules);
	std::tuple<std::vector<bool>, std::map<int, bool>> ParseInput(std::vector<std::string> lines);
	const long long padding = 2000;
};

