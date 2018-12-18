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
			size_t actual;
			string input("dabAcCaCBAcCcaDA");
			size_t expected(10);
			actual = day5.Part1(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day05 day5;
			size_t actual;
			string input("dabAcCaCBAcCcaDA");
			size_t expected(4);
			actual = day5.Part2(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
