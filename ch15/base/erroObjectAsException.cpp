/****************************
将对象用作异常类型
****************************/

#include <iostream>
#include <cmath>

#include "erroObjectAsException.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using namespace std;

	double x,y,z;
	std::cout<<"Enter x, y: ";

	while(std::cin>>x>>y)//TODO  数值类型为什么输入字母会挂
	{
		try{
			z=hmean(x,y);
			cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "<<z<<endl;
			cout<<"Geometric mean of "<<x<<" and "<<y<<" is "<<gmean(x,y)<<endl;
			std::cout<<"Enter q to quit:";
		}
		catch(bad_hmean &bg)
		{
			bg.mesg();
			cout<<"Try again\n";
			continue;
		}
		catch(bad_gmean &hg)
		{
			hg.mesg();
			cout<<"Value used:"<<hg.v1<<","<<hg.v2<<endl;
			cout<<"Sorry,you do not get to play any more. \n";
			break;
		}
		
	}
	std::cout<<"bye!\n";
	return 0;
}


double hmean(double a, double b)
{
	if(a == -b)
	{
		throw bad_hmean(a ,b);
	}
	return 2.0*a*b/(a+b);
}


double gmean(double a, double b)
{
	if(a<0||b<0)
	{
		throw bad_gmean(a, b);
	}
	return std::sqrt(a*b);
}