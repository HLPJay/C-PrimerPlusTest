/***********************************************
使用vector来模拟随机漫步
***********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ex11_01_vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0)); //send random-num generator

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

		while(result.magval()<target)
		{
			direction = rand()%360;
			step.reset(dstep, direction, VECTOR::Vector::POL);//TODO ：类对象中枚举的使用方法
			result = result +step;
			steps++;
		}
		cout<<"After "<<steps<<"  steps, the subject"
		     "has the following location:\n";
		cout<<result<<endl;
		result.polar_mode();
		cout<<"or \n"<<result <<endl;
		cout<<"Average outward distance per step = "
		    <<result.magval()/steps<<endl;
		steps = 0;
		result.reset(0.0,0.0);
		cout<<"Enter target distance (q or quit):";
	}
	cout<<"Bye!\n";
	cin.clear();
	while(cin.get()!='\n')
		continue;
	return 0;
}