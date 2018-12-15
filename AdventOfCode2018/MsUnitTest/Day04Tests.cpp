#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day04/Day04.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day04Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day04 day4;
			
			vector<string> valsStrings(day4.ReadInput());
			Assert::AreEqual(size_t(1040), valsStrings.size());
			Assert::AreEqual(string("[1518-02-24 23:58] Guard #853 begins shift"), valsStrings.front());
			Assert::AreEqual(string("[1518-11-23 00:48] wakes up"), valsStrings.back());
		}

		TEST_METHOD(Part1)
		{
			Day04 day4;
			int actual;

			vector<string> valsStrings(day4.ReadInput());
			actual = day4.Part1(valsStrings);
		}

		TEST_METHOD(Part2)
		{
			Day04 day4;
			int actual;

			vector<string> valsStrings(day4.ReadInput());
			actual = day4.Part2(valsStrings);
		}
	};
}
