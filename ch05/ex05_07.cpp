/******************************************
输入 :生产商，生产年份
	用new的方式输入指定个数的信息录入
输出 ：输出录入的信息
*******************************************/

#include <iostream>
#include <string>
using namespace std;

struct Car
{
	string makes;
	int makeyears;
};

int main(void)
{
	int carNumber;
	cout<<"Please input hwo many cars catalog:";
	cin>>carNumber;

	Car *carInforamtion = new(std::nothrow) Car[carNumber];

	for(int i=1;i<=carNumber;i++)
	{
		cout<<"car #"<<i<<endl;
		cout<<"please enter the make:";
		cin>>carInforamtion[i-1].makes;
		cout<<"please enter the year made:";
		cin>>carInforamtion[i-1].makeyears;
	}
	cout<<"here is your collection:"<<endl;
	for(int i=0;i<carNumber;i++)
	{
		cout<<carInforamtion[i].makeyears<<"   "<<carInforamtion[i].makes<<endl;
	}

	delete []carInforamtion;
	carInforamtion = nullptr;
	return 0;
}

