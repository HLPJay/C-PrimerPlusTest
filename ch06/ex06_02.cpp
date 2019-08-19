/*********************************8
输入：最多将十个donation输入十个doulbe数组，用array
输出：非数字的时候终止，
	 输出平均值以及大于平均值的个数
*********************************/
//TODO :string和数值相互转换也是一个知识点
//length()和size（）的区别
//求数组的实际大小？
//https://www.cnblogs.com/johngu/p/7878029.html
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <array>
#include <string>
using namespace std;

const int ArSize = 10;
bool IsDigit(string & );

int main(void)
{
	array<double,ArSize> myArray;
	double sum = 0.0;
	double avg = 0.0;
	string donation;
	int actualSize;
	int largeOfavg = 0;
	for(int i=0;i<ArSize;i++)
	{
		cout<<"please enter "<<i<<" donation:";
		cin>>donation;
		if(IsDigit(donation))
		{
			myArray[i] = atof(donation.c_str());
			sum  += myArray[i];
		}else
		{
			actualSize = i;
			break;
		}
	}

	avg = sum/actualSize;
	cout.precision(4);
	for(int i=0;i<actualSize;i++)
	{
		cout<<"myArray ["<<i<<"]:"<<myArray[i]<<" "<<endl;
		if(avg<myArray[i])
		{
			++largeOfavg;
		}
	}

	cout<<"sum:"<<sum<<" avg:"<<avg<<" ctualSize:"<<actualSize<<" the large of avg num is: "<<largeOfavg<<endl;
	return 0;
	//1:输入一个字符串
	//2:判断字符串是否是数字
	//3：如果是，则输入。  否则终止

}

bool IsDigit(string & str)
{

	int pointnum = 0;
	for(int i=0;i<str.length();i++)
	{
		if((str[i]=='.'))
		{
			++pointnum;
		}

		if(pointnum>1)
		{
			return false;
		}

		if(!isdigit(str[i])&&(str[i]!='.'))
		{
			return false;
		}
	}
	return true;
}