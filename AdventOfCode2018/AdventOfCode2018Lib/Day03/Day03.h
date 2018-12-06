#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>
#include "FabricClaim.h"

using namespace std;

class ADVENTOFCODE2018LIB_API Day03
{
public:
	Day03();
	~Day03();
	int Part1(vector<FabricClaim> claims);
	string Part2(vector<FabricClaim> claims);
	vector<FabricClaim> ReadInput();
};
