#pragma once
#include "../AdventOfCode2018Lib.h"
#include <utility>

using namespace std;

class ADVENTOFCODE2018LIB_API FabricClaim
{
public:
	FabricClaim();
	~FabricClaim();
	int Id;
	pair<int, int> Coordinates;
};



FabricClaim::FabricClaim()
{
}


FabricClaim::~FabricClaim()
{
}
