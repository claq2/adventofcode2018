#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day13/Day13.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
//using namespace std::string_literals;

namespace MsUnitTest
{
	TEST_CLASS(Day13Tests)
	{
	public:
		string sample = R"("
/->-\        
|   |  /----\
| /-+--+-\  |
| | |  | v  |
\-+-/  \-+--/
  \------/")";

		TEST_METHOD(ReadInput)
		{
			Day13 day13;
			auto value(day13.ReadInput());
		}

		TEST_METHOD(Part1)
		{
			Day13 day13;
			auto value(day13.ParseInput(sample));
			auto actual(day13.Part1(value));
			Assert::AreEqual(string("7,3"), actual);
		}

		TEST_METHOD(Part2)
		{
			Day13 day13;
			auto value(day13.ParseInput(sample));
			auto actual(day13.Part2(value));
			Assert::AreEqual(string("7,3"), actual);
		}
	};
}
