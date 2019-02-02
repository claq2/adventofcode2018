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

string Day13::Part1(vector<vector<char>> tracks)
{
	map<int, tuple<int, int, Direction, NextJunctionAction>> cartsAndDirections(ExtractCarts(tracks));
	pair<int, int> firstCollision(FindNextCollision(tracks, cartsAndDirections));
	return to_string(firstCollision.first) + "," + to_string(firstCollision.second);
}

string Day13::Part2(std::vector<std::vector<char>> tracks)
{
	map<int, tuple<int, int, Direction, NextJunctionAction>> cartsAndDirections(ExtractCarts(tracks));
	while (cartsAndDirections.size() > 1)
	{
		pair<int, int> nextCollision(FindNextCollision(tracks, cartsAndDirections));

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

		// Remove crashed carts
		bool erasedFirstItem(false);
		for (auto it = cartsAndDirections.begin(); it != cartsAndDirections.end(); it++)
		{
			if (erasedFirstItem)
			{
				it--;
			}

			erasedFirstItem = false;
			if (get<0>((*it).second) == nextCollision.first && get<1>((*it).second) == nextCollision.second)
			{
				if (it == cartsAndDirections.begin())
				{
					erasedFirstItem = true;
				}

				it = cartsAndDirections.erase(it);
			}
		}
	}

	pair<int, tuple<int, int, Direction, NextJunctionAction>> lastCart = *cartsAndDirections.begin();
	int x(get<0>(lastCart.second));
	int y(get<1>(lastCart.second));
	return to_string(x) + "," + to_string(y);
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

map<int, tuple<int, int, Day13::Direction, Day13::NextJunctionAction>> Day13::ExtractCarts(vector<vector<char>> &tracks)
{
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

	return cartsAndDirections;
}

pair<int, int> Day13::FindNextCollision(vector<vector<char>> &tracks, map<int, tuple<int, int, Day13::Direction, Day13::NextJunctionAction>> &cartsAndDirections)
{
	int step(0);
	bool collisionDetected(false);
	while (!collisionDetected)
	{
		// Determine processing order based on location. Top left to bottom right.
			// Map of pair<int,int> automatically ordered.
		map<pair<int, int>, int> cartLocationsToIds;
		for (auto & cart : cartsAndDirections)
		{
			pair<int, int> location{ get<0>(cart.second), get<1>(cart.second) };
			cartLocationsToIds[location] = cart.first;
		}

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
			cartsAndDirections[locationAndId.second] = { nextX, nextY, currentDirection, nextAction };

			// Rebuild cart map based on coordinates, 

			//string state;
			//for (size_t y = 0; y < tracks.size(); y++)
			//{
			//	for (size_t x = 0; x < tracks[y].size(); x++)
			//	{
			//		// If location has a cart write the cart
			//		map<int, tuple<int, int, Direction, NextJunctionAction>>::iterator cartAtCurrentlocation =
			//			find_if(cartsAndDirections.begin(), cartsAndDirections.end(),
			//				[x, y](pair<int, tuple<int, int, Direction, NextJunctionAction>> const &c)
			//		{
			//			return get<0>(c.second) == x && get<1>(c.second) == y;
			//		});
			//		if (cartAtCurrentlocation != cartsAndDirections.end())
			//		{
			//			state += DirectionsToChars[get<2>((*cartAtCurrentlocation).second)];
			//		}
			//		else
			//		{
			//			state += tracks[y][x];
			//		}
			//	}
			//	state += "\r\n";
			//}

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
						return { currentX, currentY };
					}
				}
			}

			step++;
			// Prevent bugs from running this forever
			if (step == 10000)
			{
				return { -1,-1 };
			}
		}
	}
}
