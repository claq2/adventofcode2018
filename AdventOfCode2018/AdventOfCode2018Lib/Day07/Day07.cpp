#include "stdafx.h"
#include "Day07.h"
#include <fstream>
#include "Node.h"
#include <map>

using namespace std;

Day07::Day07()
{
}


Day07::~Day07()
{
}

vector<string> Day07::ReadInput()
{
	vector<string> result;
	ifstream file;
	string currentLine;

	file.open("Day07.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	tm tm = {};
	while (getline(file, currentLine))
	{
		result.push_back(currentLine);
	}

	file.close();
	return result;
}

string Day07::Part1(vector<string> nodeLines)
{
	string result;
	//vector<Node> nodes;
	map<char, Node> nodeMap;
	map <char, bool> performedSteps;
	// step = index 5
	// dep = index 36
	char firstStep;

	// Build dep graph
	for (auto const& line : nodeLines)
	{
		char currentId(line[5]);
		char currentDep(line[36]);
		if (line == nodeLines.front())
		{
			firstStep = currentId;
			result.push_back(firstStep);
		}

		if (nodeMap.count(currentId) == 0)
		{
			nodeMap[currentId] = Node(currentId);
			nodeMap[currentId].NextSteps.push_back(Node(currentDep));
		}
		else
		{
			nodeMap[currentId].NextSteps.push_back(Node(currentDep));
		}

		if (nodeMap.count(currentDep) == 0)
		{
			nodeMap[currentDep] = Node(currentDep);
		}
	}

	Node start = nodeMap[firstStep];

	return result;
}

string Day07::Part2(vector<string> nodeLines)
{
	return "";
}
