#include "stdafx.h"
#include "Day09.h"
#include <fstream>

using namespace std;

Day09::Day09()
{
}

Day09::~Day09()
{
}

std::string Day09::ReadInput()
{
	vector<int> result;
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
	return line;
}

std::string Day09::Part1(std::string values)
{
	return std::string();
}

std::string Day09::Part2(std::string values)
{
	return std::string();
}
