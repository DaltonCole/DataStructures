#include <iostream>
#include "arraylist.h"

using namespace std;

int main()
{
  ArrayList<int> test;
  ArrayList<int> test2;
  int x = 22;
  int y = 23;
  cout << "Begin" << endl;
  
  test.insert_back(1);
  test.insert_back(2);
  test.insert_back(3);
  test.insert_back(4);
  test.insert_back(5);
  test.insert_back(6);
  test.insert_back(7);
  test.insert_back(8);
  test.insert_back(9);
  test.insert_back(10);
  test.insert_back(11);



  cout << test << endl;
  
  test2 = test;
  cout << test2 << endl;

  x = test2.find(3);
  cout << x << endl;;

  test2.swap(x+1, x+2);
  cout << test2 << endl;

  y = test2.first();
  cout << y << endl;
  test2.remove(0);
//  test2.insert(y, 2);
  cout << test2 << endl;
/*
  cout << endl << "Append:" << endl;
  test2.append(test);
  cout << test2 << endl;
*/
  cout << "end" << endl;

  return 0;
}
