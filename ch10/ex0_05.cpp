/***************************
从栈中删除和添加customer结构

****************************/



#include <iostream>
#include "ex0_05stack.h"

int main()
{
	using namespace std;
	Stack stack;
	Item it = {"full name", 12.0};

	double sum = 0.0;
	if(stack.isempty())
	{
		cout<<"stack is null"<<endl;
	}

	if(stack.isfull())
	{
		cout<<"stack is full"<<endl;
	}

	for(int i=0;i<11;i++)
	{
		if(stack.push(it))
		{
			cout<<"num "<<i<<" push success"<<endl;
		}else
		{
			cout<<"num "<<i<<" push fail"<<endl;
		}

	}

	for(int i=0;i<11;i++)
	{
		if(stack.pop(it))
		{
			sum += it.payment;
			cout<<"num "<<i<<" push success"<<endl;
		}else
		{
			cout<<"num "<<i<<" push fail"<<endl;
		}
	}
	cout<<"sum:"<<sum<<endl;

	return 0;
}