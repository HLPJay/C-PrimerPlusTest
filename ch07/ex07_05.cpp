/***************************
接受一个整形参数，并返回该参数的竭诚。
定义一个递归
***************************/

#include <iostream>
using namespace std;

long GetResultByRecursive(int num);
int main(void)
{
	cout<<"please input the num! you want to get:";
 	int num;
	cin>>num;
	cout<<"num! = "<<GetResultByRecursive(num)<<endl;
	return 0;
}

long GetResultByRecursive(int num)
{
	if(num == 0)
	{
		return 0;
	}
	if(num == 1)
	{
		return 1;
	}
	while(num>1)
	{
		return num*GetResultByRecursive(num-1);
	}
}