#include "stdafx.h"
#include <iostream>
#include "Day02Runner.h"
#include "Day02.h"

Day02Runner::Day02Runner()
{
}


Day02Runner::~Day02Runner()
{
}

void Day02Runner::Run()
{
	Day02 day02;
	auto input = day02.ReadInput();
	cout << "Day 02 part 1: " << day02.Part1(input) << endl;
	cout << "Day 02 part 2: " << day02.Part2(input) << endl;
}
