/******************************88
实现了主要的模块，追加模块和命令行输入参考base中的代码

*********************************/

#include <iostream>
#include <string>
#include <fstream>
#include "ex14_05_base.h"

using namespace std;

const int MAX =10;
const string fileName = "ex17_06.txt";
int main()
{
	abstr_emp * pc[MAX];

	//根据用户的输入，把相关的类型保存在文件中
	//然后追加
	//1:定义输入内容
	char ch;
	int i=0;
	cout<<"Menu\n"<<"e:   employee \n"<< "m:   manager\n"
		<<"f:   fink\n"<<"h:  highfink\n"<<"q:   to quit\n";
	cout<<"Please input your choice:";
	cin>>ch;
	while(ch!='q')
	{
		switch(ch)
		{
			case 'e': 
				pc[i++] = new employee("Trip", "Harris", "Thumper");
				break;
			case 'm':
				pc[i++] = new manager("Amorphia", "Spindragon", "Nuancer", 5);
				break;
			case 'f':
				pc[i++] = new fink("Matt", "Oggs", "Oiler", "Juno Barr");
				break;
			case 'h':
				pc[i++] = new highfink("Amorphia", "Spindragon", "Nuancer", "Curly Kew", 5);
				break;
			default :
				cout<<"Please input e/m/f/h/q \n";
		}
		cout<<"Please input your choice:";
		cin>>ch;
	}

	//2：开始写入文件
	ofstream fout(fileName, ios_base::out);
	if(!fout.is_open())
	{
		cerr<<"Can't not open "<<fileName<<" for output\n";
		exit(EXIT_FAILURE);
	}

	//这里需要重构每个类的方法 实现写入
	i=0;
	while(pc[i]!=nullptr)
	{
		pc[i]->writeAll(fout);
		delete pc[i];
		i++;
	}
	// i=0;
	// for(;i<4;i++)
	// {
	// 	pc[i]->writeAll(fout);
	// 	delete pc[i];
	// }
	fout.close();
	return 0;
}