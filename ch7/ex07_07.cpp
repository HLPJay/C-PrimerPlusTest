/***************************************
修改7.7中的函数，改为指针传递的方式，然后fill_array返回end指针
***************************************/


#include <iostream>
using namespace std;

const int Max = 5;
double* fill_array(double *begin, int limit);
void show_array(double *begin, double *end);
void revalue(double *begin, double *end, double value);
int main(void)
{

	double properties[Max];
	double *end;

	end = fill_array(properties, Max);
	show_array(properties, end);
	if(end-properties>0)
	{
		cout<<"enter revaluation factor:";
		double factor;
		while(!(cin>>factor))
		{
			cin.clear();
			while(cin.get()!='\n')
			{
				continue;
			}
			cout<<"Bad Input."<<endl;
		}
		revalue(properties, end, factor);
		show_array(properties, end);
	}
	cout<<"Done \n";
	cin.get();
	cin.get(); //输入回车终止
	return 0;
}

//定义一个函数，负责输入数组的值，然后返回最后一个数组指向位置。

double* fill_array(double *begin, int limit)
{
	double temp;
	int num = 0;
	for(int i=0;i<limit;i++)
	{
		cout<<"Enter value #"<<(i+1)<<": ";
		cin>>temp;
		if(!cin)
		{
			cin.clear();
			while(cin.get() !='\n')
			{
				continue;
			}
			cout<<"Bad input."<<endl;
			break;
		}
		else if(temp<0)
		{
			break;
		}
		*(begin+i) = temp;
		num++;
	}
	return begin+num;
}

void show_array(double *begin, double *end)
{
	int num = 0;
	for(double *pt = begin; pt != end; pt++)
	{
		cout<<"Preperty #"<<num<<" :";
		cout<<*pt<<endl;
		num++;
	}
}


void revalue(double *begin, double *end, double value)
{
	for(double *pt = begin; pt != end; pt++)
	{
		*pt = value;
	}
}