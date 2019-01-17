#include "stdafx.h"
#include "Day12.h"

using namespace std;

Day12::Day12()
{
}


Day12::~Day12()
{
}

tuple<vector<bool>, map<int, bool>> Day12::ReadInput()
{
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

	tuple<vector<bool>, map<int, bool>> result(ParseInput(lines));
	return result;
}

string Day12::Part1(tuple<vector<bool>, map<int, bool>> initialStateAndRules)
{
	auto state = get<0>(initialStateAndRules);
	const vector<bool> padding{ false, false, false, false, false };
	int totalPlants(0);
	for (int i = 0; i < 21; i++)
	{
		vector<bool> nextGeneration;
		// Pad beginning with up to 5 falses
		while (!equal(state.begin(), state.begin() + 5, padding.begin()))
		{
			state.insert(state.begin(), false);
		}

		while (!equal(state.end() - 5, state.end(), padding.begin()))
		{
			state.push_back(false);
		}

		// Check from start + 2 to end - 2
		for (auto it = state.begin() + 2; it < state.end() - 2; it++)
		{
			// Build bitmap of LLCRR
			int bitmap(0);
			for (int localIndex = -2; localIndex < 3; localIndex++)
			{
				if (*(it + localIndex))
				{
					bitmap += pow(2, localIndex);
				}
			}

			if (get<1>(initialStateAndRules).count(bitmap) && get<1>(initialStateAndRules)[bitmap])
			{
				state.push_back(true);
				totalPlants++;
			}
			else
			{
				state.push_back(false);
			}
		}

		state = nextGeneration;
	}

	return to_string(totalPlants);
}

string Day12::Part2(tuple<vector<bool>, map<int, bool>> initialStateAndRules)
{
	return string();
}

tuple<vector<bool>, map<int, bool>> Day12::ParseInput(vector<string> lines)
{
	/*
  initial state: ###..###....####.###...#..#...##...#..#....#.##.##.#..#.#..##.#####..######....#....##..#...#...#.#

  ..#.# => #
  ###.# => .
*/
	tuple<vector<bool>, map<int, bool>> result;
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
		else if (i == '.')
		{
			get<0>(result).push_back(false);
		}
		else
		{
			throw exception("Found bad input");
		}
	}

	for (auto const & r : lines)
	{
		int val(0);
		for (int i = 0; i < 5; i++)
		{
			if (r[i] == '#')
			{
				val += pow(2, i);
			}
			else if (r[i] == '.')
			{
				//nothing
			}
			else
			{
				throw exception("Found bad input");
			}
		}

		bool ruleResult(r.back() == '#');
		if (get<1>(result).count(val) != 0)
		{
			throw exception("Duplicate rule");
		}

		get<1>(result)[val] = ruleResult;
	}

	return result;
}
