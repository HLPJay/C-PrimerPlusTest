#include <iostream>
#include "bress.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;  //TODO std的设置
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass (const std::string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)//存款
{
	if(amt < 0)
	{
		cout << "Negative deoisit not allowed";
	}
	else
		balance+=amt;
}

double Brass::Balance() const
{
	return balance;
}

void Brass::withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if(amt<0)
	{
		cout<<"withdrawal amount must be positive:"
			<<"withdrawal canceled \n";
	}  
	else if(amt <= balance)
	{
		balance -= amt;
	}
	else
	{
		cout<<"withdrawal amount of $"<<amt
			<<"exceed your balance. \n"
			<<"withdrawal canceled \n";
	}
	restore(initialState, prec);
}

void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout<<"Client :"<<fullName<<endl;
	cout<<"account nun:"<<acctNum<<endl;
	cout<<"balance : $"<<balance<<endl;
	restore(initialState, prec);
}

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r)
	:Brass(s, an, bal)
{
	maxLoan = ml;
	rate = r;
	owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
	:Brass(ba)
{
	maxLoan = ml;
	rate = r;
	owesBank = 0.0;
}

void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct(); //虚函数通过这种方式调用

	cout<<"maxinum loan: $ :"<<maxLoan<<endl;
	cout<<"owed to bank: $"<<owesBank<<endl;
	cout.precision(3);
	cout<<"Loan Rate : "<<100*rate<<"%"<<endl;
	restore(initialState, prec);
}

void BrassPlus::withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();//直接调用基类方法
	if(amt<=bal)
	{
		Brass::withdraw(amt);
	}
	else if( amt<= bal+maxLoan-owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0+rate);//欠银行的钱
		cout<<"Bank advance: $"<<advance<<endl;
		cout<<"Finance charge: $"<<advance*rate<<endl;
		Deposit(advance); //透支计算
		Brass::withdraw(amt);
	}
	else
	{
		cout<<"Credit limit exceed . Transaction cancelled . \n";
	}
	restore(initialState, prec);
}

format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}