/*****************************************
修改程序 以string代替字符数组 
*****************************************/

#include <iostream>
#include <string>
using namespace std;


void strcount(string& str);

int main()
{
	string str;
	char next;

	cout<<"please input str:";
	getline(cin, str);  //TODO: getline获取一行   以回车键终止
	while(str!="")
	{
		strcount(str);
		cout<<"enter next line, (empty line to quit.):";
		getline(cin, str); 
	}
	return 0;
}

//观察total和count的显示  理解静态作用域
void strcount(string& str)
{
	static int total =0;
	int count = 0;
	count = str.length();
	total += count;
	cout<<"str length total:"<<total<<endl;
	cout<<"str length count:"<<count<<endl;
	return ;
}

