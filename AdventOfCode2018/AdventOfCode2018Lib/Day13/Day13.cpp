#include "stdafx.h"
#include "Day13.h"

using namespace std;

Day13::Day13()
{
}


Day13::~Day13()
{
}

vector<string> Day13::ReadInput()
{
	vector<string> lines;
	ifstream file;
	string currentLine;

	file.open("Day13.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	while (getline(file, currentLine))
	{
		lines.push_back(currentLine);
	}

	file.close();
	return lines;
}

string Day13::Part1(std::vector<std::vector<char>> tracks)
{
	// Left, straight, then right
	map<int, tuple<int, int, Direction>> cartsAndDirections;
	int x(0), y(0), cartId(0);
	
	// Populate initial cart locations
	for (auto const & tl : tracks)
	{
		x = 0;
		for (auto const & tc : tl)
		{
			if (DirectionChars.count(tc) == 1)
			{
				cartsAndDirections[cartId] = { x,y, DirectionChars[tc] };
				cartId++;
			}
			x++;
		}

		y++;
	}

	int step(0);
	bool collisionDetected(false);
	while (!collisionDetected)
	{
		for (auto & cart : cartsAndDirections)
		{
			// Check to see if current char is a junction
			int currentX(get<0>(cart.second));
			int currentY(get<1>(cart.second));
			Direction currentDirection(get<2>(cart.second));
			if (tracks[currentY][currentX] == '+')
			{
				// Change direction
				if (currentDirection == Direction::)
			}

			// Read next step for each cart
			pair<int, int> toAdd(NumbersToAdd[currentDirection]);
			int nextX(currentX + toAdd.first);
			int nextY(currentY + toAdd.second);
			char nextChar(tracks[nextY][nextX]);
			Direction nextDirection(NextDirections[{ nextChar, currentDirection }]);
			// Move
			cartsAndDirections[cart.first] = { nextX, nextY, nextDirection };
			int x(9);

			// Detect collisions - did any carts just move to the same location as another cart
		}

		step++;
		// Prevent bugs from running this forever
		if (step == 100)
		{
			break;
		}
	}

	return string();
}

string Day13::Part2(std::vector<std::vector<char>> tracks)
{
	return string();
}

vector<vector<char>> Day13::ReadTracks(vector<string> tracks)
{
	vector<vector<char>> result;
	for (auto const & tl : tracks)
	{
		result.push_back(vector<char>());
		for (auto const & c : tl)
		{
			result.back().push_back(c);
		}
	}

	return result;
}
