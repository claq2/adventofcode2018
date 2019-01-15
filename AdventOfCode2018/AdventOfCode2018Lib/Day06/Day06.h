#pragma once
#include "../AdventOfCode2018Lib.h"

typedef std::pair<int, int> Coords;

class ADVENTOFCODE2018LIB_API Day06
{
public:
	Day06();
	~Day06();
	size_t Part1(std::vector<std::string> coords);
	size_t Part2(std::vector<std::string> coords);
	std::vector<std::string> ReadInput();
	int ManhattanDistance(Coords point1, Coords point2);
	std::tuple<std::map<Coords, int>, int, int> ExtractStuff(std::vector<std::string> coords);
};

