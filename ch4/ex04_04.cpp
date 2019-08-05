/**********************************
输入：名，姓，组合姓名
输出：使用string和string头文件函数来实现

**********************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
 	string firstName;
 	string secondName;
 	string allName;

 	cout<<"Enter your first Name:";
 	getline(cin,firstName);
 	cout<<"Enter your last name:";
 	getline(cin,secondName);

 	allName = firstName + ", " + secondName;
 	cout<<"Here the information in a single string:"<<allName<<endl;
 	return 0;

}