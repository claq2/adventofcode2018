#include "stdafx.h"
#include "Day05.h"
#include <fstream>

Day05::Day05()
{
}


Day05::~Day05()
{
}

int Day05::Part1(string polymer)
{
	return 0;
}

int Day05::Part2(string polymer)
{
	return 0;
}

std::string Day05::ReadInput()
{
	string result;
	ifstream file;

	file.open("Day05.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	std::tm tm = {};
	getline(file, result);

	file.close();

	return result;
}
