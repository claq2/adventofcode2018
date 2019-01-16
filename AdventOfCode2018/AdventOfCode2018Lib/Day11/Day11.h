#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day11
{
public:
	Day11();
	~Day11();
	int ReadInput();
	std::string Part1(int input);
	std::tuple<int, int, int> FindMaxPower(int gridSize, std::vector<std::vector<int>> grid);
	std::string Part2(int input);
	int CalculatePower(int serial, int x, int y);
	std::vector<std::vector<int>> BuildGrid(int serial);
};

