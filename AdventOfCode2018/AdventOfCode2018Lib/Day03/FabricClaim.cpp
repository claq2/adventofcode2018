#include "stdafx.h"
#include "FabricClaim.h"
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

FabricClaim::FabricClaim(string line)
{
	// #1 @ 861,330: 20x10
	istringstream iss(line);
	vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());

	Id = stoi(tokens[0].substr(1));

	auto commaPosition = tokens[2].find(',');
	StartX = stoi(tokens[2].substr(0, commaPosition));
	StartY = stoi(tokens[2].substr(commaPosition + 1, tokens[2].length() - 1 - commaPosition));

	auto xPosition = tokens[3].find('x');
	Width = stoi(tokens[3].substr(0, xPosition));
	Height = stoi(tokens[3].substr(xPosition + 1));
}


FabricClaim::~FabricClaim()
{
}
