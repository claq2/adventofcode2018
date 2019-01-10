#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>

class ADVENTOFCODE2018LIB_API Day08
{
public:
	class ADVENTOFCODE2018LIB_API Leaf
	{
	public:
		Leaf();
		//Leaf(std::vector<int> values);
		std::vector<int> Metadata;
		int ExpectedChildren;
		int ExpectedMetadata;
		std::vector<std::shared_ptr<Leaf>> Children;
		//void BuildChildren(std::vector<int> values);
		std::shared_ptr<Leaf> Parent;
	};
public:
	Day08();
	~Day08();
	std::vector<int> ReadInput();
	std::string Part1(std::vector<int> values);
	//std::vector<std::shared_ptr<Leaf>> ExtractChildren(int count, std::vector<int>::iterator it, std::vector<int> &values, Leaf &parent);
	std::shared_ptr<Leaf> ExtractChild(std::vector<int> &values, std::shared_ptr<Leaf> parent);
	int SumMetadata(std::shared_ptr<Leaf> leaf);
	std::string Part2(std::vector<int> values);
};

