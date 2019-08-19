/*******************************
改造String的实现
重载+运算符
Stringlow（） 字母转为小写
Stringcapital 字母转为大写
字符在字符串中出现的次数
*******************************/


#include <iostream>
using namespace std;

#include "ex12_02_string.h"
int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name:";
	String s3;
	cout<<s2;
	cin>>s3;
	s2 = "My name is" +s3;
	cout<<s2<<".\n";

	s2 = s2 +s1;
	s2.ToUpper();
	cout<<"The string\n"<<s2<<"\n contains"<<s2.GetCharNum('A')<<"'A' characters in it . \n";

	s1 = "red";
	String rgb[3] = {String(s1),String("green"), String("blue")};//TODO 不允许隐士转换
	cout<<"Enter the name of a primary color for mixing light:";
	String ans;
	bool success = false;
	while(cin>>ans)
	{
		ans.StringLow();
		for(int i=0;i<3;i++)
		{
			if(ans == rgb[i])
			{
				cout<<"That is right. \n";
				success = true;
				break;
			}
		}
		if(success)
			break;
		else
			cout<<"try again\n";
	}
	cout<<"Bye\n";
	return 0;
}