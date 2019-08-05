/*************************************************
1:const char*数组存储表示季度名称的字符串，double数组存储开支
2：const char*数组存储表示季度名称的字符串 结构只有一个存储开支的double数组

*************************************************/
#include <iostream>
using namespace std;

const int Seasons = 4;
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};
void fill(double *pa, int size);
void show(double ba[],int size);


struct result
{
	double expenditure[Seasons];
};
void fillStruct(result *resultOne);
void showStruct(result *resultOne);
int main(void)
{
	double expenditure[Seasons];
	fill(expenditure,Seasons);
	show(expenditure, Seasons);

	result resultOne;
	fillStruct(&resultOne);
	showStruct(&resultOne);
	return 0;
}

void fill(double *pa, int size)
{
	for(int i = 0;i<size;i++)
	{
		cout<<"Enter the #"<<i<<" :";
		cin>>*(pa+i);
	}
	return;
}

void show(double ba[],int size)
{
	double total = 0;
	cout<<"\t EXPENSES: \t"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<Snames[i]<<" : $"<<ba[i]<<endl;
		total+=ba[i];
	}
	cout<<"Total Expenses:$"<<total<<endl;
}

void fillStruct(result *resultOne)
{
	for(int i = 0;i<Seasons;i++)
	{
		cout<<"Enter the #"<<i<<" :";
		cin>>resultOne->expenditure[i];
	}
	return;
}

void showStruct(result *resultOne)
{
	double total = 0;
	for(int i = 0;i<Seasons;i++)
	{
		cout<<Snames[i]<<" : $"<<resultOne->expenditure[i]<<endl;
		total+=resultOne->expenditure[i];
	}
	cout<<"Total Expenses:$"<<total<<endl;
	return;
}