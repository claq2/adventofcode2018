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
	auto maxPowerStart(FindMaxPower(3, grid));
	return to_string(get<0>(maxPowerStart) + 1) + "," + to_string(get<1>(maxPowerStart) + 1);
}

tuple<int, int, int> Day11::FindMaxPower(int gridSize, vector<vector<int>> grid)
{
	int maxPower(0);
	pair<int, int> maxPowerStart;
	for (int y = 0; y < 300 - gridSize; y++)
	{
		for (int x = 0; x < 300 - gridSize; x++)
		{
			vector<int> toCheck;
			for (int i = 0; i < gridSize; i++)
			{
				int curry = y + i;
				for (int j = 0; j < gridSize; j++)
				{
					toCheck.push_back(grid[curry][x + j]);
				}
			}

			int powerTotal(0);
			for (auto const& t : toCheck)
			{
				powerTotal += t;
			}

			if (powerTotal > maxPower)
			{
				maxPower = powerTotal;
				maxPowerStart = pair<int, int>{ x, y };
			}
		}
	}

	return tuple<int, int, int>(maxPowerStart.first, maxPowerStart.second, maxPower);
}

string Day11::Part2(int input)
{
	pair<int, int> maxPowerStartCoords;
	int maxPowerGridSize(0);
	int maxPower(0);
	auto grid(BuildGrid(input));
	for (int i = 1; i <= 299; i++)
	{
		auto maxPowerStart = FindMaxPower(i, grid);
		if (maxPower < get<2>(maxPowerStart))
		{
			maxPower = get<2>(maxPowerStart);
			maxPowerGridSize = i;
			maxPowerStartCoords = pair<int, int>(get<0>(maxPowerStart), get<1>(maxPowerStart));
		}
	}

	return to_string(get<0>(maxPowerStartCoords) + 1) + "," + to_string(get<1>(maxPowerStartCoords) + 1) + "," + to_string(maxPowerGridSize);
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
	for (int y = 1; y <= 300; y++)
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
