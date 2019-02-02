#include "stdafx.h"
#include "Day13.h"

using namespace std;

Day13::Day13()
{
}


Day13::~Day13()
{
}

vector<vector<char>> Day13::ReadInput()
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
	return ReadTracks(lines);
}

string Day13::Part1(std::vector<std::vector<char>> tracks)
{
	// Left, straight, then right
	map<int, tuple<int, int, Direction, NextJunctionAction>> cartsAndDirections;
	int x(0), y(0), cartId(0);
	
	// Populate initial cart locations. All next junction actions are rotate left.
	// Replace carts with track characters
	for (auto & tl : tracks)
	{
		x = 0;
		for (auto & tc : tl)
		{
			if (DirectionChars.count(tc) == 1)
			{
				cartsAndDirections[cartId] = { x,y, DirectionChars[tc], NextJunctionAction::RotateLeft };
				cartId++;
				if (tc == '<' or tc == '>')
				{
					tc = '-';
				}
				else
				{
					tc = '|';
				}
			}
			x++;
		}

		y++;
	}

	int step(0);
	bool collisionDetected(false);
	while (!collisionDetected)
	{
		// Determine processing order based on location. Top left to bottom right.
		// Map of pair<int,int> automatically ordered.
		map<pair<int, int>, int> cartLocationsToIds;
		//vector<pair<int, int>> cartLocations;
		for (auto & cart : cartsAndDirections)
		{
			pair<int, int> location{ get<0>(cart.second), get<1>(cart.second) };
			cartLocationsToIds[location] = cart.first;
			//cartLocations.push_back(location);
		}

		//sort(cartLocations.begin(), cartLocations.end());

		/*vector<int> cartIdsInOrderOfProcessing;
		for (auto const & location : cartLocations)
		{
			cartIdsInOrderOfProcessing.push_back(cartLocationsToIds[location]);
		}*/

		for (auto & locationAndId : cartLocationsToIds)
		{
			int currentX(locationAndId.first.first);
			int currentY(locationAndId.first.second);
			Direction currentDirection(get<2>(cartsAndDirections[locationAndId.second]));
			NextJunctionAction nextAction(get<3>(cartsAndDirections[locationAndId.second]));

			// Read next step for each cart
			pair<int, int> toAdd(NumbersToAdd[currentDirection]);
			int nextX(currentX + toAdd.first);
			int nextY(currentY + toAdd.second);
			char nextChar(tracks[nextY][nextX]);
			// Check to see if current char is a junction
		}

		for (auto & cart : cartsAndDirections)
		{
			int currentX(get<0>(cart.second));
			int currentY(get<1>(cart.second));
			Direction currentDirection(get<2>(cart.second));
			NextJunctionAction nextAction(get<3>(cart.second));

			// Read next step for each cart
			pair<int, int> toAdd(NumbersToAdd[currentDirection]);
			int nextX(currentX + toAdd.first);
			int nextY(currentY + toAdd.second);
			char nextChar(tracks[nextY][nextX]);
			// Check to see if current char is a junction
			if (nextChar == '+')
			{
				// Change direction
				if (nextAction == NextJunctionAction::RotateLeft)
				{
					currentDirection = TurnLeftDirections[currentDirection];
				}
				else if (nextAction == NextJunctionAction::GoStraight) // remove?
				{
					currentDirection = GoStraightDirections[currentDirection];
				}
				else if (nextAction == NextJunctionAction::RotateRight)
				{
					currentDirection = TurnRightDirections[currentDirection];
				}

				nextAction = NextJunctionActions[nextAction];
			}
			else
			{
				currentDirection = NextDirections[{ nextChar, currentDirection }];
			}

			// Move
			cartsAndDirections[cart.first] = { nextX, nextY, currentDirection, nextAction };

			// TODO: Check if we just moved onto another cart
		}

		// Rebuild cart map based on coordinates, 

		string state;
		for (size_t y = 0; y < tracks.size(); y++)
		{
			for (size_t x = 0; x < tracks[y].size(); x++)
			{
				// If location has a cart write the cart
				map<int, tuple<int, int, Direction, NextJunctionAction>>::iterator cartAtCurrentlocation = 
					find_if(cartsAndDirections.begin(), cartsAndDirections.end(),
					[x, y](pair<int, tuple<int, int, Direction, NextJunctionAction>> const &c)
					{
						return get<0>(c.second) == x && get<1>(c.second) == y; 
					});
				if (cartAtCurrentlocation != cartsAndDirections.end())
				{
					state += DirectionsToChars[get<2>((*cartAtCurrentlocation).second)];
				}
				else
				{
					state += tracks[y][x];
				}
			}
			state += "\r\n";
		}

		// Detect collisions after moving everything - are any carts on top of each other
		for (auto & cart : cartsAndDirections)
		{
			int currentX(get<0>(cart.second));
			int currentY(get<1>(cart.second));
			for (auto & otherCart : cartsAndDirections)
			{
				int currentOtherX(get<0>(otherCart.second));
				int currentOtherY(get<1>(otherCart.second));
				if (cart != otherCart && currentOtherX == currentX && currentOtherY == currentY)
				{
					return to_string(currentX) + "," + to_string(currentY);
				}
			}
		}

		step++;
		// Prevent bugs from running this forever
		if (step == 10000)
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
