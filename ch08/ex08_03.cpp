/******************************
string 引用传参，转为大写输出
******************************/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


void StringToUpper(string & str);
int main(void)
{
	string str;
	cout<<"Enter String(q to quit):";
	// cin>>str;
	getline(cin,str);
	while(str!="q")
	{
		StringToUpper(str);
		cout<<"Next String(q to quit):";
		// cin>>str;
		getline(cin,str);
	}
	return 0;
}

void StringToUpper(string & str)
{
	for(int i=0;i<str.length();i++)
	{
		str[i] = toupper(str[i]);
	}
	cout<<"UPPER:"<<str<<endl;
	return;
}