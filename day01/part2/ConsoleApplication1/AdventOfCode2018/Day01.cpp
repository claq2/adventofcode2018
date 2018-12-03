#include "stdafx.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include <sstream> 
#include <filesystem>
#include "Day01.h"
namespace fs = std::filesystem;

using namespace std;

Day01::Day01()
{
}


Day01::~Day01()
{
}

int Day01::Part1()
{
	return 5;
}

int Day01::Part2()
{
	// read input into vector
	ifstream file;
	string currentNumberStringWithSign;
	vector<int> numbers;
	vector<fs::directory_entry> des;

	for (auto & p : fs::directory_iterator(""))
		des.push_back(p);

	file.open("Day01.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	while (getline(file, currentNumberStringWithSign))
	{
		//cout << currentNumberStringWithSign << endl;
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

	int sum = 0;
	map<int, int> seenValues;
	seenValues[sum] = sum;
	bool foundDuplicate = false;
	do
	{
		for (auto const& value : numbers) {
			sum += value;
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
