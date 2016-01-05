
#include "TreeNode.hpp"
#include "GraphNode.hpp"

using namespace std;

TreeNode::TreeNode(GraphNode *nNode)
{
  makeNode = nNode;
  leftSubtree = NULL;
  rightSubtree = NULL;
}

TreeNode* TreeNode:: left()
{
  return leftSubtree;
}

void TreeNode:: left(TreeNode *leftPtr)
{
  leftSubtree = leftPtr;
} 

TreeNode* TreeNode:: right()
{
  return rightSubtree;
}

void TreeNode:: right(TreeNode *rightPtr)
{
  rightSubtree = rightPtr;
}

void TreeNode:: print()
{
}

GraphNode* TreeNode:: graphNode()
{
  return makeNode;
}
