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
	map<pair<int, int>, int> claimsMap;// { { {3, 2}, 3} };

	for (auto const & c : claims)
	{
		vector<pair<int, int>> currentPairs;
		// Build the list of pairs for the claim
		for (int x = 0; x < c.Width; x++)
		{
			for (int y = 0; y < c.Height; y++)
			{
				currentPairs.push_back({ x + c.StartX, y + c.StartY });
			}
		}

		for (auto const& p : currentPairs)
		{
			claimsMap[p]++;
		}
	}

	int countOfOverlapping = 0;
	for (auto const& p: claimsMap)
	{
		if (p.second > 1)
		{
			countOfOverlapping++;
		}
	}

	return countOfOverlapping;
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
