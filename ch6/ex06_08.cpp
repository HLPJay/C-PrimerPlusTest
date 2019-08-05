/**********************************
打开文件，逐个字符读取，直到到达末尾，输出多少个字符
***********************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void)
{
	//写入文件
	ofstream outFile;
	outFile.open("ioTest.txt");

	string inputToFileString;
	float inputToFileFloat;
	cout<<"please input string to file:"<<endl;
    getline(cin,inputToFileString);
	
	while(inputToFileString!= "q")
	{

		outFile<<inputToFileString<<endl;
		cout<<"please input float to file:"<<endl;
		cin>>inputToFileFloat;
		cin.get();
		outFile<<inputToFileFloat<<endl;
		cout<<"please input string to file:"<<endl;
		getline(cin,inputToFileString);
	}
	outFile.close();

	//读出文件，显示字符数
	ifstream inFile;
	inFile.open("ioTest.txt");

	if(!inFile.is_open())
	{
		cout<<"can not open this file .";
		exit(EXIT_FAILURE);
	}

	char ch;
	int count = 0 ;
	inFile>>ch;
	while(inFile.good())
	{
		++count;
		inFile>>ch;
	}

	if(inFile.eof())
	{
		cout<<"end of file with count:"<<count<<endl;
	}else if(inFile.fail())
	{
		cout<<"failed"<<endl;
	}
	else
	{
		cout<<"other failed"<<endl;
	}

	inFile.close();
	return 0;
}