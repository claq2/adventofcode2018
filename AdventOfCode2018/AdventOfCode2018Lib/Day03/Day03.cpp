#include "stdafx.h"
#include "Day03.h"
#include <fstream>

Day03::Day03()
{
}


Day03::~Day03()
{
}

int Day03::Part1(vector<string> claims)
{
	return 42;
}

string Day03::Part2(vector<string> claims)
{
	return "42";
}

vector<string> Day03::ReadInput()
{
	ifstream file;
	string currentClaim;
	vector<string> claims;

	file.open("Day03.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	while (getline(file, currentClaim))
	{
		claims.push_back(currentClaim);
	}

	file.close();

	return claims;
}
