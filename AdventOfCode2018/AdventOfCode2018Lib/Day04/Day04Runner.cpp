#include "stdafx.h"
#include <iostream>
#include "Day04Runner.h"
#include "Day04.h"

using namespace std;

void Day04Runner::Run()
{
	Day04 day04;
	auto input = day04.ReadInput();
	cout << "Day 04 part 1: " << day04.Part1(input) << endl;
	cout << "Day 04 part 2: " << day04.Part2(input) << endl;
}
