#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>

class ADVENTOFCODE2018LIB_API Day11
{
public:
	Day11();
	~Day11();
	int ReadInput();
	std::string Part1(int input);
	std::string Part2(int input);
	int CalculatePower(int serial, int x, int y);
	std::vector<std::vector<int>> BuildGrid(int serial);
};

