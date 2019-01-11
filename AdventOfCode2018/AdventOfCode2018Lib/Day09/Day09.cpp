#include "stdafx.h"
#include "Day09.h"
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

Day09::Day09()
{
}

Day09::~Day09()
{
}

pair<int, int> Day09::ReadInput()
{
	vector<string> result;
	ifstream file;

	file.open("Day09.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	string line;
	getline(file, line);

	file.close();

	istringstream is(line);
	// 10 players; last marble is worth 1618 points
	string n;
	while (is >> n) {
		result.push_back(n);
	}

	pair<int, int> numbers({ stoi(result[0]), stoi(result[6]) });
	return numbers;
}

string Day09::Part1(pair<int, int> values)
{
	int players = values.first;
	int marbles = values.second;
	list<int> circle({ 0 });
	for (int i = 1; i <= marbles; i++)
	{
		circle.push_back(i);
	}

	return std::string();
}

string Day09::Part2(pair<int, int> values)
{
	return std::string();
}
