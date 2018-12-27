#include "stdafx.h"
#include "Day07.h"
#include <fstream>
#include "Node.h"
#include <map>
#include <algorithm>

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
	vector<Node> performedSteps;
	vector<Node> nextSteps;
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
		}

		if (nodeMap.count(currentId) == 0)
		{
			nodeMap[currentId] = Node(currentId);
		}

		nodeMap[currentId].NextSteps.push_back(Node(currentDep));

		if (nodeMap.count(currentDep) == 0)
		{
			nodeMap[currentDep] = Node(currentDep);
		}

		nodeMap[currentDep].Dependencies.push_back(nodeMap[currentId]);
	}

	// Record first step
	result.push_back(firstStep);
	performedSteps.push_back(nodeMap[firstStep]);

	Node start = nodeMap[firstStep];
	nextSteps = start.NextSteps;
	/*while (performedSteps.size() > nodeMap.size())
	{*/
		Node lowestNext(nextSteps.front());
		int lowestIndex(0);
		// find next lowest step
		for (int i = 0; i < nextSteps.size(); i++)
		{
			if (nextSteps[i].Id < lowestNext.Id)
			{
				lowestNext = nextSteps[i];
				lowestIndex = i;
			}
		}

		// Record next step
		performedSteps.push_back(lowestNext);
		result += lowestNext.Id;
		// Add the steps that may be available
		nextSteps.insert(nextSteps.end(), lowestNext.NextSteps.begin(), lowestNext.NextSteps.end());
		// Remove the step we did
		nextSteps.erase(nextSteps.begin() + lowestIndex);

	/*}*/

	return result;
}

string Day07::Part2(vector<string> nodeLines)
{
	return "";
}
