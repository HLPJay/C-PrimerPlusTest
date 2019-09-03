/*************************
命令行处理  用到main函数可变参数

文件模式

打开文件并输入写入， 
追加形式打开文件并输入，
重新打开显示文件内容
*************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[])
{

	using namespace std;
	if(argc == 1)
	{
		cout<<"Usage: "<<argv[0]<<" filename.\n.";
		exit(EXIT_FAILURE);
	}

	char ch;
	ifstream fin;
	fin.open(argv[1]);
	if(fin.is_open())
	{
		cout<<"Here is the courrent contents of the "<<argv[1]<< " file.\n";
		while(fin.get(ch))
		{
			cout<<ch;
		}
		fin.close();
	}

	ofstream fout(argv[1], ios::out|ios::app);
	if(!fout.is_open())
	{
		cerr<<"Can't open file:"<<argv[1]<<endl;
		exit(EXIT_FAILURE);
	}

	cout<<"Enter contents:"<<endl;
	string name;
	while(getline(cin,name) && name.size() >0)
	{
		fout<<name<<endl;//写入文件
	}
	fout.close();

	fin.clear();
	fin.open(argv[1]);
	fin.open(argv[1]);
	if(fin.is_open())
	{
		cout<<"Here is the courrent contents of the new "<<argv[1]<< " file.\n";
		while(fin.get(ch))
		{
			cout<<ch;
		}
		fin.close();
	}
	cout<<"Done.\n";
	return 0;
}