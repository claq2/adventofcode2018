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

string Day08::Part1(vector<int> values)
{
	int sum(0);
	shared_ptr<Leaf> root(BuildTree(values));


	// Walk the tree
	sum += SumMetadata(root);
	return to_string(sum);
}

shared_ptr<Day08::Leaf> Day08::BuildTree(vector<int> &values)
{
	shared_ptr<Leaf> root;
	root = make_shared<Leaf>();
	root->Parent = nullptr;
	root->ExpectedChildren = values.front();
	values.erase(values.begin());
	root->ExpectedMetadata = values.front();
	values.erase(values.begin());

	for (int i = 0; i < root->ExpectedChildren; i++)
	{
		root->Children.push_back(ExtractChild(values, root));
	}

	for (int i = 0; i < root->ExpectedMetadata; i++)
	{
		root->Metadata.push_back(values.front());
		values.erase(values.begin());
	}

	return root;
}

shared_ptr<Day08::Leaf> Day08::ExtractChild(
	vector<int> &values,
	shared_ptr<Leaf> parent)
{
	shared_ptr<Leaf> result;
	result = make_shared<Leaf>();
	result->ExpectedChildren = values.front();
	values.erase(values.begin());
	result->ExpectedMetadata = values.front();
	values.erase(values.begin());
	result->Parent = parent;

	for (int i = 0; i < result->ExpectedChildren; i++)
	{
		result->Children.push_back(ExtractChild(values, result));
	}

	for (int i = 0; i < result->ExpectedMetadata; i++)
	{
		result->Metadata.push_back(values.front());
		values.erase(values.begin());
	}

	return result;
}

int Day08::SumMetadata(shared_ptr<Leaf> leaf)
{
	int sum(0);
	for (auto const& m : leaf->Metadata)
	{
		sum += m;
	}

	for (auto const& l : leaf->Children)
	{
		sum += SumMetadata(l);
	}

	return sum;
}

int Day08::SumNodes(shared_ptr<Leaf> leaf)
{
	int sum(0);
	if (leaf->Children.size() == 0)
	{
		// No children, sum the metadata
		for (auto const& m : leaf->Metadata)
		{
			sum += m;
		}
	}
	else
	{
		for (auto const& m : leaf->Metadata)
		{
			if (m != 0 && leaf->Children.size() >= m)
			{
				sum += SumNodes(leaf->Children[m - 1]);
			}
		}
	}

	return sum;
}

string Day08::Part2(vector<int> values)
{
	int sum(0);
	shared_ptr<Leaf> root(BuildTree(values));
	sum += SumNodes(root);
	return to_string(sum);
}

Day08::Leaf::Leaf()
{
}
