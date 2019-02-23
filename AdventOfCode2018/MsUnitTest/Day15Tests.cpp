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
			auto value{ day15.ReadInput() };

			for (auto const & v : value)
			{
				// 32 wide
				Assert::AreEqual(size_t{ 32 }, v.size());
			}

			// 32 long
			Assert::AreEqual(size_t{ 32 }, value.size());
		}

		TEST_METHOD(ExtractCreatures)
		{
			Day15 day15;
			auto value{ day15.ReadInput() };
			auto creatures{ day15.ExtractCreatures(value) };
			Assert::AreEqual(size_t{ 30 }, creatures.size());
			Assert::AreEqual(200, get<3>(creatures[0])); // 200 hit points to start
			int goblinCount = count_if(creatures.begin(), creatures.end(), [](const pair<int, tuple<int, int, Day15::Creature, int>> & c) {
				return get<2>(c.second) == Day15::Creature::Goblin;
			});
			int elfCount = count_if(creatures.begin(), creatures.end(), [](const pair<int, tuple<int, int, Day15::Creature, int>> & c) {
				return get<2>(c.second) == Day15::Creature::Elf;
			});
			Assert::AreEqual(10, elfCount);
			Assert::AreEqual(20, goblinCount);
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
