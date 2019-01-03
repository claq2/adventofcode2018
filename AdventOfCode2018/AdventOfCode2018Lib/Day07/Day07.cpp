#include "stdafx.h"
#include "Day07.h"
#include <fstream>
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

	map<char, Node> nodeMap(BuildGraph(nodeLines));


	// Potential steps starts with all nodes that have 0 dependencies
	// Find items with 0 dependencies and add them to potentialNextSteps
	vector<Node*> potentialNextSteps;
	for (auto & n : nodeMap)
	{
		if (n.second.Dependencies.size() == 0)
		{
			potentialNextSteps.push_back(&n.second);
		}
	}

	vector<Node*> performedSteps;
	while (performedSteps.size() < nodeMap.size())
	{

		// Start lowest at highest ID value by first finding the highest one...
		Node* lowestNext;
		char highestId('A');

		vector<Node*>::iterator ni;
		for (auto i = potentialNextSteps.begin(); i != potentialNextSteps.end(); i++)
		{
			if ((*i)->Id >= highestId)
			{
				ni = i;
				highestId = (*i)->Id;
			}
		}


		for (int i = 0; i < potentialNextSteps.size(); i++)
		{
			if (potentialNextSteps[i]->Id >= highestId)
			{
				highestId = potentialNextSteps[i]->Id;
				lowestNext = potentialNextSteps[i];
			}
		}

		// ... then find lowest step that have all of its dependencies satisfied
		int lowestIndex(0);
		for (int i = 0; i < potentialNextSteps.size(); i++)
		{
			if (potentialNextSteps[i]->Id <= lowestNext->Id)
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

		// Record next step if it hasn't already been done
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
	const int numberOfWorkers(2); // 5 for non-test
	const int stepBaseTime(0); // 60 for non-test
	map<int, char> workerMap; // Who's working on what
	vector<char> steps;
	vector<char> completedSteps;

	map<char, Node> nodeMap(BuildGraph(nodeLines));

	// Find all the available start steps, order them and assign them to workers
	// Potential steps starts with all nodes that have 0 dependencies
	// Find items with 0 dependencies and add them to potentialNextSteps
	vector<Node*> potentialNextSteps;
	for (auto & n : nodeMap)
	{
		if (n.second.Dependencies.size() == 0)
		{
			potentialNextSteps.push_back(&n.second);
		}
	}

	// Loop until we've completed as many steps as were in the starting string
	int seconds(0);
	while (completedSteps.size() < nodeMap.size())
	{
		break;
	}

	return to_string(seconds);
}

std::map<char, Node> Day07::BuildGraph(std::vector<std::string> nodeLines)
{
	// Build dep graph
	map<char, Node> nodeMap;
	for (auto const& line : nodeLines)
	{
		// step = index 5
		// dep = index 36
		char currentId(line[5]);
		char currentDep(line[36]);

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

	return nodeMap;
}
