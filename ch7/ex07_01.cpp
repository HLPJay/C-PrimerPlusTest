/**********************************************
输入：两个数，直到一个数为0
定义一个函数，输入两个数，求调和平均数，返回给main函数

**********************************************/


#include <iostream>
using namespace std;

double GetAvgNum(int x, int y);
int main(void)
{
	cout<<"please enter x and y:";
	int x,y;
	double avgNum = 0.0;
	cin>>x;
	cin>>y;

	while(x!=0&&y!=0)
	{
		avgNum = GetAvgNum(x,y);
		cout<<"Harmonic average is:"<<avgNum<<endl;
		cout<<"please enter x and y:";
		cin>>x>>y;
	}
	cout<<"end!"<<endl;
	return 0;
}

double GetAvgNum(int x, int y)
{
	double avgNum = 0.0;
	if(x+y == 0 )
	{
		return 0;
	}
	avgNum = 2.0*x*y/(x+y);
	return avgNum;
}