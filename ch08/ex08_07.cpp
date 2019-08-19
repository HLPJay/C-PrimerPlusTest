/********************************

SumArray() 返回数组元素的和 
********************************/

#include <iostream>
using namespace std;

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T *arr[], int n);//TODO ！！！传递的是数组指针

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T *arr[], int n);

struct debts
{
	char names[50];
	double amount;
};

int main()
{
	int things[6] = {13,31,103,301,310,130};
	struct debts mr_E[3] = {
		{"Ima Wolfe",2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby stout", 1800.0}
	};
	double * pd[3];
	for(int i=0;i<3;i++)
	{
		pd[i] = &mr_E[i].amount;//传递的是地址
	}

	ShowArray(things, 6);
	ShowArray(pd, 3);
	cout<<"sum of things:"<<SumArray(things, 6)<<endl;
	cout<<"sum of pd:"<<SumArray(pd, 3)<<endl;
	return 0;
}
template <typename T>
void ShowArray(T arr[], int n)
{
	cout<<"template A:";
	for(int i=0;i<n;i++)
	{
		cout << arr[i]<<"\t";
	}
	cout<<endl;
}

template <typename T>
void ShowArray(T *arr[], int n)
{
	cout<<"template B:";
	for(int i=0;i<n;i++)
	{
		cout<<*arr[i]<<"\t";
	}
	cout<<endl;
}


template <typename T>
T SumArray(T arr[], int n)
{
	T sum = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	return sum;
}

template <typename T>
T SumArray(T *arr[], int n)
{
	T sum = 0;
	for(int i=0;i<n;i++)
	{
		sum+=*arr[i];
	}
	return sum;
}