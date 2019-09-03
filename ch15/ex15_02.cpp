#include <iostream>
#include <stdexcept>
#include <cmath>

class bad_hmean: public std::logic_error //TODO  异常源码
{
public:
	bad_hmean():std::logic_error("hean()  invalid arguments: a= -b \n"){}
};


class bad_gmean :public std::logic_error
{
public:
	bad_gmean():std::logic_error("gmean()  arguments should be >=0 \n"){}
};




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
			cout<<"Geometric mean of "<<x<<" and "<<y<<" is "<<gmean(x,y);
			std::cout<<"\n Enter q to quit:";
		}
		catch(bad_hmean &bg)
		{
			cout<<"\n"<<bg.what()<<endl;
			cout<<"Try again\n";
			continue;
		}
		catch(bad_gmean &hg)
		{
			cout<<"\n"<<hg.what()<<endl;
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
		throw bad_hmean();
	}
	return 2.0*a*b/(a+b);
}


double gmean(double a, double b)
{
	if(a<0||b<0)
	{
		throw bad_gmean();
	}
	return std::sqrt(a*b);
}