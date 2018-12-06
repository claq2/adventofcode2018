#include "stdafx.h"
#include "Day03.h"
#include <fstream>
#include <sstream>
#include <iterator>

Day03::Day03()
{
}


Day03::~Day03()
{
}

int Day03::Part1(vector<FabricClaim> claims)
{
	auto claimsMap = this->MapClaims(claims);
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

int Day03::Part2(vector<FabricClaim> claims)
{
	int currentClaimId = 0;
	auto claimsMap = this->MapClaims(claims);
	for (auto const& c: claims)
	{
		currentClaimId = c.Id;
		bool foundOverlap = false;
		// Check all the spots for the current claim for overlaps
		for (int x = 0; x < c.Width; x++)
		{
			for (int y = 0; y < c.Height; y++)
			{
				if (claimsMap[{ x + c.StartX, y + c.StartX }] > 1)
				{
					foundOverlap = true;
				}
			}
		}

		if (!foundOverlap)
		{
			return currentClaimId;
		}
	}

	return 0;
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
	}

	file.close();

	return claims;
}

map<pair<int, int>, int> Day03::MapClaims(vector<FabricClaim> claims)
{
	map<pair<int, int>, int> claimsMap;

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

	return claimsMap;
}
