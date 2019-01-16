#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day11/Day11.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day11Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day11 day11;

			int value(day11.ReadInput());
			Assert::AreEqual(5535, value);
		}

		TEST_METHOD(Part1)
		{
			Day11 day11;
			string expected("33,45");
			string actual(day11.Part1(18));
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day11 day11;
			string expected("90,269,16");
			string actual(day11.Part2(18));
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CalculatePower)
		{
			Day11 day11;
			vector<tuple<int, int, int, int>> inputs
			{
				{ 8, 3, 5, 4 },
				{ 57, 122, 79, -5 },
				{ 39, 217, 196, 0 },
				{ 71, 101, 153, 4 },
				{ 18, 32, 44, -2 },
			};

			for (auto  i : inputs)
			{
				int expected(get<3>(i));
				int serial(get<0>(i));
				int x(get<1>(i));
				int y(get<2>(i));
				int actual(day11.CalculatePower(serial, x, y));
				Assert::AreEqual(expected, actual);
			}
		}

		TEST_METHOD(BuildGrid)
		{
			Day11 day11;
			auto grid = day11.BuildGrid(18);
			Assert::AreEqual(-2, grid[43][31]);
			Assert::AreEqual(-4, grid[43][32]);
			Assert::AreEqual(4, grid[43][33]);
			Assert::AreEqual(4, grid[43][34]);
			Assert::AreEqual(4, grid[43][35]);
		}
	};
}
