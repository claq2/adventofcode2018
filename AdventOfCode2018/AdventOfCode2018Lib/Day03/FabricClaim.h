#pragma once
#include "../AdventOfCode2018Lib.h"
#include <utility>
#include <string>

using namespace std;

class ADVENTOFCODE2018LIB_API FabricClaim
{
public:
	FabricClaim(string line);
	~FabricClaim();
	int Id;
	int StartX;
	int StartY;
	int Width;
	int Height;
};
