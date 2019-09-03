#ifndef BRESS_H_
#define BRESS_H_
//TODO 继承的简单演练
//TODO 可以使用ABC抽象继承来实现同样的功能
#include <string>

class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass (const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
		// double ml = 500, double r = 0.11125);
	void Deposit(double amt);
	virtual void withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass(){};
};

class BrassPlus: public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0,
		double ml = 500, double r = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void withdraw(double amt);
	void ResetMax(double m){maxLoan = m;}
	void ResetRate(double r){rate = r;}
	void Resetowes(){owesBank = 0;}
};

#endif //BRESS_H_