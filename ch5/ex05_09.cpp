#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string word;
	cout<<"please input world, stop with done:"<< endl;
	cin>>word;

	int num = 0;
	while(word != "done")
	{
		num++;
		cin>>word;
	}

	cout << "you have enter a total of "<< num<<" word."<<endl;
	return 0;
}