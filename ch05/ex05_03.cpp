/***********************************************
输入：用户持续输入数据，直到输入0为止，输出所有的累加和。
************************************************/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	int sum = 0;
	do{
		cout<<"Please input:";
		cin>>num;
		sum+=num;
		cout<<"sum: "<<sum<<endl;
	}while(num!=0);

	return 0;
}