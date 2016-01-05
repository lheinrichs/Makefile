#ifndef _DepGraph_hpp
#define _DepGraph_hpp

#include<iostream>
#include<cstring>

#include "MakeTree.hpp"
#include "Token.hpp"
#include "Reader.hpp"

class DepGraph {
public:
    DepGraph( std::string name );
    void print();
    void parseDepGraph();
    void runMake();
    bool isCyclic();

private:
    Token readAndProcessDependencyPair(Reader *);
    bool isCyclic(GraphNode *);
    void runMake( GraphNode *p );

private:
    std::string _fileToMake, _targetToMake;
    GraphNode *firstTarget;
    MakeTree *_tree;
};

#endif
