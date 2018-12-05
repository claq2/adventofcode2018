#pragma once
#include <vector>
#include <string>
#include "../AdventOfCode2018Lib.h"

using namespace std;

class ADVENTOFCODE2018LIB_API Day02
{
public:
	Day02();
	~Day02();
	int Part1(vector<string> boxIds);
	vector<string> ReadInput();
	bool HasTwoRepeatedCharacters(string input);
	bool HasThreeRepeatedCharacters(string input);
};
