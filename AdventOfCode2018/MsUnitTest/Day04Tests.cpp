#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day04/Day04.h"
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day04Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day04 day4;
			vector<string> vals(day4.ReadInput());
		}

		TEST_METHOD(Part1)
		{
			Day04 day4;
			int actual;

			actual = day4.Part1({});
		}

		TEST_METHOD(Part2)
		{
			Day04 day4;
			int actual;

			actual = day4.Part2({});
		}
	};
}
