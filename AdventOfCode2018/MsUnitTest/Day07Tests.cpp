#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day07/Day07.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day07Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day07 day7;

			vector<string> coords(day7.ReadInput());
			Assert::AreEqual(size_t(60000), coords.size());
		}

		TEST_METHOD(Part1)
		{
			Day07 day7;
			string actual;
			vector<string> input({
				"1, 1",
				"1, 6",
				"8, 3",
				"3, 4",
				"5, 5",
				"8, 9"
				});
			string expected("17");
			actual = day7.Part1(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day07 day7;
			string actual;
			vector<string> input({
				"1, 1",
				"1, 6",
				"8, 3",
				"3, 4",
				"5, 5",
				"8, 9"
				});
			string expected("16");
			actual = day7.Part2(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
