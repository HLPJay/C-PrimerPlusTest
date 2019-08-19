#include <iostream>
#include "ex12_string.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	String name;
	cout<<"please input a string for your name:\n";
	cin>>name;
	cout<<name<<" , please input up to "<< ArSize<<"short saying<empty line to quit>:"<<endl;
	String say[ArSize];//已经调用了构造函数   所以String::HowMany值为11
	char temp[MaxLen];
	int i;
	for(i=0;i<ArSize;i++)
	{
		cout<<i+1<<":";
		cin.get(temp, MaxLen);
		while(cin&& cin.get()!='\n')  //TODO cin的方式获取string输入
			continue;
		if(!cin||temp[0] == '\0')//TODO 判断空行
			break;
		else
			say[i] = temp;
	}

	int total = i;
	if(total >0)
	{
		cout<<"Here is your says:\n";
		for(i=0;i<total;i++)
			cout<<say[i][0]<<":"<<say[i]<<endl;

		int shortest = 0;
		int first =0;
		for(i=0;i<total;i++)
		{
			if(say[i].length()<say[shortest].length())
				shortest = i;
			if(say[i]<say[first])
				first = i;
		}
		cout<<"Shortest saying: \n"<<say[shortest]<<endl;
		cout<<"first alphabetically: \n"<<say[shortest]<<endl;
		cout<<"this program used "<<String::HowMany()<<" String Object. Bye"<<endl;
	}
	else
	{
		cout<<"no input"<<endl;
	}
	return 0;
}