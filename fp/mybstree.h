//Dalton Cole
//Class and section: cs153, A
//Date: 5/6/2014
//Description: mybstree.h, derived from abstractbstree.h

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"
#include "TreeNode.h"

template < typename T >
class bstree : public AbstractBSTree<T>
{
private:
	TreeNode<T>* m_root;
	int m_size;
  
public:

//Purpose:
//Returns:
  bstree() : m_root(NULL) { m_size = 0;}

//
//
  bstree(int size, TreeNode<T>* root) : m_size(size), m_root(root) {}


   /*** ---- Big Three ---- */

//Purpose:
//Returns:
// ---inline---
  ~bstree() {clear();}

//Purpose:
//Returns:
  const bstree<T>& operator = (const bstree<T>& rhs);

//
  TreeNode<T>* clone(TreeNode<T>* t);

//Purpose:
//Returns:
  bstree(const bstree<T>& rhs);
	  
   /*** ---- Accessor Operations ---- */
  
// Purpose: Accessor function for the number of elements in the tree
// Returns: number of elements in the tree 
  virtual int size() const;


// Purpose: Checks if a tree is empty
// Returns: 'true' if the tree is empty
//     'false' otherwise  
  virtual bool isEmpty() const;


// Purpose: Returns the height of the tree
// Returns: height the tree 
  virtual int height() const;

//
//
  int r_height(TreeNode<T>* tmp, int max_height, int height) const;

// Purpose: finds the maximum element in the Tree
// Returns: a const reference to the maximum element
  virtual const T& findMax() const;


// Purpose: finds the minimum element in the Tree
// Returns: a const reference to the minimum element
  virtual const T& findMin() const;


// Purpose: finds an element in the Tree
// Parameters: x is value to be found 
// Returns: 
//     If The tree contains x then  
//         return N, the level of the node containing x
//         (the root is considered level 0)
//     If The tree does not contains x then  
//         return -N, where N is the level of the tree 
//         reached in the search + 1
  virtual int contains(const T& x) const;


    
  /*** ---- Mutator Operations ---- */

  
// Purpose: Clears the Tree
// Postconditions: an empty Tree
  virtual void clear();

//
  void r_clear(TreeNode<T>* t);


// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
  virtual void insert(const T& x);

//
//
  void r_insert(TreeNode<T>* tmp, const T& x);

    
// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
  virtual void remove(const T& x);

//
  int r_remove(TreeNode<T>* t, const T& x);
          
     
  /*** ---- Output Operations ---- */

// Purpose: Prints the Tree in Pre-Order    
  virtual void printPreOrder() const;

//
  void r_printPreOrder(TreeNode<T>* t) const;


// Purpose: Prints the Tree in Pre-Order    
  virtual void printPostOrder() const; 

//
  void r_printPostOrder(TreeNode<T>* t) const;

// Purpose: Prints the Tree In-Order with formatting
//     each level indented 4 spaces, one element per line    
  virtual void print() const;

//
//
  void prettyPrint (const TreeNode<T>* t, int pad) const;
};

#include "mybstree.cpp"

#endif