/********************************
接受一个字符串的地址，打印字符串。
********************************/

#include <iostream>
using namespace std;

void printString(const char* str, int n=0);
int main(void)
{
	char str[20] = "Mytest of string";
	printString(str);
	printString(str,1);
	return 0;
}

void printString(const char* str, int n)
{
	if(!n)
	{
		cout<<"str:"<<str<<endl;
	}else
	{
		cout<<"end with n!=0"<<endl;
	}
	
	return;
}