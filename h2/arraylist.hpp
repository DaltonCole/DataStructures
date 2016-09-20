//Name: COLE,DALTON
//Class and Section: CS153, A
//Date:2/16/13
//Description: arraylist.hpp file

//#include "arraylist.h"

#include<iostream>
using namespace std;

template<typename T>
ArrayList<T>::~ArrayList()
{
  delete [] m_data;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator = (const ArrayList<T>& rhs)
{
  if(this != & rhs) //allias test
  {
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    delete [] m_data; 
    m_data = new T[m_max];
    for (int i =0; i < m_size; i++)
    m_data[i] = rhs.m_data[i];
  }
  return *this;
}

template <typename T>
ArrayList<T>::ArrayList (const ArrayList<T>& cpy)
{
  m_data = new T[1];
  *this = cpy;
}

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  if(m_size == 0)
  {
    cout << "!-- ERROR : PANIC IN ARRAYLIST!! *list is empty*" << endl;
    return m_errobj;
  }  
  else
  {
    return m_data[0];
  }
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  if(i >= m_size)
  {
    cout << "!-- ERROR : PANIC IN ARRAYLIST.[] *NOT WITHIN BOUNDS*" << endl;
    return m_errobj;
  }
  else  
    return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator [] (int i) const
{
  if(i >= m_size)
  {
    cout << "!--ERROR : PANIC IN ARRAYLIST.[] *NOT WITHIN BOUNDS*" << endl;
    return m_errobj;
  }
  else
    return m_data[i];
}

template <typename T>
int ArrayList<T>::find(const T& x)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_data[i] == x)
      return i;
  }
  //if match is not found, return -1
  return -1;
}

template <typename T>
void ArrayList<T>::clear()
{
  m_size = 0;
  m_max = 0;
  delete m_data;
  m_data = NULL;
  return;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
/*-------------------------------------------------------
  if the array is full, one double the size is created +1
  is created (incase m_max is zero)
-------------------------------------------------------*/
  if(m_size == m_max)
  {
    T* tmp;
    tmp = new T[(m_max+1)*2]; 
    for(int i = 0; i < m_size; i++)
    {
      tmp[i] = m_data[i];
    }
    if(m_data != NULL)
      delete [] m_data;
    m_data = tmp;
    m_max = (2*(1+m_max));
  }
  m_data[m_size] = x;
  m_size++;
  return;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  //checks to see if i is within the size
  if(i > m_size)
  {
    cout << "!--ERROR : PANIC IN ARRAYLIST!!.insert *NOT WITHIN BOUNDS*" << endl;
  }
  else
  {
    if(m_size == m_max)
    {
      T* tmp;
      tmp = new T[m_max * 2];
      for(int k = 0; k < m_max; k++)
      {
        tmp[k] = m_data[k];
      }
      if(m_data != NULL)
        delete[] m_data;
      m_data = tmp;
      m_max = 2 * m_max;
    }
    T* tmq;
    tmq = new T[m_max];
    for(int j = 0; j < i; j++)
    {
      tmq[j] = m_data[j];
    } 
    tmq[i] = x;
    for(int m = (i+1); m < (m_size+1); m++)
    {
      tmq[m] = m_data[m-1];
    }
    delete[] m_data;
    m_data = tmq;
    m_size++;
  }
  return;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  if(i > m_size)
  {
    cout << "!-- ERROR : PANIC IN ARRAYLIST!!.remove *NOT WITHIN BOUNDS*" << endl;
  }
  else
  {
    if(i<m_size && i >=0)
    {
      for(int k = i; k< m_size-1; k++)
        m_data[k] = m_data[k+1];
    }
    m_size--;
  
    if(m_size < (m_max/4))
    {
      T* tmq;
      tmq = new T[m_max/2];
      for(int k = 0; k < m_size; k++)
      {
        tmq[k] = m_data[k];
      }
      if(m_data != NULL)
        delete[] m_data;
      m_data = tmq;
      m_max = m_max/2;
    }  
  }
  return;  
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if( (i > m_size) || (k > m_size))
  {
    cout << "!-- ERROR : PANIC IN ARRAYLIST!!.swap *NOT WITHIN BOUNDS*" << endl;
  }
  else
  {
    T tmp = m_data[k];
    m_data[k] = m_data[i];
    m_data[i] = tmp;
  }
  return;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  int counter = 0; //counter for alist
  T* tmp;
  tmp = new T[m_max *2];
  for(int i = 0; i < m_size; i++)
  {
    tmp[i] = m_data[i];
  }
  for(int i = m_size; i < (m_size + alist.m_size); i++) //might be -1
  {
    tmp[i] = alist.m_data[counter];
    counter++;
  }
  delete[] m_data;
  m_data = tmp;
  m_max = (2 * m_max);
  m_size = (m_size + alist.m_size);
  return;
}

template <typename T>
void ArrayList<T>::purge()
{
  for(int i = 0; i < m_size; i++)
  {
    for(int j = i+1; j < m_size; j++)
    {
      if(m_data[i] == m_data[j])
      {
        remove(j);
      }
    } 
  }
  return;
}






