#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day03/Day03.h"
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day03Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day03 day3;
			vector<string> vals(day3.ReadInput());
			Assert::AreEqual(string("#1 @ 861,330: 20x10"), vals.front());
			Assert::AreEqual(string("#1317 @ 382,340: 28x29"), vals.back());
			Assert::AreEqual(size_t(1317), vals.size());
		}

		TEST_METHOD(Part1)
		{
			map<vector<string>, int> tests({
				{ { "abcdef", "bababc", "abbcde", "abcccd", "aabcdd", "abcdee", "ababab" }, 12 },
				});

			Day03 day3;
			int actual;
			for (auto const& m : tests)
			{
				actual = day3.Part1(m.first);
				Assert::AreEqual(m.second, actual);
			}
		}

		TEST_METHOD(Part2)
		{
			map<vector<string>, string> tests({
				{ {
						"abcde",
						"fghij",
						"klmno",
						"pqrst",
						"fguij",
						"axcye",
						"wvxyz"
					}, "fgij" },
				});

			Day03 day3;
			string actual;
			for (auto const& m : tests)
			{
				actual = day3.Part2(m.first);
				Assert::AreEqual(m.second, actual);
			}
		}
	};
}
