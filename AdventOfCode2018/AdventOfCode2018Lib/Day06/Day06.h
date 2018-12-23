#include <string>
#include <vector>
#include "../AdventOfCode2018Lib.h"
#pragma once
#include <utility>
#include <map>

class ADVENTOFCODE2018LIB_API Day06
{
public:
	Day06();
	~Day06();
	size_t Part1(std::vector<std::string> coords);
	size_t Part2(std::vector<std::string> coords);
	std::vector<std::string> ReadInput();
	int ManhattanDistance(std::pair<int, int> point1, std::pair<int, int> point2);
	std::tuple<std::map<std::pair<int, int>, int>, int, int> ExtractStuff(std::vector<std::string> coords);
};

