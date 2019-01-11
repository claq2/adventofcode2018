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

			pair<int, int> values(day9.ReadInput());
			Assert::AreEqual(446, values.first);
			Assert::AreEqual(71522, values.second);
		}

		TEST_METHOD(Part1)
		{
			Day09 day9;
			string actual;
			vector<pair<int, int>> inputs
			{
				{ 9, 25 },
				{ 10, 1618 },
				{ 13, 7999 },
				{ 17, 1104 },
				{ 21, 6111 },
				{ 30, 5807 },
			};
			vector<string> expecteds{ "32", "8317", "146373", "2764", "54718", "37305" };

			for (size_t i = 0; i < inputs.size(); i++)
			{
				actual = day9.Part1(inputs[i]);
				Assert::AreEqual(expecteds[i], actual);
			}


			/*pair<int, int> input({ 9, 25 });
			string expected("32");
			actual = day9.Part1(input);
			Assert::AreEqual(expected, actual);*/
		}

		TEST_METHOD(Part2)
		{
			Day09 day9;
			string actual;
			pair<int, int> input({ 9, 25 });
			string expected("32");
			actual = day9.Part2(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
