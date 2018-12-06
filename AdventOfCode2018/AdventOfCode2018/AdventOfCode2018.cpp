// AdventOfCode2018.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "../AdventOfCode2018Lib/DayRunner.h"
#include "../AdventOfCode2018Lib/Day01/Day01Runner.h"
#include "../AdventOfCode2018Lib/Day02/Day02Runner.h"
#include "../AdventOfCode2018Lib/Day03/Day03Runner.h"

using namespace std;

int main()
{
	Day01Runner day01Runner;
	vector<shared_ptr<DayRunner>> runners{ 
		make_shared<Day01Runner>(),
		make_shared<Day02Runner>(),
		make_shared<Day03Runner>(),
	};

	for (auto r : runners)
	{
		r->Run();
	}
}
	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file