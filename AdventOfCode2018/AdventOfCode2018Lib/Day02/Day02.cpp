#include "stdafx.h"
#include <fstream>
#include "Day02.h"
#include <algorithm>
#include <iostream>

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

string Day02::Part2(vector<string> boxIds)
{
	for (auto const& curr : boxIds)
	{
		for (auto const& other : boxIds)
		{
			int totalDiffs = 0;
			int lastDiffPosition = 0;
			if (curr != other)
			{
				for (int i = 0; i < curr.length(); i++)
				{
					if (curr[i] != other[i])
					{
						totalDiffs++;
						lastDiffPosition = i;
					}
				}

				if (totalDiffs == 1)
				{
					string commonLetters;
					commonLetters.append(curr.substr(0, lastDiffPosition));
					commonLetters.append(curr.substr(lastDiffPosition + 1));
					return commonLetters;
				}
			}
		}
	}

	return "";
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
