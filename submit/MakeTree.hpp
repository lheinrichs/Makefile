#ifndef _MakeTree_hpp
#define _MakeTree_hpp

#include "TreeNode.hpp"
#include<iostream>
#include<string>

using namespace std;


class MakeTree {
public:
  MakeTree(GraphNode *gNode) {_root = new TreeNode(gNode); }
  void insert( GraphNode *nNode ) { _root = insert(_root, nNode); }
  GraphNode *find( std::string name ) { return find( _root, name); }
  void print() { print(_root); }   // print the tree using in-order traversal
  TreeNode  *getRoot() { return _root; }

private:
  TreeNode *insert(TreeNode *tNode, GraphNode *nNode);
  void print(TreeNode *root);
  GraphNode *find(TreeNode *tNode, string name);
    
  TreeNode *_root;
};

#endif

