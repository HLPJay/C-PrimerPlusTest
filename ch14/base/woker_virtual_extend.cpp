#include <iostream>
#include "woker_virtual_extend.h"


using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {} //纯虚函数  抽象类 但是还是得定义函数体  子类析构时调用

void Worker::Data() const
{
	cout<<"Name: "<<fullname<<endl;
	cout<<"Employee id :"<<id<<endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout<<"Enter Employee id:";
	cin>>id;
	while(cin.get()!='\n')
		continue;
}


void Waiter::Set()
{
	cout<<"Enter Waiter name:";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout<<"Category : Waiter \n";
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout<<"Waiter's panache rating:"<<panache<<endl;
}

void Waiter::Get()
{
	cout<<"Enter Waiter's panache rating:";
	cin>>panache;
	while(cin.get()!='\n')
		continue;
}
//TODO 定义静态类型
char *Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto",
	 "soprano", "bass", "baritone", "tenor"};

void Singer::Data() const
{
	cout<<"Voval range:" <<pv[voice]<<endl;
}

void Singer::Get()
{
	cout<<"Enter number for Singer's Voval range:" <<endl;
	int i;
	for(i =0 ;i<Vtypes;i++)
	{
		cout<<i<<":"<<pv[i]<<"    ";
		if(i%4 == 3)
			cout<<endl;
	}
	if(i%4 != 0)
		cout<<"\n";
	cin>>voice;
	while(cin.get()!='\n')
		continue;
}

void Singer::Set()
{
	cout<<"Enter Singer's name:"<<endl;
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout<<"Gategory: Singer\n";
	Worker::Data();
	Data();
}


void SingingWaiter::Data() const
{
	Waiter::Data();
	Singer::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout<<"Enter Waiter's name:"<<endl;
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout<<"SingingWaiter: Waiter \n";
	Worker::Data();
	Data();
}
