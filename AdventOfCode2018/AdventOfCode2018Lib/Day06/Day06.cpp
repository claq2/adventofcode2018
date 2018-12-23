#include "stdafx.h"
#include "Day06.h"
#include <sstream>
#include <iterator>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Day06::Day06()
{
}

Day06::~Day06()
{
}

size_t Day06::Part1(vector<string> coords)
{
	typedef int pointType;

	map<Coords, pointType> coordMap;
	int maxX;
	int maxY;

	tie(coordMap, maxX, maxY) = ExtractStuff(coords);

	// Calculate the closest point of each grid point and detect edge points
	map<pointType, size_t> countOfPoint;
	vector<pointType> edgeCoords;
	for (int y = 0; y <= maxY; y++)
	{
		for (int x = 0; x <= maxX + 1; x++)
		{
			if (coordMap.count({ x, y }) == 1)
			{
				countOfPoint[coordMap[{x, y}]]++;
			}
			else
			{
				int minDistance(1000);
				int minDistanceCount(0);
				pointType closestPoint;
				for (auto const& c : coordMap)
				{
					if (c.first != Coords{x, y})
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

				if (x == maxX || x == 0 || y == maxY || y == 0)
				{
					if (find(edgeCoords.begin(), edgeCoords.end(), closestPoint) == edgeCoords.end())
					{
						edgeCoords.push_back(closestPoint);
					}
				}

				if (minDistanceCount = 1)
				{
					countOfPoint[closestPoint]++;
				}
			}
		}
	}

	size_t largestCount(0);
	for (auto const& c : countOfPoint)
	{
		if (c.second > largestCount
			&& find(edgeCoords.begin(), edgeCoords.end(), c.first) == edgeCoords.end())
		{
			largestCount = c.second;
		}
	}

	return largestCount;
}

size_t Day06::Part2(vector<string> coords)
{
	size_t maxTotalDistance(10000);
	typedef int pointType;

	map<Coords, pointType> coordMap;
	int maxX;
	int maxY;

	tie(coordMap, maxX, maxY) = ExtractStuff(coords);

	// Calculate total manhattan distances for each point
	map<Coords, size_t> pointsAndtotalDistances;
	for (int y = 0; y <= maxY; y++)
	{
		for (int x = 0; x <= maxX + 1; x++)
		{
			size_t totalDistances(0);
			for (auto const& c : coordMap)
			{
				totalDistances += ManhattanDistance({ x, y }, c.first);
			}

			pointsAndtotalDistances[{x, y}] = totalDistances;
		}
	}

	size_t countOfPointsLessThanMax(0);
	for (auto const& p : pointsAndtotalDistances)
	{
		if (p.second < maxTotalDistance)
		{
			countOfPointsLessThanMax++;
		}
	}

	return countOfPointsLessThanMax;
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

int Day06::ManhattanDistance(Coords point1, Coords point2)
{
	return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}

tuple<map<Coords, int>, int, int> Day06::ExtractStuff(vector<string> coords)
{
	typedef int pointType;

	map<pair<int, int>, pointType> coordMap;
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

		coordMap[{x, y}] = pointNum;// +65;
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

	return { coordMap, maxX, maxY };
}
