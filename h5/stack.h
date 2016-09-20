//Programer: Dalton Cole
//Date: April 13, 2014
//Class and section: CS153, A
//Description: stack.h file

#ifndef STACK_H
#define STACK_H

#include "abstractstack.h"
#include "linkedlist.h"
#include <iostream>
using namespace std;

template < typename T>
class Stack : public AbstractStack <T>
{
  public:
  	//int m_size; //size of the stack
  	LinkedList<T>* m_top; //top of the stack

    //Purpose: To be a constructor
    //Parameters: takes in nothing, must be nothing
    //Post: sets size to 0
    //---Inline---
    Stack() : m_top() {}

  	// Purpose: clears the stack
    // Postconditions: the stack is now empty
    virtual void clear();

    // Purpose: push an element into the stack
    // Parameters: x is the value to push into the stack
    // Postconditions: x is now the element at the top of the stack,
    virtual void push(const T& x);

    // Purpose: pop the stack
    // Postconditions: the element formerly at the top of the stack has
    // been removed
    // Note: Poping an empty stack results in an empty stack.
    virtual void pop();

    // Purpose: looks at the top of the stack
    // Returns: a const reference to the element currently on top of the stack
    // Exception: if the stack is empty, THROW a 'Oops' object with an error message!!!
    virtual const T& top() const throw ( Oops );

    // Purpose: Checks if a stack is empty
    // Returns: 'true' if the stack is empty
    //     'false' otherwise
    virtual bool isEmpty() const;
    
    //Purpose: to deallocate all alocated memory
    //--inline--
    virtual ~Stack() { delete m_top;}
};

template <typename T>
ostream& operator << (ostream& out, const Stack<T>& xstack)
{
  out << "[";
  const Stack<T>* p = &xstack;
  const LinkedList<T>* t = p -> m_top;
  while( t -> m_next -> m_next != NULL)
  {
    out << t -> m_data << ", ";
    t = t -> m_next;
  }
  if(t -> m_next != NULL)
    out << t -> m_data;
  out << "]";
  return out;
}

#include "stack.hpp"

#endif
