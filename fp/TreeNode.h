//Dalton Cole
//Class and section: cs153, A
//Date: 5/6/2014
//Description: TreeNode

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

template < typename T >
struct TreeNode
{
   T m_data;
   TreeNode* m_right;
   TreeNode* m_left;

   TreeNode() : m_left(NULL), m_right(NULL) {}

   TreeNode(T& x, TreeNode<T>* left, TreeNode<T>* right) : m_data(x), m_left(left), m_right(right) {}
};

#endif