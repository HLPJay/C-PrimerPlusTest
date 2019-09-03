/**********************************
定义一个结构体，录入
显示
**********************************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//const char *可以直接用字符串初始化
//char*的赋值要用strcpy
//char*类型的变量赋值给string 字符串首地址及字符串
struct CandyBar {
	string name;
	//char name1[30];
	float weight;
	int heat;
};

void SetCandyBar(CandyBar &bar,const char *str = "Millennium Munch", float weight=2.85, int heat=350);
void show(const CandyBar &bar);
int main(void)
{
	CandyBar bar;
	SetCandyBar(bar);
	show(bar);
	return 0;
}

void SetCandyBar(CandyBar &bar,const char *str, float weight, int heat)
{
	bar.name = str;
	//strcpy(bar.name1, str);
	bar.weight = weight;
	bar.heat = heat;
	return;
}

void show(const CandyBar &bar)
{
	cout<<"bar.name:"<<bar.name<<endl;
	cout<<"bar.weight"<<bar.weight<<endl;
	cout<<"bar.heat"<<bar.heat<<endl;
	return;
}

