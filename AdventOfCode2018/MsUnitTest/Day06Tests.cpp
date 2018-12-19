#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day06/Day06.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day06Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day06 day6;

			vector<string> coords(day6.ReadInput());
			Assert::AreEqual(size_t(60000), coords.size());
		}

		TEST_METHOD(Part1)
		{
			Day06 day6;
			size_t actual;
			vector<string> input({
				"1, 1",
				"1, 6",
				"8, 3",
				"3, 4",
				"5, 5",
				"8, 9"
				});
			size_t expected(10);
			actual = day6.Part1(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day06 day6;
			size_t actual;
			vector<string> input({
				"1, 1",
				"1, 6",
				"8, 3",
				"3, 4",
				"5, 5",
				"8, 9"
				});
			size_t expected(4);
			actual = day6.Part2(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
