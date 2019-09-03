/****************************
抛出异常测试
****************************/

#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
	double x,y,z;
	std::cout<<"Enter x, y: ";
	while(std::cin>>x>>y)//TODO  数值类型为什么输入字母会挂
	{
		try{
			z=hmean(x,y);
		}
		catch(const char* s)
		{
			std::cout<<s<<std::endl;
			std::cout<<"enter a new number:"<<std::endl;
			continue;
		}
		std::cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "<<z<<std::endl;
		std::cout<<"Enter q to quit:";
	}
	std::cout<<"bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if(a==-b)
	{
		throw "bad hmean() arguments: a=-b not allowed.";
	}
	return 2.0*a*b/(a+b);
}
