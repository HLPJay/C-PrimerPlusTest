/*******************************
内核格式化

********************************/

#include <iostream>
#include <sstream>
#include <string>

int main()
{
	using namespace std;

	ostringstream outstr;
	string hdisk;
	cout<<"Please input the string:"<<endl;
	getline(cin, hdisk);
	int cap;
	cout<<"please input int:";
	cin>>cap;

	//内核格式化
	outstr<<"the hard disk" <<hdisk<<"has a capacity of"
		  <<cap<<" gigabytes.\n";

	string result = outstr.str();
	cout<<result<<endl;

	//string 初始化并提取内存内容
	string word;
	istringstream instr(result);
	while(instr>>word)
		cout<<word<<endl;
	return 0;
}