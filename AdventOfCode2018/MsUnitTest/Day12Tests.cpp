#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day12/Day12.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day12Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day12 day12;
			// ###..###....####.###...#..#...##...#..#....#.##.##.#..#.#..##.#####..######....#....##..#...#...#.#
			auto value(day12.ReadInput());
			Assert::IsTrue(get<0>(value)[0]);
			Assert::IsTrue(get<0>(value)[1]);
			Assert::IsTrue(get<0>(value)[2]);
			Assert::IsFalse(get<0>(value)[3]);
			Assert::IsFalse(get<0>(value)[4]);
			Assert::IsTrue(get<0>(value)[5]);
		}

		TEST_METHOD(Part1)
		{
			Day12 day12;
			//string expected("33,45");
			auto value(day12.ReadInput());
			auto actual(day12.Part1(value));
			//Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day12 day12;
			//string expected("90,269,16");
			//auto actual(day12.Part2(18));
			//Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ParseInput)
		{
			Day12 day12;
			vector<string> input{
				//0123456789012345678901234
				{"initial state: #..#.#..##......###...###"},
				{""},
				//124816
				{"...## => #"}, //24
				{"..#.. => #"}, //4
				{".#... => #"}, //2
				{".#.#. => #"}, //10
				{".#.## => #"}, //26
				{".##.. => #"}, //6
				{".#### => #"}, //30
				{"#.#.# => #"}, //21
				{"#.### => #"}, //29
				{"##.#. => #"}, //11
				{"##.## => #"}, //27
				{"###.. => #"}, //7
				{"###.# => #"}, //23
				{"####. => #"}, //15
			};
			auto stateAndRules = day12.ParseInput(input);
			auto state(get<0>(stateAndRules));
			auto rules(get<1>(stateAndRules));
			vector<bool> expectedState{
				true, //0
				false,//1
				false,//2
				true, //3
				false,//4
				true, //5
				false,//6
				false,//7
				true, //8
				true, //9
				false,//0
				false,//1
				false,//2
				false,//3
				false,//4
				false,//5
				true, //6
				true, //7
				true, //8
				false,//9
				false,//0
				false,//1
				true, //2
				true, //3
				true  //4
			};
			Assert::IsTrue(equal(expectedState.begin(), expectedState.end(), state.begin()));
			Assert::AreEqual(size_t(14), rules.size());
			Assert::IsTrue(rules[24]);
			Assert::IsTrue(rules[4]);
			Assert::IsTrue(rules[2]);
			Assert::IsTrue(rules[10]);
			Assert::IsTrue(rules[26]);
			Assert::IsTrue(rules[6]);
			Assert::IsTrue(rules[30]);
			Assert::IsTrue(rules[21]);
			Assert::IsTrue(rules[29]);
			Assert::IsTrue(rules[11]);
			Assert::IsTrue(rules[27]);
			Assert::IsTrue(rules[7]);
			Assert::IsTrue(rules[23]);
			Assert::IsTrue(rules[15]);
		}
	};
}
