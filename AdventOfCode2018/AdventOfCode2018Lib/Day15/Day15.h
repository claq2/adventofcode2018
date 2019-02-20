#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day15
{
public:
	Day15();
	~Day15();
	std::vector<std::vector<char>> ReadInput();

	std::string Part1(std::vector<std::vector<char>> input);

	std::string Part2(std::vector<std::vector<char>> input);

	std::vector<std::vector<char>> ReadMap(std::vector<std::string> tracks);
};
