/*************************
从任意文件处读取文件：
seekg() 输入指针移动到指定位置
seekp() 输出指针移动到指定位置
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
	cout<<fixed; 

	fstream finout(file, ios_base::in| ios_base::out| ios_base::binary);//读写打开文件   输入 以二进制追加

	int ct = 0;
	if(finout.is_open())
	{
		finout.seekg(0);
		cout<<"Here is contents of the "<<file<<":\n";
		while(finout.read((char*)&p1, sizeof p1))  //TODO 强制类型转换，塞值
		{
			cout<<ct++<<setw(20)<<p1.name<<":"
				<<setprecision(0)<<setw(12)<<p1.population
				<<setprecision(2)<<setw(6)<<p1.g<<endl;
		}
		
		if(finout.eof())
		{
			finout.clear();
		}
		else
		{
			cerr<<"Error in reading "<<file<<endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr<<file<<" can not open. "<<endl;
		exit(EXIT_FAILURE);
	}

	cout<<"Enter the record number you wish to change:";
	long rec;
	cin>>rec;

	eatline();
	if(rec<0||rec>=ct)
	{
		cerr<<"invalid record number. "<<endl;
		exit(EXIT_FAILURE);
	}

	streampos place = rec*sizeof(p1);
	finout.seekg(place);
	if(finout.fail())
	{
		cerr<<"Error on attempted seek 。 "<<endl;
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&p1, sizeof p1);
	cout<<"you selection \n";
	cout<<rec<<setw(20)<<p1.name<<":"
				<<setprecision(0)<<setw(12)<<p1.population
				<<setprecision(2)<<setw(6)<<p1.g<<endl;

	if(finout.eof())
	{
		finout.clear();
	}

	cout<<"Please input your name:"<<endl;
	cin.get(p1.name, 20);
	eatline();
	cout<<"Enter planet population:";
	cin>>p1.population;
	cout<<"Enter planet gravity:";
	cin>>p1.g;

	finout.seekp(place);
	finout.write((char*)&p1, sizeof p1)<<flush;
	if(finout.fail())
	{
		cerr<<"Error on attempted write 。 "<<endl;
		exit(EXIT_FAILURE);
	}


	ct = 0;
	finout.seekg(0);
	cout<<"Here is the new contents of the "<<file<<":"<<endl;
	while(finout.read((char*)&p1, sizeof p1))
	{
		cout<<ct++<<setw(20)<<p1.name<<":"
				<<setprecision(0)<<setw(12)<<p1.population
				<<setprecision(2)<<setw(6)<<p1.g<<endl;
	}
	finout.close();
	cout<<"Done \n";
	return 0;
}