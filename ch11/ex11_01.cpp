 /*********************************
修改程序11.15  使随机漫步存储在文件中
构造vector函数，使用vector实现随机漫步
 *********************************/

/***********************************************
使用vector来模拟随机漫步
***********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "ex11_01_vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0)); //send random-num generator

	ofstream outFile;
	char filename [] = "ex11_01.txt";
	outFile.open(filename);
	if(!outFile.is_open())
	{
		cout<<"can not open this file:"<<filename<<" ."<<endl;;
		exit(EXIT_FAILURE);
	}
	double direction;
	Vector step;
	Vector result {0.0,0.0};

	unsigned long steps = 0;
	double target;
	double dstep;
	cout<<"Enter target distance (q or quit):";
	while(cin>>target)
	{
		cout<<"Enter step Length:";
		if(!(cin>>dstep))  //这里得括起来
			break;
		outFile<<"Target Distance: "<<target<<" Step Size: "<<dstep<<endl;
		if(steps == 0)
		{
			outFile<<"0 :" <<"(x,y) = "<<"(0, 0)"<<endl;
		}
		while(result.magval()<target)
		{
			direction = rand()%360;
			step.reset(dstep, direction, VECTOR::Vector::POL);//TODO ：类对象中枚举的使用方法
			result = result +step;
			steps++;
			outFile<<steps<<":" <<"(x,y) = "<<"("<<step.xval()<<","<<step.yval()<<")"<<endl;
		}
		outFile<<"After "<<steps<<"  steps, the subject"
		     "has the following location:\n";
		outFile<<result<<endl;
		cout<<"After "<<steps<<"  steps, the subject"
		     "has the following location:\n";
		cout<<result<<endl;
		result.polar_mode();
		outFile<<"or \n"<<result <<endl;
		outFile<<"Average outward distance per step = "
		    <<result.magval()/steps<<endl;
		cout<<"or \n"<<result <<endl;
		cout<<"Average outward distance per step = "
		    <<result.magval()/steps<<endl;
		steps = 0;
		result.reset(0.0,0.0);
		cout<<"Enter target distance (q or quit):";
	}
	cout<<"Bye!\n";
	cin.clear();
	outFile.close();
	while(cin.get()!='\n')
		continue;
	return 0;
}