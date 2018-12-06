#include "stdafx.h"
#include "Day03.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>

Day03::Day03()
{
}


Day03::~Day03()
{
}

int Day03::Part1(vector<FabricClaim> claims)
{
	vector<tuple<int, int, int>> fabricClaimCounts;
	map<tuple<int, int>, int> claimsMap{ {{3,2}, 3} };
	auto x = claimsMap[{3, 2}];
	auto z = claimsMap.count({ 4,5 });
	auto y = claimsMap[{4, 5}];
	auto a = claimsMap.count({ 3,2 });


	return 42;
}

string Day03::Part2(vector<FabricClaim> claims)
{
	return "42";
}

vector<FabricClaim> Day03::ReadInput()
{
	ifstream file;
	string currentClaimLine;
	vector<FabricClaim> claims;

	file.open("Day03.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	while (getline(file, currentClaimLine))
	{
		
		claims.push_back(FabricClaim(currentClaimLine));
		//currentClaimLine
		//claims.push_back(currentClaimLine);
	}

	file.close();

	return claims;
}
