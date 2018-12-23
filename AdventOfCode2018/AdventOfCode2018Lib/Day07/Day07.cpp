#include "stdafx.h"
#include "Day07.h"
#include <fstream>


using namespace std;

Day07::Day07()
{
}


Day07::~Day07()
{
}

vector<string> Day07::ReadInput()
{
	vector<string> result;
	ifstream file;
	string currentGuardLine;

	file.open("Day07.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	tm tm = {};
	while (getline(file, currentGuardLine))
	{
		result.push_back(currentGuardLine);
	}

	file.close();
	return result;
}

string Day07::Part1(vector<string> coords)
{
	return "";
}

string Day07::Part2(vector<string> coords)
{
	return "";
}
