#include "stdafx.h"
#include "Day14.h"

using namespace std;

Day14::Day14() {}
Day14::~Day14() {}

int Day14::ReadInput()
{
	return 513401;
}

std::string Day14::Part1(int input)
{
	auto scores = vector<int>{ 3,7 };
	auto elf1 = scores.begin();
	auto elf2 = scores.begin() + 1;
	int elf1Index = 0;
	int elf2Index = 1;
	string steps{ "" };
	for (size_t i = 1; scores.size() < input + 10; i++)
	{
		int newScore = *elf1 + *elf2;
		// get digits of new score
		int onesDigit = newScore % 10;
		int tensDigit(0);
		if (newScore >= 10)
		{
			tensDigit = (newScore - onesDigit) / 10;
		}

		// append digits to scores
		if (tensDigit != 0)
		{
			scores.push_back(tensDigit);
		}

		scores.push_back(onesDigit);

		elf1 = scores.begin() + elf1Index;
		// move iterators
		int elf1CurrentValue = *elf1;
		for (int i = 0; i < elf1CurrentValue + 1; i++)
		{
			if (elf1 == scores.end() - 1)
			{
				elf1 = scores.begin();
				elf1Index = 0;
			}
			else
			{
				elf1++;
				elf1Index++;
			}
		}

		elf2 = scores.begin() + elf2Index;
		int elf2CurrentValue = *elf2;
		for (int i = 0; i < elf2CurrentValue + 1; i++)
		{
			if (elf2 == scores.end() - 1)
			{
				elf2 = scores.begin();
				elf2Index = 0;
			}
			else
			{
				elf2++;
				elf2Index++;
			}
		}

		for (auto si = scores.begin(); si != scores.end(); si++)
		{
			if (elf1 == si)
			{
				steps += "(" + to_string(*elf1) + ")";
			}
			else if (elf2 == si)
			{
				steps += "[" + to_string(*elf2) + "]";
			}
			else
			{
				steps += " " + to_string(*si) + " ";
			}
		}

		steps += "\r\n";
	}

	string nextTenScoresAfterInput("");
	for (size_t i = input; i < 10 + input; i++)
	{
		nextTenScoresAfterInput += to_string(scores[i]);
	}

	return nextTenScoresAfterInput;
}

std::string Day14::Part2(int input)
{
	return "";
}
