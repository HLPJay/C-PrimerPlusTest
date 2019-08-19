/**********************************
根据头文件的声明，实现函数的定义，并在main函数中调用相关的函数
编译方式：g++ ex09_01.cpp ex09_01golf.cpp -o ex09_01
**********************************/

#include <iostream>
#include "./ex09_01golf.h"

using namespace std;

int main()
{
	char name [40] = "mytest of name";
	int num = 2;
	golf golftest;
	setgolf(golftest, name, num);
	golf golfnull ={"", 3};
	cout<<"setgolf return:"<<setgolf(golftest)<<endl;
	cout<<"setgolf return:"<<setgolf(golfnull)<<endl;

	handicap(golftest,3);
	showgolf(golftest);
	return 0;
}