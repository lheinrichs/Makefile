#include<iostream>
#include<cstdlib>
#include "DepGraph.hpp"

int main(int argc, const char *argv[] ) 
{
    if( argc != 2 ) {
        std::cout << "usage: " << argv[0] << " name-of-a-makefile\n";
        exit(1);
    }
    DepGraph *make = new DepGraph(argv[1]);
    make->parseDepGraph();
    make -> print();
    if( make->isCyclic() )  {
        std::cerr << "Input graph has cycles.\n";
        exit(1);
    }
    std::cout << "Running make" << std::endl;
    make->runMake();
    return 0;
}
