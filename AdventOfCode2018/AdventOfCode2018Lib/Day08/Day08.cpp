#include "stdafx.h"
#include "Day08.h"
#include <sstream>
#include <fstream>

using namespace std;

Day08::Day08()
{
}


Day08::~Day08()
{
}

vector<int> Day08::ReadInput()
{
	vector<int> result;
	ifstream file;
	string currentGuardLine;

	file.open("Day08.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	string line;
	getline(file, line);

	file.close();

	istringstream is(line);
	int n;
	while (is >> n) {
		result.push_back(n);
	}

	return result;
}

string Day08::Part1(vector<int> value)
{
	int sum(0);
	Leaf root;
	root.BuildChildren(value);
	return to_string(sum);
}

string Day08::Part2(vector<int> value)
{
	return "";
}

Day08::Leaf::Leaf()
{
}

Day08::Leaf::Leaf(vector<int> values)
{
	if (values[0] == 0)
	{
		// No children, extract metadata
		// Extract metadata
		for (int i = 0; i < values[1]; i++)
		{
			Metadata.push_back(values[values.size() - 1]);
			values.erase(values.end() - 1);
		}
	}
	else
	{
		// Consume values to get children
	}
}

void Day08::Leaf::BuildChildren(vector<int> values)
{
	if (values[0] == 0)
	{
		// No grand children, build the 1 child
		auto leaf = make_shared<Leaf>();
		// Extract metadata
		for (int i = 0; i < values[1]; i++)
		{
			leaf->Metadata.push_back(values[values.size() - 1]);
			values.erase(values.end() - 1);
		}

		Children.push_back(leaf);
	}

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
