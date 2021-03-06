﻿#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day03/Day03.h"
#include <map>
#include "../AdventOfCode2018Lib/Day03/FabricClaim.h"

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
			vector<FabricClaim> vals(day3.ReadInput());

			Assert::AreEqual(size_t(1317), vals.size());

			//#1 @ 861,330: 20x10
			auto firstVal = vals.front();
			Assert::AreEqual(1, firstVal.Id);
			Assert::AreEqual(861, firstVal.StartX);
			Assert::AreEqual(330, firstVal.StartY);
			Assert::AreEqual(20, firstVal.Width);
			Assert::AreEqual(10, firstVal.Height);

			// #1317 @ 382,340: 28x29
			auto lastVal = vals.back();
			Assert::AreEqual(1317, lastVal.Id);
			Assert::AreEqual(382, lastVal.StartX);
			Assert::AreEqual(340, lastVal.StartY);
			Assert::AreEqual(28, lastVal.Width);
			Assert::AreEqual(29, lastVal.Height);
		}

		TEST_METHOD(Part1)
		{
			pair<vector<FabricClaim>, int> tests
			{
				{
					FabricClaim("#1 @ 1,3: 4x4"),
					FabricClaim("#2 @ 3,1: 4x4"),
					FabricClaim("#3 @ 5,5: 2x2"),
				}, 4
			};

			Day03 day3;
			int actual;

			actual = day3.Part1(tests.first);
			Assert::AreEqual(tests.second, actual);
		}

		TEST_METHOD(Part2)
		{
			pair<vector<FabricClaim>, int> tests
			{
				{
					FabricClaim("#1 @ 1,3: 4x4"),
					FabricClaim("#2 @ 3,1: 4x4"),
					FabricClaim("#3 @ 5,5: 2x2"),
				}, 3
			};

			Day03 day3;
			int actual;

			actual = day3.Part2(tests.first);
			Assert::AreEqual(tests.second, actual);
		}
	};
}
