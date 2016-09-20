//Programer: Dalton Cole
//Date: April 13, 2014
//Class and section: CS153, A
//Description: stack.cpp file

#include "stack.h"

template <typename T>
void Stack<T>::clear()
{
  while(m_top -> m_next != NULL)
  {
  	LinkedList<T>* tmp = m_top -> m_next;
  	delete m_top;
  	m_top = tmp;
  }
  //delete m_top;
  return;
}

template <typename T>
void Stack<T>::push(const T& x)
{
  LinkedList<T> * tmp = new LinkedList<T>(x, m_top);
  m_top = tmp;
  return;
}

template <typename T>
void Stack<T>::pop()
{
  if(m_top -> m_next != NULL)
  {
    LinkedList<T> * tmp = m_top;
    m_top = m_top -> m_next;
    delete tmp;
  }
  return;
}

template <typename T>
const T& Stack<T>::top() const throw (Oops)
{
  try
  {
    if(m_top -> m_next == NULL)
    {
      Oops boo_boo("ERROR IN STACK_TOP: stack is empty");
      throw boo_boo;
    }
  }
  catch(Oops boo_boo)
  {
    throw boo_boo;
  }
  return (m_top -> m_data);
}

template <typename T>
bool Stack<T>::isEmpty() const
{
  return (m_top -> m_next == NULL);
}
