#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<iostream>
#include<string>
#include<vector>
#include "systemInterface.hpp"

class GraphNode {
public:
    GraphNode( std::string name );
    std::string getName();
    void setTimestamp();
    int getTimestamp();
    std::vector<GraphNode *> * &dependentNodes() { return _listOfDependentNodes; }
    void setCommand(std::string cmnd);
    std::string getCommand();
    void runCommand();  // execute the command associated with this node.
    void addDependentNode(GraphNode *child);
    bool onPath();
    void onPath(bool v);
    bool wasMade();
    void wasMade(bool v);
    bool isATarget();
    void isATarget(bool v);
    int numDependentNodes();
    void print();

private:
    std::string _name, _command;
    long _timestamp;
    std::vector<GraphNode *> *_listOfDependentNodes;

    bool _onPath, _isATarget, _wasMade;
};

#endif
