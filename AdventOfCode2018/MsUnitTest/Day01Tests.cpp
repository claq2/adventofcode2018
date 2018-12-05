#include "stdafx.h"
#include <map>
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day01/Day01.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day01Tests)
	{
	public:

		TEST_METHOD(Part1)
		{
			map<vector<int>, int> tests({
				{ { 0, 1 }, 1 },
				{ { 1, -2 }, -1 },
				{ { 1, 1, 1 }, 3 },
				{ { 1, 1, -2 }, 0 },
				{ { -1, -2, -3 }, -6 },
				});

			Day01 day1;
			int actual;
			for (auto const& m : tests)
			{
				actual = day1.Part1(m.first);
				Assert::AreEqual(m.second, actual);
			}
		}

		TEST_METHOD(Part2)
		{
			map<vector<int>, int> tests({
				{ { 1, -1 }, 0 },
				{ { +3, +3, +4, -2, -4 }, 10 },
				{ { -6, +3, +8, +5, -6 }, 5 },
				{ { +7, +7, -2, -7, -4 }, 14 },
				});
			Day01 day1;
			int actual;
			for (auto const& m : tests)
			{
				actual = day1.Part2(m.first);
				Assert::AreEqual(m.second, actual);
			}
		}

		TEST_METHOD(ReadInput)
		{
			Day01 day1;
			vector<int> vals(day1.ReadInput());
			Assert::AreEqual(-19, vals.front());
			Assert::AreEqual(-73375, vals.back());
			Assert::AreEqual(size_t(954), vals.size());
		}
	};
}
