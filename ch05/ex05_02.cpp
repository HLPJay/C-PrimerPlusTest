/**********************************
输入：array对象，long double
***********************************/

#include <iostream>
#include <array>
using namespace std;

const int ArSize = 100;
int main(void)
{
	array<long double,ArSize> myArray;
	myArray[0] = 0;
	myArray[1] = 1;
	for(int i =2; i<ArSize; i++)
	{
		myArray[i] = i * myArray[i-1];
	}

	for(int i =0; i<ArSize; i++)
	{
		cout<<i<<"! = "<<myArray[i]<<endl;
	}
	cout<<"100! = " <<100*myArray[ArSize-1]<<endl;
	return 0;
}