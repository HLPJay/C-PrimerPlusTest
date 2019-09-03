/*************************
二进制文件和文本文件

使用write()和read()实现，逐个字节进行复制，而不进行转换。
	第一个参数强制转为为指向char的指针，第二个参数为长度

//TODO 强制转换为char*
*************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> //exit()

inline void eatline() 
{
	while(std::cin.get() != '\n')
		continue;
}

struct planet
{
	char name[20];
	double population;
	double g;
};

const char* file = "planets.bat";

int main(void)
{
	using namespace std;

	planet p1;
	cout<<fixed<<right; 

	ifstream fin;
	fin.open(file, ios_base::in|ios_base::binary);//打开文件  读取 以二进制

	if(fin.is_open())
	{
		cout<<"Here is contents of the "<<file<<":\n";
		while(fin.read((char*)&p1,sizeof(p1)))
		{
			cout<<setw(20)<<p1.name<<":"
				<<setprecision(0)<<setw(12)<<p1.population
				<<setprecision(2)<<setw(6)<<p1.g<<endl;
		}
		fin.close();
	}

	ofstream fout(file, ios_base::out| ios_base::app| ios_base::binary);//打开文件   输入 以二进制追加
	if(!fout.is_open())
	{
		cerr<<"Can't not open "<<file<<" for output\n";
		exit(EXIT_FAILURE);
	}

	cout<<"Enter planet name (enter a blank to quit): \n";
	cin.get(p1.name, 20);
	while(p1.name[0]!='\0') //TODO 数组初始化 \0
	{
		eatline();
		cout<<"Enter planet population:";
		cin>>p1.population;
		cout<<"Enter planet gravity:";
		cin>>p1.g;
		eatline();


		fout.write((char *)&p1, sizeof p1);
		cout<<"Enter planet name (enter a blank to quit): \n";
		cin.get(p1.name, 20);
	}
	fout.close();

	fin.clear();
	fin.open(file,  ios_base::in|ios_base::binary);
	if(fin.is_open())
	{
		cout<<"Here is contents of the "<<file<<":\n";
		while(fin.read((char*)&p1, sizeof p1))  //TODO 强制类型转换，塞值
		{
			cout<<setw(20)<<p1.name<<":"
				<<setprecision(0)<<setw(12)<<p1.population
				<<setprecision(2)<<setw(6)<<p1.g<<endl;
		}
		fin.close();
	}
	cout<<"Done \n";
	return 0;
}