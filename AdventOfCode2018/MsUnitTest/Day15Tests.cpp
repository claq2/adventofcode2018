#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day15/Day15.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day15Tests)
	{
	public:
		TEST_METHOD(ReadInput)
		{
			Day15 day15;
			auto value(day15.ReadInput());

			for (auto const & v : value)
			{
				// 150 wide
				Assert::AreEqual(size_t(32), v.size());
			}
			// 150 long
			Assert::AreEqual(size_t(32), value.size());
		}

		TEST_METHOD(Part1)
		{
			Day15 day15;
			auto value(day15.ReadInput());
			auto actual(day15.Part1(value));

		}

		TEST_METHOD(Part2)
		{
			Day15 day15;
			
		}
	};
}
