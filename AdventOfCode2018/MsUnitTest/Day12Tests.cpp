#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day12/Day12.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day12Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day12 day12;

			auto value(day12.ReadInput());
			//Assert::AreEqual(5535, value);
		}

		TEST_METHOD(Part1)
		{
			Day12 day12;
			//string expected("33,45");
			//auto actual(day12.Part1(18));
			//Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day12 day12;
			//string expected("90,269,16");
			//auto actual(day12.Part2(18));
			//Assert::AreEqual(expected, actual);
		}
	};
}
