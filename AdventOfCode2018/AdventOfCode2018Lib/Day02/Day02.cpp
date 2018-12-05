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
	int countOfTwoCharaters = 0;
	int countOfThreeCharacters = 0;
	for (auto const& s : boxIds)
	{
		if (HasTwoRepeatedCharacters(s))
		{
			countOfTwoCharaters++;
		}

		if (HasThreeRepeatedCharacters(s))
		{
			countOfThreeCharacters++;
		}
	}

	return countOfTwoCharaters * countOfThreeCharacters;
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
	for (auto const& o : FindCharacterOccurrences(input))
	{
		if (o.second == 2)
		{
			return true;
		}
	}

	return false;
}

bool Day02::HasThreeRepeatedCharacters(string input)
{
	for (auto const& o : FindCharacterOccurrences(input))
	{
		if (o.second == 3)
		{
			return true;
		}
	}

	return false;
}

map<char, int> Day02::FindCharacterOccurrences(string input)
{
	string sortedInput = input;
	sort(sortedInput.begin(), sortedInput.end());
	char previousChar = sortedInput[0];
	int countOfCurrentChar = 1;
	map<char, int> occurences;
	occurences[previousChar] = 1;
	for (int i = 1; i < sortedInput.length(); i++)
	{
		char c = sortedInput[i];
		if (previousChar == c)
		{
			occurences[c]++;
		}
		else
		{
			previousChar = c;
			occurences[c] = 1;
		}
	}

	return occurences;
}
