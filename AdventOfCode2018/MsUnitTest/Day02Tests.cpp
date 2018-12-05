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
				wstring wide(m.first.begin(), m.first.end());
				Assert::AreEqual(m.second, actual, wide.c_str());
			}
		}

		TEST_METHOD(HasThreeRepeatedCharacters)
		{
			map<string, bool> tests{
				{ "abcdef", false },
				{ "bababc", true },
				{ "abbcde", false },
				{ "abcccd", true },
				{ "aabcdd", false },
				{ "abcdee", false },
				{ "ababab", true },
			};

			Day02 day2;
			bool actual;
			for (auto const& m : tests)
			{
				actual = day2.HasThreeRepeatedCharacters(m.first);
				wstring wide(m.first.begin(), m.first.end());
				Assert::AreEqual(m.second, actual, wide.c_str());
			}
		}

		TEST_METHOD(FindCharacterOccurrences)
		{
			map<string, map<char, int>> tests{
				{ "abcdef", {{'a', 1}, {'b', 1}, {'c', 1}, {'d', 1}, {'e', 1}, {'f', 1}} },
				{ "bababc", {{'a', 2}, {'b', 3}, {'c', 1}} },
				{ "abbcde", {{'a', 1}, {'b', 2}, {'c', 1}, {'d', 1}, {'e', 1}} },
				//{ "abcccd", false },
				{ "abcccd", {{'a', 1}, {'b', 1}, {'c', 3}, {'d', 1}} },
				//{ "aabcdd", true },
				{ "aabcdd", {{'a', 2}, {'b', 1}, {'c', 1}, {'d', 2}} },
				//{ "abcdee", true },
				{ "abcdee", {{'a', 1}, {'b', 1}, {'c', 1}, {'d', 1}, {'e', 2}} },
				//{ "ababab", false },
				{ "ababab", {{'a', 3}, {'b', 3}} },
			};

			Day02 day2;
			map<char, int> actual;
			for (auto const& m : tests)
			{
				actual = day2.FindCharacterOccurrences(m.first);
				wstring wide(m.first.begin(), m.first.end());
				Assert::AreEqual(m.second.size(), actual.size());
				for (auto const& o : m.second)
				{
					Assert::AreEqual(o.second, actual[o.first]);
				}
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
