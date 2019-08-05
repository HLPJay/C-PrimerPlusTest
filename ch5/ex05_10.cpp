/*******************************
输入：输入一个值，
输出：打印×号

...*
..**
.***
****
*******************************/

#include <iostream>
using namespace std;

int main(void)
{
	cout<<"please enter the num:";
	int num;
	cin>>num;

	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=(num-i);j++)
		{
			cout<<" "<<".";
		}
		for(int k=0;k<i;k++)
		{
			cout<<" "<<"*";
		}
		cout<<endl;
	}

	return 0;
}