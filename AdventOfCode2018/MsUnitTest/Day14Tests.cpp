﻿#include "stdafx.h"
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
			
			Assert::AreEqual(string{ "513401" }, value);
		}

		TEST_METHOD(Part1)
		{
			Day14 day14;
			map<string, string> tests{ {"9", "5158916779"}, {"5", "0124515891"} };
			for (auto const & test : tests)
			{
				string actual = day14.Part1(test.first);
				Assert::AreEqual(test.second, actual);
			}
			
		}

		TEST_METHOD(Part2)
		{
			Day14 day14;
			map<string, string> tests{ {"51589", "9"}, {"01245", "5"}, {"92510", "18"}, {"59414", "2018"} };
			for (auto const & test : tests)
			{
				string actual = day14.Part2(test.first);
				Assert::AreEqual(test.second, actual);
			}
		}
	};
}
