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
	enum JunctionAction { GoLeft, GoStraight, GoRight };
	enum Direction { Left, Down, Right, Up };
	std::map<char, Direction> DirectionChars
	{
		{ '<', Direction::Left }, 
		{ 'v', Direction::Down },
		{ '>', Direction::Right },
		{ '^', Direction::Up }
	};
	std::vector<std::vector<char>> ReadTracks(std::vector<std::string> tracks);
};
