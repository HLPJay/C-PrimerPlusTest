/******************************************
输入 :100 每年都是100的10%
     100 复利是5%
*******************************************/

#include <iostream>

int main(void)
{
	using namespace std;
	const float interestRateOne = 0.10;
	const float interestRateTwo = 0.05;

	int money = 100;
	int moneyOne = 0;
	int moneyTwo = 100;
	for(int i=1;;i++)
	{
		moneyOne = money+(money*interestRateOne)*i;
		moneyTwo = moneyTwo+(moneyTwo*interestRateTwo);
		if(moneyTwo>=moneyOne)
		{
			cout<<i<<" years "<<"moneyOne:"<<moneyOne<<" moneyTwo: "<<moneyTwo<<endl;
			break;
		}
	}
	return 0;
}