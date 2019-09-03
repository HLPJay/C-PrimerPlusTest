
#include <iostream>
using namespace std;
int main(void)
{
	char ch;
	int ct1,ct2;
	ct1 = ct2 = 0;
	while((ch = cin.get())!='$') //回车和换行也能识别到 到第一个$结束
	{
		cout<<ch<<" * ";
		ct1++;
		if(ch = '$')//!!!这里用的是赋值符号
		{
			ct2++;
		}
		cout<<ch<<" * ";
	}
	cout<<"ct1="<<ct1<<", ct2 = "<<ct2<<endl;
	return 0;
}