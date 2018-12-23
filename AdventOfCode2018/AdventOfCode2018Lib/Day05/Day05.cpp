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

size_t Day05::Part2(string polymer)
{
	size_t minSize(polymer.size());
	string allLetters("abcdefghijklmnopqrstuvwxyz");
	for (auto const& l : allLetters)
	{
		string copyOfPolymer(polymer);
		for (auto pi = copyOfPolymer.begin(); pi != copyOfPolymer.end(); pi++)
		{
			if (*pi == l || *pi == l - 32)
			{
				copyOfPolymer.erase(pi);
				if (pi != copyOfPolymer.begin())
				{
					pi--;
				}
			}
		}

		size_t sizeAfterReacting(ReactPolymer(copyOfPolymer).size());
		if (sizeAfterReacting < minSize)
		{
			minSize = sizeAfterReacting;
		}
	}

	return minSize;
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
