#include "stdafx.h"
#include <iostream>
#include "Day01Runner.h"
#include "Day01.h"

using namespace std;

void Day01Runner::Run()
{
	Day01 day01;
	auto day01input = day01.ReadInput();
	cout << "Day 01 part 1: " << day01.Part1(day01input) << endl;
	cout << "Day 01 part 2: " << day01.Part2(day01input) << endl;
}
