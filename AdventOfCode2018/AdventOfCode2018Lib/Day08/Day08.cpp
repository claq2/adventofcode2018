#include "stdafx.h"
#include "Day08.h"
#include <sstream>
#include <fstream>

using namespace std;

Day08::Day08()
{
}


Day08::~Day08()
{
}

vector<int> Day08::ReadInput()
{
	vector<int> result;
	ifstream file;
	string currentGuardLine;

	file.open("Day08.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	string line;
	getline(file, line);

	file.close();

	istringstream is(line);
	int n;
	while (is >> n) {
		result.push_back(n);
	}

	return result;
}

string Day08::Part1(vector<int> value)
{
	int sum(0);
	Leaf root;
	root.BuildChildren(value);
	return to_string(sum);
}

string Day08::Part2(vector<int> value)
{
	return "";
}


