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
	vector<Node*> performedSteps;
	vector<Node*> potentialNextSteps;
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

		if (nodeMap.count(currentDep) == 0)
		{
			nodeMap[currentDep] = Node(currentDep);
		}

		nodeMap[currentId].NextSteps.push_back(&nodeMap[currentDep]);
		nodeMap[currentDep].Dependencies.push_back(&nodeMap[currentId]);
	}

	// Record first step
	result.push_back(firstStep);
	performedSteps.push_back(&nodeMap[firstStep]);

	Node* start = &nodeMap[firstStep];
	potentialNextSteps = start->NextSteps;
	while (performedSteps.size() < nodeMap.size())
	{
		Node* lowestNext(potentialNextSteps.front());
		int lowestIndex(0);
		// Find next lowest step that have all of its dependencies satisfied
		for (int i = 0; i < potentialNextSteps.size(); i++)
		{
			if (potentialNextSteps[i]->Id < lowestNext->Id)
			{
				// Check that we've performed its dependenies
				size_t completedDeps(0);
				for (auto const s : potentialNextSteps[i]->Dependencies)
				{
					if (find(performedSteps.begin(), performedSteps.end(), s) != performedSteps.end())
					{
						completedDeps++;
					}
				}

				if (completedDeps == potentialNextSteps[i]->Dependencies.size())
				{
					lowestNext = potentialNextSteps[i];
					lowestIndex = i;
				}
			}
		}

		// Record next step
		performedSteps.push_back(lowestNext);
		result += lowestNext->Id;
		for (auto const s : lowestNext->NextSteps)
		{
			// If next step isn't already in the potentialNextSteps...
			// Add the steps that may be available
			if (find(potentialNextSteps.begin(), potentialNextSteps.end(), s) == potentialNextSteps.end())
			{
				potentialNextSteps.push_back(s);
			}
		}

		potentialNextSteps.erase(potentialNextSteps.begin() + lowestIndex);
	}

	return result;
}

string Day07::Part2(vector<string> nodeLines)
{
	return "";
}
