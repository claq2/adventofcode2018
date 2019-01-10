#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day09/Day09.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day09Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day09 day9;

			string values(day9.ReadInput());
			Assert::AreEqual(size_t(46), values.size());
		}

		TEST_METHOD(Part1)
		{
			Day09 day9;
			string actual;
			string input("9 players; last marble is worth 25 points");
			string expected("32");
			actual = day9.Part1(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day09 day9;
			string actual;
			string input("9 players; last marble is worth 25 points");
			string expected("32");
			actual = day9.Part2(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
