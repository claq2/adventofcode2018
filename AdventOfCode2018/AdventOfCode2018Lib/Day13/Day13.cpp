#include "stdafx.h"
#include "Day13.h"

using namespace std;

Day13::Day13()
{
}


Day13::~Day13()
{
}

string Day13::ReadInput()
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

	tm tm = {};
	while (getline(file, currentLine))
	{
		lines.push_back(currentLine);
	}

	file.close();
	return string();
}

string Day13::Part1(string tracks)
{
	return string();
}

string Day13::Part2(string tracks)
{
	return string();
}

string Day13::ParseInput(string input)
{
	return string();
}
