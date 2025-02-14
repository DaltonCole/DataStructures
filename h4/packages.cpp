//Dalton Cole
//Class and section: CS153, A 
//Date: 3/26/14
//Description: main file for abstract package

#include<iostream>
#include<iomanip>
using namespace std;

#include "two_d.h"
#include "three_d.h"
#include "four_d.h"

int main()
{
  //sets decimals to only 2 decimal places
  cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  cout.precision(2);
  
  int num_packages; //number of packages
  int dimentions; //number of dimentions of package
  string from; //who the package is from
  string to; //who the package is to
  float length; //the length of the package
  float width;  //the width of the package
  float height; //the height of the package
  float forthd; //the forth demention of the package
  float weight; //the weight of the package
  float total_profit = 0; //total profit of all packages

  cout << "How many packages do you have?" << endl;
  cin >> num_packages;

  AbstractPackage** packages = new AbstractPackage* [num_packages];

  for(int i = 0; i < num_packages; i++)
  {
    cout << "How many dimentions is your " << i << " number package?" << endl;
    cin >> dimentions;

    if(dimentions == 2)
    {
      cout << "Who is this 2D package from?" << endl;
      cin >> from;
      cout << "Who is this 2D package to?" << endl;
      cin >> to;
      cout << "What is the package's width?" << endl;
      cin >> width;
      cout << "What is the package's length?" << endl;
      cin >> length;
      packages[i] = new two_d(from, to, width, length);
    }
    else if (dimentions == 3)
    {  
      cout << "Who is this 3D package from?" << endl;
      cin >> from;
      cout << "Who is this 3D package to?" << endl;
      cin >> to;
      cout << "What is the package's width?" << endl;
      cin >> width;
      cout << "What is the package's length?" << endl;
      cin >> length;
      cout << "What is the package's height?" << endl;
      cin >> height;
      cout << "What is the package's weight?" << endl;
      cin >> weight;
      packages[i] = new three_d(from, to, length, width, height, weight);
    }
    else if (dimentions == 4)
    {
      cout << "Who is this 4D package from?" << endl;
      cin >> from;
      cout << "Who is this 4D package to?" << endl;
      cin >> to;
      cout << "What is the package's width?" << endl;
      cin >> width;
      cout << "what is the package's length?" << endl;
      cin >> length;
      cout << "What is the package's height?" << endl;
      cin >> height;
      cout << "What is the package's...other demention?" << endl;
      cin >> forthd;
      cout << "What is the package's weight?" << endl;
      cin >> weight;
      packages[i] = new four_d(from, to, width, length, height, forthd, weight);
    }
    else
    {
    	cout << "Dimentions may only be 2-4, please enter a valid dimention." << endl;
    	i--;
    }

  }
  for(int i = 0; i < num_packages; i++)
  {
    cout << "#" << i << ": From " << packages[i] -> getFrom() << " to " << packages[i] -> getTo() << endl;
    cout << "$" << packages[i] -> getCharge() << endl;
  }
  for(int i = 0; i < num_packages; i++)
  {
    total_profit += packages[i] -> getCharge();
  }
  cout << "TOTAL PROFIT = $" << total_profit << endl;
  cout << "AVERAGE = $" << (total_profit/num_packages) << endl;


  for(int i = 0; i < num_packages; i++)
  {
    delete packages[i];
  }
  delete[] packages;

  return 0;
}
