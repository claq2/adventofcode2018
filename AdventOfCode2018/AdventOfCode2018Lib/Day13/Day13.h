#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day13
{
public:
	Day13();
	~Day13();
	std::vector<std::string> ReadInput();
	std::string Part1(std::vector<std::vector<char>> tracks);
	std::string Part2(std::vector<std::vector<char>> tracks);
	enum Direction { Left, Straight, Right };
	std::vector<std::vector<char>> ReadTracks(std::vector<std::string> tracks);
};
