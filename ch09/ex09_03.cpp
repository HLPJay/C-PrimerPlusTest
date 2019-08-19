/***********************************************8

定义一个结构体，
	使用定位new运算符 将两个结构体放在一个缓冲区，并显示出来
		1：静态数组做缓冲区
		2：new运算符分配缓冲区
************************************************/

#include <iostream>
#include <cstring>
using namespace std;

struct chaff
{
	char dross[20];
	int slag;
};

void SetChaff(chaff *pd, int n, char * str, int value);
void ShowChaff(chaff *pd, int n);

const int Size = 2;
char buff[50];//TODO :数组长度，保存在buff中
int main(void)
{
	//使用定位new运算符，保存数据
	chaff *pd;
	pd = new (buff) chaff[Size]; //TODO :定位new申请的内存是静态buffer的内存，是delete管理之外的  所以不需要delete
	char str[]="my test of new.";
	SetChaff(pd,2,str,3);
	ShowChaff(pd,2);

	// delete [] pd;//这里不需要释放
	pd = nullptr;

	chaff * pd2 = new (std::nothrow) chaff[Size];
	SetChaff(pd2,2,str,3);
	ShowChaff(pd2,2);
	if(pd2 != nullptr)
	{
		delete pd2;
		pd2 = nullptr;
	}
	return 0;
}

//TODO 指针的用法以及传指针后，用数组形式的用法
void SetChaff(chaff *pd, int n, char * str, int value)
{
	for(int i=0; i<n; i++)
	{
		strcpy((pd+i)->dross, str);
		(pd+i)->slag = value;
	}

	// for(int i=0; i<n; i++)
	// {
	// 	strcpy(pd[i].dross, str);
	// 	pd[i].slag = value;
	// }
	return ; 
}

void ShowChaff(chaff *pd, int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"dross:"<<pd[i].dross<<endl;
		cout<<"slag:"<<pd[i].slag<<endl;
	}
	return ; 
}