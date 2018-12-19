#include "stdafx.h"
#include "Day06.h"
#include <sstream>
#include <iterator>
#include <fstream>
#include <iostream>

using namespace std;

Day06::Day06()
{
}

Day06::~Day06()
{
}

size_t Day06::Part1(vector<string> coords)
{
	vector<pair<int, int>> coordVector;

	int maxX(0);
	int maxY(0);
	for (auto const& c : coords)
	{
		// 1, 1
		istringstream iss(c);
		vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());

		coordVector.push_back({
			stoi(tokens[0].substr(0, tokens[0].find(','))),
			stoi(tokens[1])
			});
		if (coordVector.back().first > maxX)
		{
			maxX = coordVector.back().first;
		}

		if (coordVector.back().second > maxY)
		{
			maxY = coordVector.back().second;
		}
	}

	cout << endl;
	for (int x = 0; x < maxX; x++)
	{
		for (int y = 0; y < maxY; y++)
		{
			cout << ".";
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
