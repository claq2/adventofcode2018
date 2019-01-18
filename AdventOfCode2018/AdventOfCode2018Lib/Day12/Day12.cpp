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
	const int padding(100);
	auto state = get<0>(initialStateAndRules);
	// Pad state with falses on both ends
	for (int i = 0; i < padding; i++)
	{
		state.insert(state.begin(), false);
		state.push_back(false);
	}

	int plantPotsTotal(0);
	string generations;

	generations = BuildString(state);

	for (int i = 0; i < 20; i++)
	{
		vector<bool> nextGeneration;
		// Check from start + 2 to end - 2
		for (auto it = state.begin() + 2; it != state.end() - 2; it++)
		{
			// Build bitmap of LLCRR
			int bitmap(0);
			for (int localIndex = -2; localIndex < 3; localIndex++)
			{
				if (*(it + localIndex))
				{
					bitmap += pow(2, localIndex + 2);
				}
			}

			if (get<1>(initialStateAndRules).count(bitmap) && get<1>(initialStateAndRules)[bitmap])
			{
				nextGeneration.push_back(true);
			}
			else
			{
				nextGeneration.push_back(false);
			}
		}

		// Re-pad ends with falses
		for (int i = 0; i < 2; i++)
		{
			nextGeneration.insert(nextGeneration.begin(), false);
			nextGeneration.push_back(false);
		}

		state = nextGeneration;
		generations += string("\r\n");
		generations += BuildString(state);
	}

	// Total up the plants' pot numbers
	int index(-padding);
	vector<int> nums;
	for (auto const & s : state)
	{
		if (s)
		{
			plantPotsTotal += index;
			nums.push_back(index);
		}

		index++;
	}

	return to_string(plantPotsTotal);
}

string Day12::BuildString(vector<bool> state)
{
	string result;
	for (auto const & s : state)
	{
		result += s ? '#' : '.';
	}

	return result;
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
