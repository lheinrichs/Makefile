#include "DepGraph.hpp"
#include "GraphNode.hpp"
#include "systemInterface.hpp"
#include <cstdlib>

using namespace std;

DepGraph::DepGraph(string name)
{
  _fileToMake = name;
  _targetToMake = "";
}

void DepGraph:: print()
{
  firstTarget -> print();
}

void DepGraph:: parseDepGraph()
{
  Reader *read = new Reader (_fileToMake);
  
  while(true)
    {
      Token token = readAndProcessDependencyPair(read);
      if(token.isEOF())
	{
	  print();
	  return;
	}
      token = read -> getToken();

      if(!token.isCommand())
	{
	  cout << "No command found after dependency line" << endl;
	  exit(1);
	}
      if(_tree -> find(_targetToMake) != NULL)
	_tree -> find(_targetToMake) -> setCommand(token.getCommand());

    }
}

void DepGraph:: runMake()
{
  return runMake(firstTarget);
}

bool DepGraph:: isCyclic()
{
  return isCyclic(firstTarget);
}

Token DepGraph:: readAndProcessDependencyPair(Reader *read)
{
  Token target = read -> getToken();
  if(target.isEOF())
    return target;

  if(!target.isName())
    {
      cout << "The first token of a dependencey line should be a name-token." << endl;
      exit(1);
    }
  cout << "Target is: " << target.getName() << endl;



  GraphNode *parent = new GraphNode(target.getName());
  

  _targetToMake = parent -> getName();

  Token colon = read -> getToken();
  if(!colon.isColon())
    {
      cout << "Missing  colon character on the dependency line." << endl;
      exit(1);
    }

  Token token;
  do {
    token = read -> getToken();
    if(token.isName())
      {
	GraphNode *children;
	if(_tree != NULL && _tree -> find(token.getName()) != NULL && _tree -> find(token.getName()) -> numDependentNodes() != 0)
	  children = _tree -> find(token.getName());
	else
	  children  = new GraphNode(token.getName());
	parent -> addDependentNode(children);
      }

  }while(token.isName());

  if(_tree == NULL)
    {
      _tree = new MakeTree(parent);
      firstTarget = parent;
    }
  else
    _tree -> insert(parent);

  for(int i = 0; i < parent -> dependentNodes() -> size(); i++)
    _tree -> insert(parent -> dependentNodes() -> at(i));


  if(! token.isEOL())
    {
      cout << "Dependency line contains a non-name token." << endl;
      exit(1);
    }
  return token;
 
}

bool DepGraph:: isCyclic(GraphNode *cycle)
{
  if(cycle -> onPath())
    return true;
  cycle -> onPath(true);
  cycle -> setTimestamp();
  for(int i = 0; i < cycle -> numDependentNodes(); i++)
    {
      if(isCyclic(cycle -> dependentNodes() -> at(i)))
	return true;
    }
  return false;
}

void DepGraph:: runMake(GraphNode *p)
{
 for(int i = 0; i < p -> numDependentNodes(); i++)
   runMake(p -> dependentNodes() -> at(i));
 for(int i = 0; i < p -> numDependentNodes(); i++)
   {
     if( !p -> wasMade() && p -> getTimestamp() < p-> dependentNodes() -> at(i) -> getTimestamp())
       {
	 p -> runCommand();
	 p -> wasMade(true);
	 p -> setTimestamp();
       }
   }

}
