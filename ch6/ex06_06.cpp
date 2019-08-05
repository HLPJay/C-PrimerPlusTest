/*******************************
输入：动态分配的结构数组，输入信息、
输出：显示大于10000的不同类别
********************************/

#include <iostream>
#include <string>
using namespace std;

struct DonationStruct {
	string peopleName;
	double donationMoney;
};

int main()
{
	int num;
	cout<<"please input the number of you want entry:";
	cin>>num;
	DonationStruct *donationArray = new(std::nothrow) DonationStruct[num];
	if(donationArray == nullptr)
	{
		return -1;
	}
	for(int i=0;i<num;i++)
	{
		cout<<"please input "<<i <<"people information:"<<endl;
		cin>>donationArray[i].peopleName;
		cin>>donationArray[i].donationMoney;
	}

	for(int i=0;i<num;i++)
	{
		cout<<"name:"<<donationArray[i].peopleName;
		cout<<"\t\tmoney:"<<donationArray[i].donationMoney<<endl;
	}
	//TODO :考虑效率，应该怎么实现？？？
	//显示Grand Patrons

	cout<<"Grand Patrons:"<<endl;
	int number = 0;
	for(int i=0;i<num;i++)
	{
		if((donationArray+i)->donationMoney >10000)
		{
			++number;
			cout<<"Grand Patrons name:"<<(donationArray+i)->peopleName;
			cout<<"\t\tGrand Patrons money:"<<(donationArray+i)->donationMoney<<endl;
		}
	}
	if(number == 0 )
	{
		cout<<"\t \t none"<<endl;
	}
	//显示 Patrons
	cout<<"Patrons:"<<endl;
	number = 0;
	for(int i=0;i<num;i++)
	{
		if((donationArray+i)->donationMoney <10000)
		{
			++number;
			cout<<"Patrons name:"<<(donationArray+i)->peopleName;
			cout<<"\t\t Patrons money:"<<(donationArray+i)->donationMoney<<endl;
		}
	}
	if(number == 0 )
	{
		cout<<"\t \t none"<<endl;
	}

	delete []donationArray;
	donationArray = nullptr;
	return 0;
}