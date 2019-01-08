#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day08/Day08.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day08Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day08 day8;

			vector<int> values(day8.ReadInput());
			Assert::AreEqual(size_t(17359), values.size());
		}

		TEST_METHOD(Part1)
		{
			Day08 day8;
			string actual;
			vector<int> input({ 2, 3, 0, 3, 10, 11, 12, 1, 1, 0, 1, 99, 2, 1, 1, 2 });
			string expected("138");
			actual = day8.Part1(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day08 day8;
			string actual;
			vector<int> input({ 2, 3, 0, 3, 10, 11, 12, 1, 1, 0, 1, 99, 2, 1, 1, 2 });
			string expected("15");
			actual = day8.Part2(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
