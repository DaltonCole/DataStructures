//Dalton Cole
//Class and section: cs153, A
//Date: 5/6/2014
//Description: myMyBSTree.cpp for myMyBSTree.h

#include <iostream>
#include <string>
using namespace std;

template < typename T >
const MyBSTree<T>& MyBSTree<T>::operator = (const MyBSTree<T>& rhs)
{
	if(this != &rhs)
	{
		if(this -> m_root != NULL)
		{
			clear();
			delete m_root;
		}
		TreeNode<T>* t;
		TreeNode<T>* p = rhs.m_root;
		t = clone(p);
		this -> m_size = rhs.m_size;
		this -> m_root = t;
	}
	return *this;
}

template < typename T>
TreeNode<T>* MyBSTree<T>::clone(TreeNode<T>* t)
{
	if(t == NULL)
		return NULL;
	else
	{
		return new TreeNode<T>(t -> m_data, clone(t -> m_left), clone(t -> m_right));
	}
}

template < typename T >
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)
{
	//MyBSTree<T>* p = new MyBSTree;
	//*p = rhs;
	//this -> m_size = rhs.m_size;
	//this -> m_root = p -> m_root;
	//delete p;
	//*this = rhs;
	TreeNode<T>* t;
	TreeNode<T>* p = rhs.m_root;
	t = clone(p);
	this -> m_size = rhs.m_size;
	this -> m_root = t;

}

template < typename T >
int MyBSTree<T>::size() const
{
	return m_size;
}

template < typename T >
bool MyBSTree<T>::isEmpty() const
{
	return ((m_root == NULL)?true:false);
}

template < typename T >
int MyBSTree<T>::height() const
{
	if(isEmpty() == true)
		return 0;
	TreeNode<T>* tmp = m_root;
	int max_height;
	max_height = r_height(tmp, 0, 0);
	return max_height;

}

template < typename T >
int MyBSTree<T>::r_height(TreeNode<T>* tmp, int max_height, int height) const
{
	height++;
	if(tmp -> m_left != NULL) //if it can terverse left
	{
		if(height > max_height)
			max_height = height;
		max_height = r_height(tmp -> m_left, max_height, height);

	}
	if(tmp -> m_right != NULL) //if it cannot terverse right
	{
		if(height > max_height)
			max_height = height;
		max_height = r_height(tmp -> m_right, max_height, height);

	}
	if((tmp -> m_left == NULL && tmp -> m_right == NULL)) //if it is a leaf
	{
		if(height > max_height)
			max_height = height;
	}
	return max_height;
}

template < typename T >
const T& MyBSTree<T>::findMax() const
{
	string err = "PANIC : Tree is Empty!!";
	TreeNode<T>* p = m_root;
	try
	{
		if(p == NULL) throw err;
	}
	catch(string s)
	{
		throw s;
	}
	while(p -> m_right != NULL)
	  	p = p -> m_right;
	return p -> m_data;
}

template < typename T >
const T& MyBSTree<T>::findMin() const
{
	string err = "PANIC : Tree is Empty!!";
	TreeNode<T>* p = m_root; //Might have to make this a new TreeNode to return it
	try
	{
		if(p == NULL) throw err;
	}
	catch(string s)
	{
		throw s;
	}
	while(p -> m_left != NULL)
		p = p -> m_left;
	return p -> m_data;
}

template < typename T >
int MyBSTree<T>::contains(const T& x) const
{
	int level = 0;
	TreeNode<T>* p = m_root;
	while((p -> m_data != x) && ((p -> m_right != NULL) || (p -> m_left != NULL)))
	{
		if(p->m_data == x)
			return level;
		else if (x < p->m_data)
		{
			level++;
			p = p -> m_left;
		}
		else if (x > p->m_data)
		{
			level++;
			p = p -> m_right;
		}
		else
		{
			break;
		}
	}
	return (-(level++));
}

template < typename T >
void MyBSTree<T>::clear()
{
	TreeNode<T>* t = m_root;
	if(t == NULL)
		return;
	r_clear(t);
	m_size = 0;
	m_root = NULL;
	return;
}

template < typename T >
void MyBSTree<T>::r_clear(TreeNode<T>* t)
{
	if(t -> m_left != NULL)
		r_clear(t -> m_left);
	if(t -> m_right != NULL)
		r_clear(t -> m_right);
	delete t;
	return;
}

template < typename T >
void MyBSTree<T>::insert(const T& x)
{
	if(m_root == NULL)
	{
		TreeNode<T>* t = new TreeNode<T>;
		t -> m_data = x;
		m_root = t;
		m_size++;
		return;
	}
	TreeNode<T>* tmp = m_root;
	r_insert(tmp, x);
	return;
}

template < typename T >
void MyBSTree<T>::r_insert(TreeNode<T>* tmp, const T& x)
{
	if(tmp -> m_left == NULL && x < tmp -> m_data)
	{
		m_size++;
		TreeNode<T>* t = new TreeNode<T>;
		t -> m_data = x;
		tmp -> m_left = t;
		return;
	}
	else if(tmp -> m_right == NULL && x > tmp -> m_data)
	{
		m_size++;
		TreeNode<T>* t = new TreeNode<T>;
		t -> m_data = x;
		tmp -> m_right = t;
		return;
	}
	else if(x < tmp -> m_data)
	{
		r_insert(tmp -> m_left, x);
		return;
	}
	else if(x > tmp -> m_data)
	{
		r_insert(tmp -> m_right, x);
		return;
	}
	else if(x == (tmp -> m_data))
	{
		return;
	}


}

template < typename T >
void MyBSTree<T>::remove(const T& x)
{
	TreeNode<T>* t = m_root;
	r_remove(t, x);
	return;
}

template < typename T >
int MyBSTree<T>::r_remove(TreeNode<T>* t, const T& x)
{
	int same = 0;
	if(t == NULL)
		return 0;
	else if(x < t -> m_data)
	{
		same = r_remove(t -> m_left, x);
		same++;
	}
	else if (x > t -> m_data)
	{
		same = r_remove(t -> m_right, x);
		same -= 2;
	}
	else // x== t -> m_data
	{
		if((t -> m_left != NULL) && (t -> m_right != NULL)) //Can break if the min has a right child
		{
			/*TreeNode<T>* q = t;
			while(q -> m_left -> m_left != NULL)
				q = q -> m_left;
			t -> m_data = q -> m_left -> m_data;
			TreeNode<T>* r = q -> m_left;
			if(r -> m_right != NULL)
			{
				q -> m_left = r -> m_right;
			}
			else
				q -> m_left = NULL;
			delete r;*//*
			TreeNode<T>* p = t -> m_left;
			while(p -> m_right != NULL)
				p = p -> m_right;
			t -> m_data = p -> m_data;
			r_remove(t -> m_left, t -> m_data);*/
			TreeNode<T>* q = t;
			if(q -> m_left -> m_right != NULL)
			{
				q = q -> m_left;
				while(q -> m_right -> m_right != NULL)
					q = q -> m_right;
			}
			t -> m_data = q -> m_right -> m_data;
			TreeNode<T>* r = q -> m_right;
			if(r -> m_left != NULL)
			{
				q -> m_right = r -> m_left;
			}
			else
				q -> m_right = NULL;
			delete r;

		}
		else if((t -> m_left == NULL) && (t -> m_right == NULL))
		{
			delete t;
			return 1;
		}
		else 
		{
			TreeNode<T>* p = t -> m_left; //if left is the only child
			if(t -> m_right != NULL) //if right is the only child
				p = t -> m_right;
			t -> m_data = p -> m_data;
			t -> m_left = p -> m_left;
			t -> m_right = p -> m_right;
			delete p;
		}
	}
	if(same == 2)
	{
		t -> m_left = NULL;
	}
	if(same == -1)
	{
		t -> m_right = NULL;
	}
	return 0;
}

template < typename T >
void MyBSTree<T>::printPreOrder() const
{
	TreeNode<T>* t = m_root;
	r_printPreOrder(t);
	return;
}

template < typename T >
void MyBSTree<T>::r_printPreOrder(TreeNode<T>* t) const
{
	cout << t -> m_data << endl;
	if(t -> m_left != NULL)
	{
		r_printPreOrder(t -> m_left);
	}
	if(t -> m_right != NULL)
	{
		r_printPreOrder(t -> m_right);
	}
	return;
}

template < typename T >
void MyBSTree<T>::printPostOrder() const
{
	TreeNode<T>* t = m_root;
	r_printPostOrder(t);
	return;
}

template < typename T >
void MyBSTree<T>::r_printPostOrder(TreeNode<T>* t) const
{
	if(t -> m_left != NULL)
	{
		r_printPostOrder(t -> m_left);
	}
	if(t -> m_right != NULL)
	{
		r_printPostOrder(t -> m_right);
	}
	cout << t -> m_data << endl;
	return;
}

template < typename T >
void MyBSTree<T>::print() const
{
	TreeNode<T>* t = m_root;
	prettyPrint(t, 0);
	return;
}

template < typename T >
void MyBSTree<T>::prettyPrint (const TreeNode<T>* t, int pad) const
{
  string s(pad, ' ');
  if (t == NULL)
      cout << endl;
  else{
    prettyPrint(t->m_right, pad+4);
    cout << s << t->m_data << endl;
    prettyPrint(t->m_left, pad+4);
  }  
  return;
}