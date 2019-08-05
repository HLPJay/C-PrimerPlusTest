/*****************************
修改程序清单7.4,求中奖几率
*****************************/

#include <iostream>
using namespace std;

//求中最大头奖的概率

long double GetProbability(unsigned int total, unsigned int choices);
int main(void)
{
	cout<<"please input First rule, total and choices:";
	long double probability;
	unsigned int total, choices;
	cin>>total>>choices;
	probability = GetProbability(total, choices);
	cout<<"please input Second rule, total and choices:";
	cin>>total>>choices;
	probability *= GetProbability(total, choices);
	cout<<"probability R is:"<<probability<<endl;
	cout<<"probability 1/R is:"<<1/probability<<endl;
	return 0;
}

long double GetProbability(unsigned int total, unsigned int choices)
{
	long double result = 1.0;
	long double n;
	int p;
	for(n = total, p =choices;p>0;n--,p--)
	{
		result = result*(n/p);
	}
	return result;
}