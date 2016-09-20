//main

#include "gmatrix.h"
using namespace std;

int main()
{
 GMatrix test(6,4,5,2);

 cout << test;
 
 GMatrix josh(test);// = test;
 
 cout << josh;
 
// josh = test;
 
// cout << endl << endl << josh;

  return 0;
}
