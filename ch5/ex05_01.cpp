/************************************
输入：两个整数
输出：两个数之间的所有数字之和
************************************/

#include <iostream>
using namespace std;
int main(void)
{
	int min,max;
	cout<<"please input two num:";
	cin>>min;
	cin>>max;
	if(min>max)
	{
		min = min + max;
		max = min - max;
		min = min - max;
	}

	int sum = 0;
	for(int i= min; i<=max; i++)
	{
		sum += i;
	}
	cout<<min<<" to "<<max <<" num is:"<<sum<<endl;
	return 0;
}