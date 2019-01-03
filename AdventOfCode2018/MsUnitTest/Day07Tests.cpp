#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AdventOfCode2018Lib/Day07/Day07.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MsUnitTest
{
	TEST_CLASS(Day07Tests)
	{
	public:

		TEST_METHOD(ReadInput)
		{
			Day07 day7;

			vector<string> coords(day7.ReadInput());
			Assert::AreEqual(size_t(101), coords.size());
		}

		TEST_METHOD(Part1)
		{
			Day07 day7;
			string actual;
			vector<string> input({
				"Step C must be finished before step A can begin.",
				"Step C must be finished before step F can begin.",
				"Step A must be finished before step B can begin.",
				"Step A must be finished before step D can begin.",
				"Step B must be finished before step E can begin.",
				"Step D must be finished before step E can begin.",
				"Step F must be finished before step E can begin.",
				});
			string expected("CABDFE");
			actual = day7.Part1(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Part2)
		{
			Day07 day7;
			string actual;
			vector<string> input({
				"Step C must be finished before step A can begin.",
				"Step C must be finished before step F can begin.",
				"Step A must be finished before step B can begin.",
				"Step A must be finished before step D can begin.",
				"Step B must be finished before step E can begin.",
				"Step D must be finished before step E can begin.",
				"Step F must be finished before step E can begin.",
				});
			string expected("15");
			actual = day7.Part2(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
