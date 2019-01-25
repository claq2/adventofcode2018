#include "stdafx.h"
#include "Day07.h"

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
	const int numberOfWorkers(5); // 5 for non-test
	const int stepBaseTime(60); // 60 for non-test
	const char freeWorkerValue('.');
	map<int, char> workerMap; // Who's working on what
	map<int, int> workerTimes; // How long each worker has been working on its task
	//vector<char> steps;
	//vector<char> completedSteps;

	// Initialize worker map
	for (int i = 0; i < numberOfWorkers; i++)
	{
		workerMap[i] = freeWorkerValue;
	}

	map<char, Node> nodeMap(BuildGraph(nodeLines));

	// Find all the available start steps
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

	stringstream state;
	// Loop until we've completed as many steps as were in the starting string
	int seconds(-1);
	vector<Node*> performedSteps;
	while (performedSteps.size() < nodeMap.size())
	{
		// Check to see if workers are done any steps
		for (auto wi = workerMap.begin(); wi != workerMap.end(); wi++)
		{
			// A = 65
			if (workerTimes[(*wi).first] == (*wi).second - 64 + stepBaseTime)
			{
				// Worker is done
				// Record step
				performedSteps.push_back(&nodeMap[(*wi).second]);
				// Populate next available steps
				for (auto const s : (&nodeMap[(*wi).second])->NextSteps)
				{
					// If next step isn't already in the potentialNextSteps...
					// Add the steps that may be available
					if (find(potentialNextSteps.begin(), potentialNextSteps.end(), s) == potentialNextSteps.end())
					{
						potentialNextSteps.push_back(s);
					}
				}

				// Free worker
				workerTimes[(*wi).first] = 0; // Reset worker time
				(*wi).second = freeWorkerValue;
			}
		}

		// TODO: make it delay starting something that depends on something we just finished in this iteration
		// E.g. D->E in sample

		// Find free workers and give them work
		for (int i = 0; i < numberOfWorkers; i++)
		{
			if (workerMap[i] == freeWorkerValue)
			{
				// Found free worker, see if there's an available step and no one's working on it
				auto ni = FindNextAvailableStep(potentialNextSteps, performedSteps);

				if (ni != potentialNextSteps.end())
				{
					// Other workers working on this item?
					bool otherWorkerWorkingOnItem(false);
					for (int j = 0; j < numberOfWorkers; j++)
					{
						if (i != j && workerMap[j] == (*ni)->Id)
						{
							otherWorkerWorkingOnItem = true;
						}
					}

					if (!otherWorkerWorkingOnItem)
					{
						// Assign work
						workerMap[i] = (*ni)->Id;
						workerTimes[i] = 0;
						// Remove from next steps
						potentialNextSteps.erase(ni);
					}
				}
			}
		}

		seconds++;
		// Update workers' times
		for (auto & wt : workerTimes)
		{
			if (workerMap[wt.first] != freeWorkerValue)
			{
				wt.second++;
			}
		}

		state << seconds << " ";
		for (auto & wm : workerMap)
		{
			state << wm.first << ":" << wm.second << " ";
		}

		state << endl;
	}

	string s(state.str());

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
	vector<Node*>::iterator ni(potentialNextSteps.end());
	char highestId('A');
	for (auto i = potentialNextSteps.begin(); i != potentialNextSteps.end(); i++)
	{
		if ((*i)->Id >= highestId)
		{
			ni = i;
			highestId = (*i)->Id;
		}
	}

	// ni points to the highest ID element

	// ... then find lowest step that have all of its dependencies satisfied
	bool foundAvailableItem(false);
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
				foundAvailableItem = true;
				ni = i;
			}
		}
	}

	// ni may still point to the highest ID item, but there might not be an available item
	return foundAvailableItem ? ni : potentialNextSteps.end();
}
