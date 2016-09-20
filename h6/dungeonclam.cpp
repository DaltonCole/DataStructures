//Dalton Cole
//Section and Class: A, cs153
//Date: 5/4/2014
//Description: 

#include <iostream>
using namespace std;

//Pre: none
//Post: returns where Z is by changing cc and cr
//Purpose: Finds Z in the two dimentional char array
void find(char ** maze, int cs, int rs, int& cc, int& cr);
//Pre: none
//Post: recursively returns true if a path exists and false if the path didn't work
//Purpose: recursivly finds a path from Z to E going through only ' ' and changing them to '.'
bool path(char ** maze, int cs, int rs, int& cc, int& cr);
//Pre: none
//Post: returns true if next movment is inside array and a ' ' or 'E'
//Purpose: tells path rather or not the movment is valid
bool valid(char ** maze, int cs, int rs, int& cc, int& cr, char& direction);

int main()
{
	int cs, rs; //coluom size and row size
	int cc = 0, cr = 0; //current column and current row
    int count = -1; //count the number of mazes
    char dummy; // dummy for new line character
	char** maze; //double pointer for memeory

	do
	{
		count++; // start at the zeroth maze


		//read in size of maze
		cin >> cs >> rs;
		cin.ignore();
        
        if(cs !=0 && rs != 0)
        {
		 	//allocate maze array
		  	maze = new char*[rs];
		  	for(int i = 0; i < rs; i++)
		  	{
		  		maze[i] = new char[cs];
		  	}

			//read maze array character by character
			for(int i = 0; i < rs; i++)
			{
				for(int k = 0; k < cs; k++)
				{
					cin.get(maze[i][k]);
				}
				cin.get(dummy);
			}
            
			//finds Z
			find(maze, cs, rs, cc, cr);

			//find a maze path
			path(maze, cs, rs, cc, cr);

			//print maze
			cout << endl << "Map : " << count << endl;
			for(int i = 0; i < rs; i++)
			{
				for(int k = 0; k < cs; k++)
				{ 
					cout << maze[i][k];
				}
				cout << endl;
			}

			//deallocate maze array
			for(int i = 0; i < rs; i++)
			{
				delete [] maze[i];
			}
		delete [] maze; //free up the massive maze memory
        }
	}while(cs != 0 && rs != 0); //do loop while maze isn't size 0,0

	return 0;
}

void find(char ** maze, int cs, int rs, int& cc, int& cr)
{
    for(cr = 0; cr < rs; cr++)
    {
    	for(cc = 0; cc < cs; cc++)
    	{
    		if(maze[cr][cc] == 'Z')
    			return;
    	}
    }
    return;
}

bool path(char ** maze, int cs, int rs, int& cc, int& cr)
{
	bool worked; //domino effect if exist is found
	char direction = 'n'; //starting direction is north
    if(valid(maze,cs,rs,cc,cr,direction))
    {
    	cr--;
    	if(direction == 'E') //if direction (changed from valid) is E, then you have found the exit!
    		return true;
    	maze[cr][cc] = '.'; //put bread crum on your path
    	worked = path(maze,cs,rs,cc,cr); //RECURSION PART
    	if(worked == false) //if path didn't work, undo the change
    	{
    		maze[cr][cc] = ' ';
    		cr++;
    	}
    	else //if path worked, return true
    	{
    		return worked;
    	}
    }
    direction = 'e'; //next is east
    if(valid(maze,cs,rs,cc,cr,direction))
    {
    	cc++;
    	if(direction == 'E') 
    		return true;
    	maze[cr][cc] = '.';
    	worked = path(maze,cs,rs,cc,cr);
    	if(worked == false)
    	{
    		maze[cr][cc] = ' ';
    		cc--;
    	}
    	else
    	{
    		return worked;
    	}
    }
    direction = 's'; //then south
    if(valid(maze,cs,rs,cc,cr,direction))
    {
    	cr++;
    	if(direction == 'E') 
    		return true;
    	maze[cr][cc] = '.';
    	worked = path(maze,cs,rs,cc,cr);
    	if(worked == false)
    	{
    		maze[cr][cc] = ' ';
    		cr--;
    	}
    	else
    	{
    		return worked;
    	}
    }
    direction = 'w'; //finally west
    if(valid(maze,cs,rs,cc,cr,direction))
    {
    	cc--;
    	if(direction == 'E') 
    		return true;
    	maze[cr][cc] = '.';
    	worked = path(maze,cs,rs,cc,cr);
    	if(worked == false)
    	{
    		maze[cr][cc] = ' ';
    		cc++;
    	}
    	else
    	{
    		return worked;
    	}
    }
    return false; //no path exists
}

bool valid(char ** maze, int cs, int rs, int& cc, int& cr, char& direction)
{
	if(direction == 'n') //for north
	{
		if((cr - 1) == -1) //if out of bounds, invalid
			return false;
		direction = maze[cr-1][cc]; //changes char direction to what is next
		if((direction == ' ') || (direction == 'E')) //' ' and 'E' are valid directions, so true
			return true;
		else //if anything else, invalid
			return false;
	}
	else if(direction == 'e') //for east
	{
		if((cc + 1) == cs)
			return false;
		direction = maze[cr][cc+1];
		if((direction == ' ') || (direction == 'E'))
			return true;
		else
			return false;
	}
	else if(direction == 's') //for south
	{
		if((cr + 1) == rs)
			return false;
		direction = maze[cr+1][cc];
		if((direction == ' ') || (direction == 'E'))
			return true;
		else
			return false;
	}
	else if(direction == 'w') //for west
	{
		if((cc - 1) == -1)
			return false;
		direction = maze[cr][cc-1];
		if((direction == ' ') || (direction == 'E'))
			return true;
		else
			return false;
	}
	return false;
}

