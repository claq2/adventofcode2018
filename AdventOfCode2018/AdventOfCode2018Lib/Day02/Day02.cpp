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
	string sortedInput = input;
	sort(sortedInput.begin(), sortedInput.end());
	char previousChar = sortedInput[0];
	int countOfCurrentChar = 1;
	for (int i = 1; i < sortedInput.length(); i++)
	{
		char c = sortedInput[i];
		if (previousChar == c)
		{
			countOfCurrentChar++;
		}

		else
		{
				previousChar = c;
				countOfCurrentChar = 1;
			
		}

		if (countOfCurrentChar == 2)
		{
			// TODO: keep going until end of string to see if there was exactly 2 of something
			return true;
		}

	}

	return false;
}

bool Day02::HasThreeRepeatedCharacters(string input)
{
	return false;
}
