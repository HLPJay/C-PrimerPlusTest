#include "ex09_01golf.h"

#include <cstring>
#include <iostream>
using namespace std;

//non-interactive version:
//function sets golf structure to provided name,handicap
//using values passed as arguments to the function
void setgolf(golf &g, const char* name, int hc)
{
	//TODO:求char*的长度
	strcpy(g.fullname, name);
	g.handicap = hc;
}

//interactive version:
//function solicits name and handicap from user
//and sets the numbers of g to the values entered
//return 1 if name is entered, 0 if name is empty string
int setgolf(golf &g)
{
	if(strlen(g.fullname) ==0)
	{
		return 0;
	}

	return 1;
}

//function resets handicap to new value
void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

//function displays contents of golf structure
void showgolf(const golf& g)
{
	cout<<"golf fullname: "<< g.fullname<<endl;
	cout<<"golf handicap: "<< g.handicap<<endl;
}