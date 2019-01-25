#include "stdafx.h"
#include "Day13.h"

using namespace std;

Day13::Day13()
{
}


Day13::~Day13()
{
}

vector<string> Day13::ReadInput()
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
	return lines;
}

string Day13::Part1(std::vector<std::vector<char>> tracks)
{
	// Left, straight, then right
	return string();
}

string Day13::Part2(std::vector<std::vector<char>> tracks)
{
	return string();
}

vector<vector<char>> Day13::ReadTracks(vector<string> tracks)
{
	return vector<vector<char>>();
}
