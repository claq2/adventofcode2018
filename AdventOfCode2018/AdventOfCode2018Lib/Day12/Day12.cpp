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
	auto rules = get<1>(initialStateAndRules);
	// Pad state with falses on both ends
	vector <bool> paddingVector;
	for (int i = 0; i < padding; i++)
	{
		paddingVector.push_back(false);
	}

	state.insert(state.begin(), paddingVector.begin(), paddingVector.end());
	state.insert(state.end(), paddingVector.begin(), paddingVector.end());

	int plantPotsTotal(0);
	string generations;

	generations = "0:" + BuildString(state);

	for (int i = 0; i < 20; i++)
	{
		state = CalculateNextGeneration(state, rules);
		generations += string("\r\n");
		generations += to_string(i + 1) + ":";
		generations += BuildString(state);
	}

	plantPotsTotal = CalculatePotsTotal(state);
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
	auto state = get<0>(initialStateAndRules);
	auto rules = get<1>(initialStateAndRules);
	// Pad state with falses on both ends
	vector <bool> paddingVector;
	for (int i = 0; i < padding; i++)
	{
		paddingVector.push_back(false);
	}

	state.insert(state.begin(), paddingVector.begin(), paddingVector.end());
	state.insert(state.end(), paddingVector.begin(), paddingVector.end());

	long long plantPotsTotal(0);
	string generations;

	generations = "0:" + BuildString(state);
	long long previousTotal(CalculatePotsTotal(state));
	long long currentTotal(0);
	long long previousDifference(currentTotal - previousTotal);
	long long currentDifference(0);
	long long generation(0);
	long long previousCount(count(state.begin(), state.end(), true));
	long long currentCount(0);
	for (long long i = 0; i < 2000; i++)
	{
		state = CalculateNextGeneration(state, rules);
		currentTotal = CalculatePotsTotal(state);
		currentDifference = currentTotal - previousTotal;
		currentCount = count(state.begin(), state.end(), true);
		// Look for a repeating pattern of same number of plants changing by the same number each generation
		if (currentCount == previousCount && currentDifference == previousDifference)
		{
			break;
		}
		else
		{
			generation++;
			previousCount = currentCount;
			previousDifference = currentDifference;
			previousTotal = currentTotal;
		}

		generations += string("\r\n");
		generations += to_string(i + 1) + ":";
		generations += BuildString(state);
	}

	// Total up the plants' pot numbers
	long long index(-padding);
	//vector<long long> nums;
	for (auto const & s : state)
	{
		if (s)
		{
			plantPotsTotal += index;
			//nums.push_back(index);
		}

		index++;
	}

	return to_string(plantPotsTotal);
}

long long Day12::CalculatePotsTotal(vector<bool> state)
{
	long long plantPotsTotal(0);
	// Total up the plants' pot numbers
	long long index(-padding);
	for (auto const & s : state)
	{
		if (s)
		{
			plantPotsTotal += index;
		}

		index++;
	}

	return plantPotsTotal;
}

vector<bool> Day12::CalculateNextGeneration(vector<bool> state, map<int, bool> rules)
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

		if (rules.count(bitmap) && rules[bitmap])
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

	//state = nextGeneration;
	/*generations += string("\r\n");
	generations += to_string(i + 1) + ":";
	generations += BuildString(state);*/

	//// Total up the plants' pot numbers
	//long long index(-padding);
	//long long localPlantPotsTotal(0);
	////vector<long long> nums;
	//for (auto const & s : state)
	//{
	//	if (s)
	//	{
	//		localPlantPotsTotal += index;
	//		//nums.push_back(index);
	//	}

	//	index++;
	//}

	return nextGeneration;
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
