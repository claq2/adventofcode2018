#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day13/Day13.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day13Tests)
	{
	public:
		vector<string> sample1
		{
//           0123456789012
		  R"(/->-\        )",
		  R"(|   |  /----\)",
		  R"(| /-+--+-\  |)",
		  R"(| | |  | v  |)",
		  R"(\-+-/  \-+--/)",
		  R"(  \------/   )",
		};
/*
 0123456789012
0/->-\        
1|   |  /----\
2| /-+--+-\  |
3| | |  | v  |
4\-+-/  \-+--/
5  \------/   
*/

		vector<string> sample2
		{
			R"(/>-<\  )",
			R"(|   |  )",
			R"(| /<+-\)",
			R"(| | | v)",
			R"(\>+</ |)",
			R"(  |   ^)",
			R"(  \<->/)",
		};
/*
/>-<\
|   |
| /<+-\
| | | v
\>+</ |
  |   ^
  \<->/
*/

		TEST_METHOD(ReadInput)
		{
			Day13 day13;
			auto value(day13.ReadInput());
			for (auto const & v : value)
			{
				// 150 wide
				Assert::AreEqual(size_t(150), v.size());
			}
			// 150 long
			Assert::AreEqual(size_t(150), value.size());
		}

		TEST_METHOD(Part1)
		{
			Day13 day13;
			auto value(day13.ReadTracks(sample1));
			auto actual(day13.Part1(value));
			Assert::AreEqual(string("7,3"), actual);
		}

		TEST_METHOD(Part2)
		{
			Day13 day13;
			auto value(day13.ReadTracks(sample2));
			auto actual(day13.Part2(value));
			Assert::AreEqual(string("6,4"), actual);
		}

		TEST_METHOD(ReadTracks)
		{
			Day13 day13;
			auto value(day13.ReadTracks(sample1));
			for (auto const & v : value)
			{
				// 13 wide
				Assert::AreEqual(size_t(13), v.size());
			}
			// 6 long
			Assert::AreEqual(size_t(6), value.size());
			Assert::AreEqual('/', value[0][0]);
			Assert::AreEqual(' ', value[0][12]);
			Assert::AreEqual(' ', value[5][0]);
			Assert::AreEqual(' ', value[5][12]);
		}
	};
}
