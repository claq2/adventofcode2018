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

			string value(day11.ReadInput());
			Assert::AreEqual(string("5535"), value);
		}

		TEST_METHOD(Part1)
		{
			Day11 day11;
			string actual;
			
		}

		TEST_METHOD(Part2)
		{
			Day11 day11;
			string actual;
			
		}
	};
}
