//Programer: Dalton Cole
//Date: April 13, 2014
//Class and section: CS153, A
//Description: braincalc.cpp file

#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.h"
using namespace std;

int main()
{
  string num; //the user input for the calculator
  char first; //what is currently the first input
  Stack<int> calc; //stack of what is to be calculated
  int num1, num2; //what is popped off the stack and is used for calculations
  int input; //the value of the taken integer from the string
  calc.push(0); //in order to make the rest of the program to work correctly
      
  //exit the loop once the user inputs #
  while(first != '#')
  {
    while((first != '$')&&(first != '#'))
    {
      try
      { 
        cin >> num; //reads in the cacluations the user wants done
        first = num[0]; //checks to see what the first charcter is
         if (first == '+')
         {
           num1 = calc.top();
           calc.pop();
           num2 = calc.top();
           calc.pop();
           num2 += num1;
           calc.push(num2);
           num = num.substr(1); //deletes the + character in num string
         }
         else if (first == '-')
         {
           num1 = calc.top();
           calc.pop();
           num2 = calc.top();
           calc.pop();
           num2 -= num1;
           calc.push(num2);
           num = num.substr(1); //deletes the - character in num string
         }
         else if (first == '*')
         {
           num1 = calc.top();
           calc.pop();
           num2 = calc.top();
           calc.pop();
           num2 *= num1;
           calc.push(num2);
           num = num.substr(1); //deletes the * character in num string
         }
         else if (first == '/')
         {
           num1 = calc.top();
           calc.pop();
           num2 = calc.top();
           calc.pop();
           num2 /= num1;
           calc.push(num2);
           num = num.substr(1); //deletes the / character in num string
         }
         else if (first == '%')
         {
           num1 = calc.top();
           calc.pop();
           num2 = calc.top();
           calc.pop();
           num2 %= num1;
           calc.push(num2);
           num = num.substr(1); //delets the % character in num string
         }
         else if (first == '!')
         {
           num1 = calc.top();
           calc.pop();
           num1 *= (-1);
           calc.push(num1);
           num = num.substr(1); //deletes the ! character in num string
         }
         else if ((first == '$')||(first == '#'))
         {
		    if (first == '$')
              cout << calc << endl; //if done with cacluation, outputs the stack
         }
         else
         {
          input = atoi(num.c_str()); //grabs the integer in the frount of the string
           calc.push(input); //puts integer onto the stack
         }
      }
      catch (Oops boo_boo)
      {
        cout << boo_boo.m_errormsg << endl; //if top is empty
      }
    }
    calc.clear(); //clears the stack for next cacluation
    if (first != '#')
      first = 0; //so the second while will loop again
  }
  return 0;
}
