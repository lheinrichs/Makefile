#include "MakeTree.hpp"
#include "TreeNode.hpp"
#include "GraphNode.hpp"
#include <string.h>

using namespace std;

GraphNode *MakeTree::find( TreeNode *tNode, string name )
{
  if( tNode == NULL)
    return NULL;
  if( strcmp( tNode -> graphNode() -> getName().c_str(), name.c_str() ) == 0 )
    return tNode -> graphNode();
  if( strcmp( tNode -> graphNode() -> getName().c_str(), name.c_str() ) > 0 )
    return find( tNode -> left(), name );
  return find( tNode -> right(), name );
}


void MakeTree:: print(TreeNode *root)
{
  if(root == NULL)
    return;
  print(root -> left());
  cout << root -> graphNode() -> getName()<< endl;
  print(root -> right());
}

TreeNode *MakeTree:: insert(TreeNode *tNode, GraphNode *nNode)
{
  if(tNode == NULL)
    return new TreeNode(nNode);
  if(strcmp(tNode -> graphNode() -> getName().c_str(), nNode -> getName().c_str()) == 0)
    tNode -> graphNode() -> dependentNodes() = nNode -> dependentNodes();
  if(strcmp(tNode -> graphNode() -> getName().c_str(), nNode -> getName().c_str()) < 0)
    tNode -> right(insert( tNode -> right(), nNode));
  else
    tNode -> left(insert( tNode -> left(), nNode));
  return tNode;

}


