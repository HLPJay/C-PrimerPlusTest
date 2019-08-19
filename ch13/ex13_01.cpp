#include <iostream>
#include "ex13_01_cd.h"

using namespace std;

void Bravo(const Cd &disk);

int main(void)
{
	Cd cd1("Beatles", "Capitol", 14, 35.5);
	classic c2 = classic("Piano Sonata in B flat, Dantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);

	Cd *pcd = &cd1;
	cout<<"Using Object directly: \n";
	cd1.Report();
	c2.Report();

	cout<<"Using type cd * pointer to object: \n";
	pcd ->Report();
	pcd = &c2;
	pcd ->Report();

	cout<<"Calling a function with a Cd refence argument: \n";
	Bravo(cd1);
	Bravo(c2);

	cout<<"Testing assignment: \n";
	classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk)
{
	disk.Report();
}