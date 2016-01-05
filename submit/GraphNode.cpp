#include "GraphNode.hpp"
#include "TreeNode.hpp"
#include <cstring>

using namespace std;

GraphNode::GraphNode(string name)
{
  _name = name;
  _command = "";
  _timestamp = 0;
  _onPath = false;
  _isATarget= false;
  _wasMade = false;
  _listOfDependentNodes = new vector<GraphNode *>;
}

string GraphNode:: getName()
{
  return _name;
}

void GraphNode:: setTimestamp()
{
  timestamp(_name.c_str(), &_timestamp);
}

int GraphNode:: getTimestamp()
{
  return _timestamp;
}

void GraphNode:: setCommand(string cmnd)
{
  _command = cmnd;
}

string GraphNode:: getCommand()
{
  return _command;
}

void GraphNode:: runCommand()
{
  executeCommand(_command.c_str());
}

void GraphNode:: addDependentNode(GraphNode *child)
{
  dependentNodes() -> push_back(child);
}

bool GraphNode:: onPath()
{
  return _onPath;
}

void GraphNode:: onPath(bool v)
{
  _onPath = v;
}

bool GraphNode:: wasMade()
{
  return _wasMade;
}

void GraphNode:: wasMade(bool v)
{
  _wasMade = v;
}

bool GraphNode:: isATarget()
{
  return _isATarget;
}

void GraphNode:: isATarget(bool v)
{
  _isATarget = v;
}

int GraphNode:: numDependentNodes()
{
  return dependentNodes() -> size();
}

void GraphNode:: print()
{

}
