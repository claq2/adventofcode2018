#pragma once
#include "../AdventOfCode2018Lib.h"
#include <vector>
#include <string>

class ADVENTOFCODE2018LIB_API Day08
{
public:
	Day08();
	~Day08();
	std::vector<int> ReadInput();
	std::string Part1(std::vector<int> value);
	std::string Part2(std::vector<int> value);
private:
	class Leaf
	{
		public:
			std::vector<int> Metadata;
			std::vector<std::unique_ptr<Leaf>> Children;
			void BuildChildren(std::vector<int> values)
			{
				int numberOfChildren = values[0];

				// Extract metadata
				for (int i = 0; i < values[1]; i++)
				{
					Metadata.push_back(values[values.size() - 1]);
					values.erase(values.end() - 1);
				}

				
				// Erase number of children
				values.erase(values.begin());
				// Erase number of metadata
				values.erase(values.begin());

				for (int i = 0; i < numberOfChildren; i++)
				{
					Children.push_back(std::make_unique<Leaf>());
					Children.back()->BuildChildren(values);
				}
			}
	};
};

