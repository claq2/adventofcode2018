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
		auto ni = FindNextAvailableStep(potentialNextSteps, performedSteps);

		// Record next step if it hasn't already been done
		performedSteps.push_back(*ni);
		result += (*ni)->Id;
		Node* currentStep(*ni);
		potentialNextSteps.erase(ni);
		for (auto const s : currentStep->NextSteps)
		{
			// If next step isn't already in the potentialNextSteps...
			// Add the steps that may be available
			if (find(potentialNextSteps.begin(), potentialNextSteps.end(), s) == potentialNextSteps.end())
			{
				potentialNextSteps.push_back(s);
			}
		}
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
		// TODO: find free workers

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

vector<Node*>::iterator Day07::FindNextAvailableStep(vector<Node *> &potentialNextSteps, vector<Node *> &performedSteps)
{
	// Start lowest at highest ID value by first finding the highest one...
	vector<Node*>::iterator ni;
	char highestId('A');
	for (auto i = potentialNextSteps.begin(); i != potentialNextSteps.end(); i++)
	{
		if ((*i)->Id >= highestId)
		{
			ni = i;
			highestId = (*i)->Id;
		}
	}

	// ... then find lowest step that have all of its dependencies satisfied
	for (auto i = potentialNextSteps.begin(); i != potentialNextSteps.end(); i++)
	{
		if ((*i)->Id <= (*ni)->Id)
		{
			// Check that we've performed its dependenies
			size_t completedDeps(0);
			for (auto const s : (*i)->Dependencies)
			{
				if (find(performedSteps.begin(), performedSteps.end(), s) != performedSteps.end())
				{
					completedDeps++;
				}
			}

			if (completedDeps == (*i)->Dependencies.size())
			{
				ni = i;
			}
		}
	}

	return ni;
}
