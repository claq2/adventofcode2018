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

std::string Day15::Part1(vector<vector<char>> map)
{
	return "";
}

std::string Day15::Part2(vector<vector<char>> map)
{
	return "";
}

vector<vector<char>> Day15::ReadMap(vector<string> tracks)
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
