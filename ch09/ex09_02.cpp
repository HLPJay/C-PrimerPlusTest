/*****************************************
修改程序 以string代替字符数组 
*****************************************/

#include <iostream>
using namespace std;

const int arSize = 40;
void strcount(const char* str);

int main()
{
	using namespace std;
	char input[arSize];
	char next;

	cout<<"please input str:";
	cin.get(input, arSize);  //TODO: cin.get
	while(cin)
	{
		cin.get(next);
		cout<<"next:"<<next<<"**"<<endl;
		while(next != '\n')
		{
			cout<<"next:"<<next<<endl;
			cin.get(next);
		}
		strcount(input);
		cout<<"enter next line, (empty line to quit.):";
		cin.get(input, arSize);
	}
	return 0;
}

//观察total和count的显示  理解静态作用域
void strcount(const char* str)
{
	using namespace std;
	static int total =0;
	int count = 0;

	cout<<"str:"<<str<<endl;

	//遍历字符串
	while(*str++)
	{
		count++;
	}
	total += count;
	cout<<"str length total:"<<total<<endl;
	cout<<"str length count:"<<count<<endl;
	return ;
}