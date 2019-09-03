/**********************************
填充数组，显示数组，反转数组，显示数组。
***********************************/

#include <iostream>
using namespace std;

const int size = 20; 
int Fill_array(double doubArray[], int size);
void Show_array(double doubArray[], int size);
void Reverse_array(double doubArray[], int size);

int main(void)
{
	double doubArray[20] = {0.0};
	cout<<"please enter the num you want input:";
	int count,realcount;
	cin>>count;
	if(count>0&&count<20)
	{
		realcount = Fill_array(doubArray, count);
	}
	cout<<"realcount:"<<realcount<<endl;
	Show_array(doubArray, realcount);
	Reverse_array(doubArray, realcount);
	Show_array(doubArray, realcount);
	return 0;
}

int Fill_array(double doubArray[], int size)//实际上传递的是数组的地址
{
	int num = 0;
	double elem;
	cout<<"please input "<<size<<" num:";
	for(int i=0;i<size;i++)
	{
		if(cin>>elem)
		{
			doubArray[i] = elem;
			num++;
		}
		else
		{
			break;
		}
	}
	return num;
}

void Show_array(double doubArray[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<"number of "<<i<<" is:"<<doubArray[i]<<endl;
	}
	return ;
}

void Reverse_array(double doubArray[], int size)//TODO 这里注意size为实际大小
{
	double elem;
	for(int i = 1; i<=((size-1)/2); i++)
	{
		elem = doubArray[i];
		doubArray[i] = doubArray[size - i-1];
		doubArray[size - i -1] = elem;
	}
	return ;
}