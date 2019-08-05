/***************************

calculate() 两个double 和一个指向函数的指针 
被指向的函数有两个double参数，返回double值
***************************/

#include <iostream>
using namespace std;

typedef double (*p_fun)(double, double);

double add (double a,double b);
double Subtraction (double a,double b);
double calculate(double x1, double x2, p_fun fun);
double calculate1(double x1, double x2, double (*fun1)(double, double));
int main(void)
{
	//循环让用户输入数据，调用calculate
	cout<<"please input a and b:";
	double a,b;
	cin>>a>>b;
	while(a!=-1||b!=-1)
	{
		cout<<a<<"+:"<<b<<"= "<<calculate(a,b,add)<<endl;
		cout<<a<<"+:"<<b<<"= "<<calculate1(a,b,add)<<endl;
		cout<<a<<"+:"<<b<<"= "<<calculate(a,b,Subtraction)<<endl;
		cout<<a<<"+:"<<b<<"= "<<calculate1(a,b,Subtraction)<<endl;
		cout<<"please input a and b:";
		cin>>a>>b;
	}

	//定义一个指针数组 这里需要练习
	p_fun pa[2] = {add, Subtraction};
	double (*pa3[2])(double,double) ={add, Subtraction};//*pa3[i](a,b)

	return 0;
}

double add (double a,double b)
{
	return a+b;
}

double Subtraction (double a,double b)
{
	if(a>b)
	{
		a= a+b;
		b= a-b;
		a= a-b;
	}
	return b-a;
}

//double (*fp)(double,double)
double calculate(double x1, double x2, p_fun fun)
{
	return (*fun)(x1,x2);
}

double calculate1(double x1, double x2, double (*fun1)(double, double))
{
	return (*fun1)(x1,x2);
}