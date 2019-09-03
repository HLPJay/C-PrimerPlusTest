/*********************************
声明6个Stonewt对象数组，初始化前三个
循环读取前三个 获取最大的 最小的 以及大于等于11的
*********************************/


#include <iostream>
#include "ex11_06_stonewt.h"

int main(void)
{
	using std::cout;
	using std::endl;
	Stonewt poppins[6];
	Stonewt temp(11.0);
	

	for(int i=0;i<3;i++)
		poppins[i] = Stonewt((i+1)*11.0, Stonewt::DOUBLE_FORMAT);  //TODO :构造函数的初始化

	for(int i=0;i<3;i++)
		cout<<poppins[i];

	Stonewt max = poppins[0];
	Stonewt min = poppins[0];
	for(int i=0;i<3;i++)
	{
		if(max <poppins[i])
			max = poppins[i]; //TODO：赋值构造函数 复制构造函数
		if(min >poppins[i])
			min = poppins[i];
		if(temp<=poppins[i])
			cout<<"Greater than or equal to 11: poppins["<<i<<"]:"<<poppins[i];
	}
	cout<<"max:"<<max;
	cout<<"min:"<<min;
	return 0;
}
