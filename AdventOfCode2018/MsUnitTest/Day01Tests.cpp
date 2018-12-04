#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day01.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MsUnitTest
{
	TEST_CLASS(Day01Tests)
	{
	public:

		TEST_METHOD(Part1)
		{
			Day01 day1;
			int val(day1.Part1({ 1, 2, 3 }));
			Assert::AreEqual(42, val);
		}

		TEST_METHOD(Part2)
		{
			Day01 day1;
			int val(day1.Part2({ 1, 2, 3 }));
			Assert::AreEqual(43, val);
		}

		TEST_METHOD(ReadInput)
		{
			Day01 day1;
			vector<int> vals(day1.ReadInput());
			vector<int> expected({ 4, 5, 6 });
			Assert::IsTrue(vals == expected, L"input doesn't match");
		}
	};
}