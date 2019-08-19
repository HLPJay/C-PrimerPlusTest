/**********************************
输入：名，姓，组合姓名
输出：使用char数组和cstring头文件来实现

**********************************/

#include <iostream>
#include <cstring> //TODO:确定其头文件的功能,
using namespace std;

int main(void)
{
	const int nameSize = 20;
	char firstName[20];
	char *secondName = new char [20];
	char allName[20];
	
	cout<<"Enter your first Name:";
	cin.get(firstName,nameSize);
	cin.get();

	cout<<"Enter your last name:";
	cin.get(secondName,nameSize);

	strcpy(allName, firstName);
	strcat(allName, ", ");
	strcat(allName, secondName);
	cout<<"Here the information in a single string:"<<allName<<endl;

	delete [] secondName;
	secondName = nullptr;
	return 0;
}