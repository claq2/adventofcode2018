#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day05/Day05.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day05Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day05 day5;

			string polymer(day5.ReadInput());
			Assert::AreEqual(size_t(50000), polymer.size());
		}

		TEST_METHOD(Part1)
		{
			Day05 day5;
			int actual;

			string polymer(day5.ReadInput());
			actual = day5.Part1(polymer);
		}

		TEST_METHOD(Part2)
		{
			Day05 day5;
			int actual;

			string polymer(day5.ReadInput());
			actual = day5.Part2(polymer);
		}
	};
}
