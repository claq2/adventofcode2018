#include "stdafx.h"
#include "Day06.h"
#include <sstream>
#include <iterator>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

Day06::Day06()
{
}

Day06::~Day06()
{
}

size_t Day06::Part1(vector<string> coords)
{
	map<pair<int, int>, char> coordMap;
	map<char, int> countOfPoint;

	int maxX(0);
	int maxY(0);
	int pointNum(0);
	for (auto const& c : coords)
	{
		// 1, 1
		istringstream iss(c);
		vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());

		int x(stoi(tokens[0].substr(0, tokens[0].find(','))));
		int y(stoi(tokens[1]));

		coordMap[{x, y}] = pointNum + 65;
		pointNum++;
		if (x > maxX)
		{
			maxX = x;
		}

		if (y > maxY)
		{
			maxY = y;
		}
	}

	cout << endl;
	for (int y = 0; y <= maxY; y++)
	{
		for (int x = 0; x <= maxX + 1; x++)
		{
			if (coordMap.count({ x, y }) == 1)
			{
				cout << coordMap[{x, y}];
				countOfPoint[coordMap[{x, y}]]++;
			}
			else
			{
				int minDistance(1000);
				int minDistanceCount(0);
				char closestPoint;
				for (auto const& c : coordMap)
				{
					if (c.first != pair<int, int>{x, y})
					{
						int distanceToCurrentPoint = ManhattanDistance(c.first, { x, y });
						if (distanceToCurrentPoint < minDistance)
						{
							minDistance = distanceToCurrentPoint;
							minDistanceCount = 1;
							closestPoint = c.second;
						}
						else if (distanceToCurrentPoint == minDistance)
						{
							minDistanceCount++;
						}
					}
				}

				if (minDistanceCount > 1)
				{
					cout << ".";
				}
				else
				{
					countOfPoint[closestPoint]++;
					cout << char(closestPoint + 32);
				}
			}
		}

		cout << endl;
	}

	return size_t();
}

size_t Day06::Part2(vector<string> coords)
{
	return size_t();
}

vector<string> Day06::ReadInput()
{
	vector<string> result;
	ifstream file;
	string currentGuardLine;

	file.open("Day06.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	std::tm tm = {};
	while (getline(file, currentGuardLine))
	{
		result.push_back(currentGuardLine);
	}

	file.close();
	return result;
}

int Day06::ManhattanDistance(std::pair<int, int> point1, std::pair<int, int> point2)
{
	return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}
