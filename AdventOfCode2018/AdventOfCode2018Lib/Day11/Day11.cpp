#include "stdafx.h"
#include "Day11.h"

using namespace std;

Day11::Day11()
{
}


Day11::~Day11()
{
}

int Day11::ReadInput()
{
	return 5535;
}

string Day11::Part1(int input)
{
	auto grid(BuildGrid(input));
	int maxPower(0);
	for (int y = 0; y < 297; y++)
	{
		for (int x = 0; x < 297; x++)
		{
			vector<int> toCheck;
			for (int i = 0; i < 3; i++)
			{

			}
		}
	}

	return "";
}

string Day11::Part2(int input)
{
	return "";
}

int Day11::CalculatePower(int serial, int x, int y)
{
	int rackId(x + 10);
	int powerLevel(rackId * y);
	powerLevel += serial;
	powerLevel *= rackId;
	if (powerLevel > 99)
	{
		// Extract hundreds value
		string powerLevelString(to_string(powerLevel));
		reverse(powerLevelString.begin(), powerLevelString.end());
		powerLevel = powerLevelString[2] - '0';
	}
	else
	{
		powerLevel = 0;
	}

	powerLevel -= 5;

	return powerLevel;
}

vector<vector<int>> Day11::BuildGrid(int serial)
{
	vector<vector<string>> gridValues;
	vector<vector<int>> result;
	for (int y = 1; y <= 300 ; y++)
	{
		result.push_back(vector<int>());
		gridValues.push_back(vector<string>());
		for (int x = 1; x <= 300; x++)
		{
			int power(CalculatePower(serial, x, y));
			result.back().push_back(power);
			gridValues.back().push_back(to_string(x) + "," + to_string(y) + "=" + to_string(power));
		}
	}

	return result;
}
