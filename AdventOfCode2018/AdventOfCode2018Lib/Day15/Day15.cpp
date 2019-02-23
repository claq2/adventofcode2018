#include "stdafx.h"
#include "Day15.h"

using namespace std;

Day15::Day15() {}
Day15::~Day15() {}

vector<vector<char>> Day15::ReadInput()
{
	vector<string> lines;
	ifstream file;
	string currentLine;

	file.open("Day15.txt");
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
	return ReadMap(lines);
}

std::string Day15::Part1(vector<vector<char>> cavern)
{
	map<int, tuple<int, int, Creature, int>> creatresAndLocations(ExtractCreatures(cavern));
	return "";
}

std::string Day15::Part2(vector<vector<char>> cavern)
{
	return "";
}

vector<vector<char>> Day15::ReadMap(vector<string> cavern)
{
	vector<vector<char>> result;
	for (auto const & cl : cavern)
	{
		result.push_back(vector<char>());
		for (auto const & c : cl)
		{
			result.back().push_back(c);
		}
	}

	return result;
}

map<int, tuple<int, int, Day15::Creature, int>> Day15::ExtractCreatures(vector<vector<char>> &cavern)
{
	map<int, tuple<int, int, Creature, int>> creatures;
	int x(0);
	int y(0);
	int creatureId(0);

	// Populate initial creature locations.
	// Replace creatures with cavern characters
	for (auto & cl : cavern)
	{
		x = 0;
		for (auto & cc : cl)
		{
			if (CreatureChars.count(cc) == 1)
			{
				creatures[creatureId] = { x, y, CreatureChars[cc], 200 }; // 200 hit points
				creatureId++;
				cc = '.';
			}

			x++;
		}

		y++;
	}

	return creatures;
}
