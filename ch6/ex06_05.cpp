/**********************************
输入：用户收入
输出：所得税
5000 不收税
5001~15000  10%
15001~35000 15%
35000以上    20%
循环输入，输入为负数或者非数字终止
***********************************/

#include <iostream>
using namespace std;

int main(void)
{
	//定义一个string类型，然后输入，如果都是数字，则计算，如果负数则终止，如果非数字也终止
	int money;
	int incomeTax;
	cout<<"Please enter the money:";
	cin>>money;
	while(money>0)
	{
		if(money<=5000)
		{
			incomeTax = 0;
		}else if(money <= 15000)
		{
			incomeTax = (money-5000)*0.10;
		}else if(money <= 35000)
		{
			incomeTax = 10000*0.10+(money-15000)*0.15;
		}else 
		{
			incomeTax = 10000*0.10+20000*0.15+(money - 35000)*0.20;
		}
		cout<<"incomeTax:"<<incomeTax<<endl;
		cout<<"Please enter the money:";
		cin>>money;
	}
	
	return 0;
}