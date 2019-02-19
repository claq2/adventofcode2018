#include "stdafx.h"
#include "Day14.h"

using namespace std;

Day14::Day14() {}
Day14::~Day14() {}

string Day14::ReadInput()
{
	return "513401";
}

std::string Day14::Part1(string input)
{
	auto scores = vector<int>{ 3,7 };
	auto elf1{ scores.begin() };
	auto elf2{ scores.begin() + 1 };
	int elf1Index{ 0 };
	int elf2Index{ 1 };
	string steps{ "" };
	int inputInt{ stoi(input) };
	for (size_t i = 1; scores.size() < inputInt + 10; i++)
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
		int elf1CurrentValue{ *elf1 };
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
		int elf2CurrentValue{ *elf2 };
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

		/*for (auto si = scores.begin(); si != scores.end(); si++)
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

		steps += "\r\n";*/
	}

	string nextTenScoresAfterInput{ "" };
	for (size_t i = inputInt; i < 10 + inputInt; i++)
	{
		nextTenScoresAfterInput += to_string(scores[i]);
	}

	return nextTenScoresAfterInput;
}

std::string Day14::Part2(string input)
{
	auto scores = vector<char>{ 3,7 };
	auto elf1{ scores.begin() };
	auto elf2{ scores.begin() + 1 };
	size_t elf1Index{ 0 };
	size_t elf2Index{ 1 };
	string steps{ "" };
	//string inputString = to_string(input);

	int iterationCount{ 0 };
	// need scores to be at least inputString + 1 long before testing
	while (true)
	{
		char newScore = *elf1 + *elf2;
		// get digits of new score
		char onesDigit = newScore % 10;
		char tensDigit(0);
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
		char elf1CurrentValue{ *elf1 };
		for (int j = 0; j < elf1CurrentValue + 1; j++)
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
		char elf2CurrentValue{ *elf2 };
		for (char j = 0; j < elf2CurrentValue + 1; j++)
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

		//iterationCount++;
		//if (iterationCount == 5000000)
		//{
		//	// Failsafe in case of bugs
		//	return "failsafe";
		//}

		if (scores.size() >= input.size() + 1)
		{
			auto first = scores.end() - input.size();
			auto last = scores.end();
			vector<char> lastScores(first, last);
			string lastScoresString{ "" };
			for (auto const & ls : lastScores) lastScoresString += to_string(ls);
			if (lastScoresString == input)
			{
				return to_string(scores.size() - input.size());
			}
			//		check end of vector for the input value
			//		if found return vector location before value + 1
		}

		/*for (auto si = scores.begin(); si != scores.end(); si++)
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

		steps += "\r\n";*/
	}

	return "";
}
