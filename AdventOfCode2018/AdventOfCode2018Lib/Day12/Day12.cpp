#include "stdafx.h"
#include "Day12.h"

using namespace std;

Day12::Day12()
{
}


Day12::~Day12()
{
}

tuple<vector<bool>, vector<map<int, bool>>> Day12::ReadInput()
{
	tuple<vector<bool>, vector<map<int, bool>>> result;
	vector<string> lines;
	ifstream file;
	string currentLine;

	file.open("Day12.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	tm tm = {};
	while (getline(file, currentLine))
	{
		lines.push_back(currentLine);
	}

	file.close();
	/*
  initial state: ###..###....####.###...#..#...##...#..#....#.##.##.#..#.#..##.#####..######....#....##..#...#...#.#

  ..#.# => #
  ###.# => .
*/
	string initialStateLine(lines.front());
	// Erase first 2 lines, leaving only rules
	lines.erase(lines.begin(), lines.begin() + 2);
	// Remove "initial state: "
	initialStateLine = initialStateLine.substr(15);
	for (auto const & i : initialStateLine)
	{
		if (i == '#')
		{
			get<0>(result).push_back(true);
		}
		else
		{
			get<0>(result).push_back(false);
		}
	}

	return result;
}

string Day12::Part1(tuple<vector<bool>, vector<map<int, bool>>> initialStateAndRules)
{
	return string();
}

string Day12::Part2(tuple<vector<bool>, vector<map<int, bool>>> initialStateAndRules)
{
	return string();
}
