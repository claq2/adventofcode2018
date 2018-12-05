#include "stdafx.h"
#include <fstream>
#include "Day02.h"
#include <algorithm>


Day02::Day02()
{
}


Day02::~Day02()
{
}

int Day02::Part1(vector<string> boxIds)
{
	return 42;
}

int Day02::Part2(vector<string> boxIds)
{
	return 43;
}

vector<string> Day02::ReadInput()
{
	ifstream file;
	string currentBoxId;
	vector<string> boxIds;

	file.open("Day02.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	while (file >> currentBoxId)
	{
		boxIds.push_back(currentBoxId);
	}

	file.close();

	return boxIds;
}

bool Day02::HasTwoRepeatedCharacters(string input)
{
	sort(input.begin(), input.end());
	char previousChar = input[0];
	int countOfCurrentChar = 1;
	for (auto const& c : input)
	{
		if (previousChar == c)
		{
			countOfCurrentChar++;
		}
		else
		{
			if (countOfCurrentChar == 2)
			{
				return true;
			}
			else
			{
				previousChar = c;
				countOfCurrentChar = 1;
			}
		}
	}

	return false;
}

bool Day02::HasThreeRepeatedCharacters(string input)
{
	return false;
}
