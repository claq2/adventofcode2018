#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>
#include "Node.h"
#include <map>

class ADVENTOFCODE2018LIB_API Day07
{
public:
	Day07();
	~Day07();
	std::vector<std::string> ReadInput();
	std::string Part1(std::vector<std::string> nodeLines);

	std::map<char, Node> BuildGraph(std::vector<std::string> nodeLines);
	

	std::string Part2(std::vector<std::string> nodeLines);
};

