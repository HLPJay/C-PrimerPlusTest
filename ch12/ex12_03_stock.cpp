// #include <iostream>
#include <cstring>
#include "ex12_03_stock.h"
using namespace std;

Stock::Stock()
{
	str = new char [8];
	strcpy(str, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * c, long n, double pr)
{
	str = new char[std::strlen(c)+1];
	strcpy(str, c);
	if(n<0)
	{
		shares = 0;
	}
	else
	{
		shares = n;
	}
	shares = 0;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	delete [] str;
}

void Stock::buy(long num, double price)
{
	if(num < 0)
	{
		cout<<"Number of shares purchased can not be negative,"
		    <<"transaction is aborted"<<endl;
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if(num < 0)
	{
		cout<<"Number of shares purchased can not be negative,"
		    <<"transaction is aborted"<<endl;
	}
	else if(num >shares)
	{
		cout<<"You can not sell more than you have!"
		    <<"transaction is aborted"<<endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	//TODO 关于设置cout输出的代码
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	cout<<"Company:" <<str <<"Shares:"<<shares<<endl;
	cout<<" Share price : $"<<share_val<<endl;

	cout.precision(2);
	cout<<"  Total Worth：$"<<total_val<<endl;
	//TODO 关于设置cout输出的代码
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

const Stock & Stock::topval(const Stock& s) const
{
	if(s.total_val >total_val)
		return s;
	else
		return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);
	os<<"Company:" <<s.str <<"Shares:"<<s.shares<<std::endl;
	os<<" Share price : $"<<s.share_val<<std::endl;

	os.precision(2);
	os<<"  Total Worth：$"<<s.total_val<<std::endl;
	//TODO 关于设置cout输出的代码
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}