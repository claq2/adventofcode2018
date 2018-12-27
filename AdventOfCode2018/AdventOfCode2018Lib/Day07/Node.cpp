#include "stdafx.h"
#include "Node.h"

Node::Node()
{
}


Node::Node(char id)
{
	Id = id;
}

Node::Node(const Node& n)
{
	Id = n.Id;
	Dependencies = n.Dependencies;
	NextSteps = n.NextSteps;
}

Node::~Node()
{
}
