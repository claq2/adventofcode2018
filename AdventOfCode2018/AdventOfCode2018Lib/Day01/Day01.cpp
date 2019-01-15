#include <stdafx.h>
#include "Day01.h"

Day01::Day01()
{
}

Day01::~Day01()
{
}

int Day01::Part1(vector<int> frequencies)
{
	int sum = 0;
	for (auto const& f : frequencies)
	{
		sum += f;
	}

	return sum;
}

int Day01::Part2(vector<int> frequencies)
{
	int sum = 0;
	map<int, int> seenValues;
	seenValues[sum] = sum;
	bool foundDuplicate = false;
	do
	{
		for (auto const& f : frequencies) {
			sum += f;
			if (seenValues.count(sum) == 1) {
				foundDuplicate = true;
				break;
			}
			else {
				seenValues[sum] = sum;
			}
		}
	} while (!foundDuplicate);

	return sum;
}

vector<int> Day01::ReadInput()
{
	ifstream file;
	string currentNumberStringWithSign;
	vector<int> numbers;

	file.open("Day01.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	while (getline(file, currentNumberStringWithSign))
	{
		string currentNumberString = currentNumberStringWithSign.substr(1, currentNumberStringWithSign.length() - 1);
		stringstream numberStream(currentNumberString);
		int currentNumber = 0;
		numberStream >> currentNumber;
		if (currentNumberStringWithSign[0] == '-')
		{
			currentNumber *= -1;
		}

		numbers.push_back(currentNumber);
	}

	file.close();

	if (numbers.empty())
	{
		exception e("didn't read any numbers");
		throw e;
	}

	return numbers;
}
