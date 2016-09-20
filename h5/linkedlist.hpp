//Name: COLE, DALTON
//Class and Section: CS153, A
//Date: 2/28/13
//Despription: linkedlist.hpp file

using namespace std;

template <typename T>
const LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
{
/*------------------------------------
  1. Checks to see if the two values are the same
  2. If not, creats a bool to check if the sentinal is reached
  3. clear LHS, so it is now NULL
  4. Makes a new LinkedList
  5. Makes a LL pointer point to rhs's next
  6. Sets this values to be the same as rhs
  7. While not at the sentinal:
     8. new LL's data is the same as rhs's data
     9. if not at the sentinal:
       10. Makes a new LL
       11. p's next = t
       12. p = p's next
       13. q = q's next
    14. if at the sentinal, exit the loop
  15. return *this
------------------------------------*/
  if(this != &rhs)
  {
    bool end = false;
    clear();
    LinkedList<T>* p = new LinkedList<T>;
    LinkedList<T>* q = rhs.m_next;
    this -> m_data = rhs.m_data;
    this -> m_next = p;

    while(!end)
    {
      p -> m_data = q -> m_data;

      if (q -> m_next != NULL)
      {
        LinkedList<T>* t = new LinkedList<T>;
        p->m_next = t;
        p = p->m_next;
        q = q->m_next;
      }
      else
        end = true;
    }
  }
  return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
/*---------------------------------------
  1. makes a new LL, so a sentinal is created
  2. new LL and RHS is passed to the = operator
  3. Make *this equal to the new LL
  4. Delete p to get rid of memory leak
---------------------------------------*/
  LinkedList<T>* p = new LinkedList;
  *p = rhs;
  this -> m_data = p -> m_data;
  this -> m_next = p -> m_next;
  delete p;
}

template <typename T>
int LinkedList<T>::size() const
{
/*-------------------------------
  1. makes a counter
  2. sets pointer to this
  3. walk down the LL until the sentinal, while counting
  4. returns the counter
--------------------------------*/
  int counter = 0;
  const LinkedList* p;
  p = this;
  while(p -> m_next != NULL)
  {
    counter++;
    p = p -> m_next;
  }
  return counter;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  //if the LL points to NULL, it is the sentinal, so empty
  return (m_next == NULL);
}

template <typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
/*---------------------
  1. checks to see if the list is empty
  2. if not, returns the first LL (*this).
---------------------*/
  if (isEmpty() == true)
  {
    cout << "!-- ERROR: PANIC IN LINKEDLIST!! .getFirstPtr - empty list"<<endl;
    return NULL;
  }
  else
  {
    return this;
  }
}

template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
/*-----------------------------
  1. checks to see if the LL is empty
  2. if not, walks down the LL until the next
     LL is the sentinal.
  3. Returns the LL before sentinal
----------------------------*/
  if (isEmpty() == true)
  {
    cout << "!-- ERROR: PANIC IN LINKEDLIST!! .getLastPtr - emptylist"<<endl;
    return NULL;
  }
  else
  {
    LinkedList* p = this;
    while(p -> m_next -> m_next != NULL)
    {
      p = p -> m_next;
    }
    return p;
  }
}

template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
/*--------------------------------
  1. checks to see if the list is empty
  2. checks to see if i is even in the LL
  3. walks down the LL until it is at i
  4. return LL at i
---------------------------------*/
  if (isEmpty() == true)
  {
    cout << "!-- ERROR: PANIC IN LINKEDLIST!! .getAtPtr - emptylist" << endl;
    return NULL;
  }
  if (size() < i)
  {
    cout << "!-- ERROR: PANIC IN LINKEDLIST!! .getAtPtr - size too small"<<endl;
    return NULL;
  }
  else
  {
    LinkedList* p = this;
    for(int k = 0; k < i; k++)
    {
      p = p -> m_next;
    }
    return p;
  }
}

template <typename T>
void LinkedList<T>::clear()
{
/*--------------------------------
  1. checks to see if the LL is already empty
  2. if not, two pointers walk down the LL,
     one ahead of the other, the other deleting
     as it goes.
  3. sets the data of *this equal to NULL
---------------------------------*/
  if (this -> m_next != NULL)
  {
    LinkedList<T>* p = this -> m_next;
    LinkedList<T>* t = this -> m_next;

    while(p -> m_next != NULL)
    {
      p = p -> m_next;
      delete t;
      t = p;
    }
    delete t;
    this -> m_next = NULL;
    this -> m_data = NULL;
  }
  return;
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
/*---------------------------------------
  1. Create a new LinkedList
  2. set new LinkedList to equal value of passed
  3. Make past point to tmp and set x value
---------------------------------------  */
  LinkedList* tmp = new LinkedList();
  tmp -> m_data = m_data;
  tmp -> m_next = m_next;
  m_next = tmp;
  m_data = x;
  return;
}

template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
/*-----------------------------------
  1. Makes a brand new LinkedList
  2. Makes the new linked list equal to pos
  3. Makes pos equal to x and points to new LL
----------------------------------*/
  LinkedList* tmp = new LinkedList;
  tmp -> m_data = pos -> m_data;
  tmp -> m_next = pos -> m_next;
  pos -> m_data = x;
  pos -> m_next = tmp;
  return;
}

template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
/*--------------------------------
  1. walks down the LL
  2. skips pos
  3. deletes pos
----------------------------------*/

  LinkedList* p = this;
  while(p -> m_next != pos)
  {
    p = p -> m_next;
  }
  p -> m_next = p -> m_next -> m_next;
  delete pos;
  return;
}

template <typename T>
bool LinkedList<T>::operator == (const LinkedList<T>& rhs) const
{
/*----------------------------------------
  1. checks to see if they are of equal size
  2. checks to see if the data of the two equal
     sized LL are the same
----------------------------------------*/

  int sizeof_lhs = size();
  int sizeof_rhs = rhs.size();
  if (sizeof_lhs != sizeof_rhs)
    return false;
  else
  {
    const LinkedList* p = this;
    const LinkedList* t = &rhs;

    while(p -> m_next != NULL)
    {
      if(p -> m_data != t -> m_data)
        return false;
      p = p -> m_next;
      t = t ->  m_next;
    }
  }
  return true;
}

template <typename T>
LinkedList<T>* LinkedList<T>::find (const T& x)
{
/*-------------------------------------------
  1. pointer that points to this
  2. walks down the LL
  3. if x is found, exit the while,
    if not, goes to the next element
  4. if never found, returns NULL
-------------------------------------------*/

  LinkedList* p = this;
  while(p -> m_next != NULL)
  {
    if(p -> m_data == x)
      return p;
    p = p -> m_next;
  }
  return NULL;
}

template <typename T>
void LinkedList<T>::reverse()
{
/*------------------------------------
  1. Makes a new LL to replace the spot of this
  2. three pointes to run down the LL
  3. makes a new sentinal for the new ending
  4. prev points to the new sentinal
  5. current's next = prev
  6. prev = current
  7. current = next;
  8. next moves up
  9. delete the next and current
  10. makes this equal to prev
  11. deletes prev
-----------------------------------*/
  LinkedList* last = new LinkedList;
  last -> m_next = this -> m_next;
  last -> m_data = this -> m_data;
  LinkedList* prev;
  LinkedList* current = last;
  LinkedList* next = last -> m_next;
  LinkedList* null_p = new LinkedList;
  null_p -> m_next = NULL;
  prev = null_p;

  while(current -> m_next != NULL)
  {
    current -> m_next = prev;
    prev = current;
    current = next;
    next = next -> m_next;
  }
  delete next;
  delete current;
  m_next = prev -> m_next;
  m_data = prev -> m_data;

  delete prev;

  return;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
/*-----------------------------------------
  1. Makes a deep copy of xlist
  2. walks down the LinkedList
  3. deletes the sentinal
  4. makes the last LL of LHS equal to xlist
---------------------------------------*/

  LinkedList<T>* p = this;
  LinkedList<T>* q;
  LinkedList<T>* t = new LinkedList(xlist);
  while(p -> m_next -> m_next != NULL)
  {
    p = p -> m_next;
  }
  q = p -> m_next;
  delete q;
  p -> m_next = t;
}

