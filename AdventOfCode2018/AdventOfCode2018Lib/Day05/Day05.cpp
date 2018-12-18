#include "stdafx.h"
#include "Day05.h"
#include <fstream>
#include <list>
#include <iostream>

using namespace std;

Day05::Day05()
{
}


Day05::~Day05()
{
}

size_t Day05::Part1(string polymer)
{
	return ReactPolymer(polymer).size();
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

string Day05::ReactPolymer(string polymer)
{
	string result;
	list<char> polymerList;
	for (auto const& p : polymer)
	{
		polymerList.push_back(p);
	}

	char previousChar = *polymerList.begin();
	for (auto it = ++polymerList.begin(); it != polymerList.end(); it++)
	{
		// ASCII upper case + 32 is ASCII lower case
		if (previousChar + 32 == *it || previousChar - 32 == *it)
		{
			it = polymerList.erase(it);
			it--;
			it = polymerList.erase(it);
			if (it == polymerList.begin())
			{
				// do nothing
			}
			else
			{
				it--;
			}
		}

		previousChar = *it;
	}

	for (auto const& pl : polymerList)
	{
		result += pl;
	}

	return result;
}
