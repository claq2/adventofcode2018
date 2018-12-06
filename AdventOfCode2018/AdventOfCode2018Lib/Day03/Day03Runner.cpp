#include "stdafx.h"
#include <iostream>
#include "Day03Runner.h"
#include "Day03.h"

using namespace std;

Day03Runner::Day03Runner()
{
}


Day03Runner::~Day03Runner()
{
}

void Day03Runner::Run()
{
	Day03 day03;
	auto input = day03.ReadInput();
	cout << "Day 03 part 1: " << day03.Part1(input) << endl;
	cout << "Day 03 part 2: " << day03.Part2(input) << endl;
}
