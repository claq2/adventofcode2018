#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day02/Day02.h"
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day02Tests)
	{
	public:

		TEST_METHOD(HasTwoRepeatedCharacters)
		{
			map<string, bool> tests{
				{ "abcdef", false },
				{ "bababc", true },
				{ "abbcde", true },
				{ "abcccd", false },
				{ "aabcdd", true },
				{ "abcdee", true },
				{ "ababab", false },
			};

			Day02 day2;
			bool actual;
			for (auto const& m : tests)
			{
				actual = day2.HasTwoRepeatedCharacters(m.first);
				Assert::AreEqual(m.second, actual);
			}
		}

		TEST_METHOD(Part1)
		{
			map<vector<string>, int> tests({
				{ { "abcdef", "bababc", "abbcde", "abcccd", "aabcdd", "abcdee", "ababab" }, 12 },
				});

			Day02 day2;
			int actual;
			for (auto const& m : tests)
			{
				actual = day2.Part1(m.first);
				Assert::AreEqual(m.second, actual);
			}
		}

		TEST_METHOD(ReadInput)
		{
			Day02 day2;
			vector<string> vals(day2.ReadInput());
			Assert::AreEqual(string("wxlnjevbfozadyiqpuzkrhstkg"), vals.front());
			Assert::AreEqual(string("wxxnjevufodamyiqruzcrhstkg"), vals.back());
			Assert::AreEqual(size_t(250), vals.size());
		}
	};
}
