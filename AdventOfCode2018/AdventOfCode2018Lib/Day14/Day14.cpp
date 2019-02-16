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
	auto elf2 = elf1++;
	for (size_t i = 1; i <= input; i++)
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

		// TODO repoint iterators after changing vector

		// move iterators
		int elf1CurrentValue = *elf1 + 0;
		for (int i = 0; i < elf1CurrentValue; i++)
		{
			if (elf1 == scores.end())
			{
				elf1 = scores.begin();
			}
			else
			{
				elf1++;
			}
		}

		int elf2CurrentValue = (*elf2);
		for (int i = 0; i < elf2CurrentValue; i++)
		{
			if (elf2 == scores.end())
			{
				elf2 = scores.begin();
			}
			else
			{
				elf2++;
			}
		}
	}

	string nextTenScoresAfterInput("");
	for (size_t i = input; i < 10 + input; i++)
	{
		nextTenScoresAfterInput += scores[i];
	}

	return nextTenScoresAfterInput;
}

std::string Day14::Part2(int input)
{
	return "";
}
