#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class dayType> class Runner
{
public:
	void Run();
};

template <class dayType> void Runner<dayType>::Run()
{
	dayType day;
	string fullClassName(typeid(dayType).name());
	string className(fullClassName.substr(fullClassName.find(' ') + 1));
	auto input = day.ReadInput();
	cout << className << " part 1: " << day.Part1(input) << endl;
	cout << className << " part 2: " << day.Part2(input) << endl;
}
