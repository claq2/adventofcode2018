#pragma once
#include "../AdventOfCode2018Lib.h"
#include "FabricClaim.h"

using namespace std;

class ADVENTOFCODE2018LIB_API Day03
{
public:
	Day03();
	~Day03();
	int Part1(vector<FabricClaim> claims);
	int Part2(vector<FabricClaim> claims);
	vector<FabricClaim> ReadInput();
private:
	map<pair<int, int>, int> MapClaims(vector<FabricClaim> claims);
};
