/******************************************
输入 :二维数组来存储 3年每个月的销售
输出 ：每年的销售量以及三年的总销售量
*******************************************/

#include <iostream>
using namespace std;

const int yearsNum = 3;
const int monthNum = 12;
int main(void)
{
	cout<<"Please three years of every month Sales volume:"<<endl;
	int saleNumber[yearsNum][monthNum];
	for(int i=0;i<yearsNum;i++)
	{
		cout<<"please enter "<< i <<" years alses:"<<endl;
		for(int j=0; j<monthNum; j++)
		{
			cout<<"month "<< j <<" sales is:";
			cin>>saleNumber[i][j];
		}
	}

	int sumOne[yearsNum] = {0};
	int sumAll = 0;
	for(int i=0;i<yearsNum;i++)
	{
		for(int j=0; j<monthNum; j++)
		{
			sumOne[i]= sumOne[i]+saleNumber[i][j];
		}
		cout<<"the "<< i <<" years sales is:"<<sumOne[i]<<endl;
		sumAll+=sumOne[i];
	}
	cout<<"SumAll:"<<sumAll<<endl;
	return 0;
}