/*******************************
一个结构体，按值传递，按地址传递，并写一个调用函数

********************************/

#include <iostream>
using namespace std;

struct box{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void PassByValue(box boxOne);
void PassByAddress(box *boxOne);

int main(void)
{
	box boxOne = {
		"maked by china",12.3, 11, 10.2,17
	};

	PassByValue(boxOne);
	PassByAddress(&boxOne);
	return 0;
}


void PassByValue(box boxOne)
{
	cout<<"boxOne.maker:"<<boxOne.maker<<endl;
	cout<<"boxOne.height:"<<boxOne.height<<endl;
	cout<<"boxOne.width:"<<boxOne.width<<endl;
	cout<<"boxOne.length:"<<boxOne.length<<endl;
	cout<<"boxOne.volume:"<<boxOne.volume<<endl;
}

void PassByAddress(box *boxOne)
{
	boxOne->volume = boxOne->height * boxOne->width * boxOne->length;
	cout<<"boxOne->maker:"<<boxOne->maker<<endl;
	cout<<"boxOne->height:"<<boxOne->height<<endl;
	cout<<"boxOne->width:"<<boxOne->width<<endl;
	cout<<"boxOne->length:"<<boxOne->length<<endl;
	cout<<"boxOne->volume:"<<boxOne->volume<<endl;
}