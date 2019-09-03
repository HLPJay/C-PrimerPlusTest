#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
	double x,y,z;
	std::cout<<"Enter x, y: ";
	while(std::cin>>x>>y)
	{
		z=hmean(x,y);
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
		std::cout<<"untenable arguments to hmean \n";
		std::abort(); //TODO abort 用错误码可以代替
	}
	return 2.0*a*b/(a+b);
}
