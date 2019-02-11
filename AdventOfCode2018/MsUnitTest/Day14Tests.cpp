#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day14/Day14.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day14Tests)
	{
	public:
		

		TEST_METHOD(ReadInput)
		{
			Day14 day14;
			auto value(day14.ReadInput());
			
			Assert::AreEqual(513401, value);
		}

		TEST_METHOD(Part1)
		{
			Day14 day14;
			
		}

		TEST_METHOD(Part2)
		{
			Day14 day14;
			
		}

	};
}
