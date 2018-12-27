#include <vector>
#pragma once
class Node
{
public:
	Node();
	Node(char id);
	Node(const Node& n);
	~Node();
	char Id;
	std::vector<Node*> NextSteps;
	std::vector<Node*> Dependencies;
};

