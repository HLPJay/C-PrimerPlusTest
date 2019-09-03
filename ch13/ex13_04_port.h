#ifndef EX13_04_PORT_H_
#define EX13_04_PORT_H_


#include <iostream>
using namespace std;

class Port
{
private:
	char * brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "none", const char* st ="none", int b=0);
	Port(const Port & p);
	virtual ~Port();
	Port & operator=(const Port &p);
	Port &operator+=(int b);
	Port &operator-=(int b);

	int BottleCount() const {return bottles ; }
	virtual void Show() const;
	friend ostream & operator<<(ostream& os, const Port & p);
};

class VintagePort:public Port
{
private:
	char *nickname;
	int year;

public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nm, int y);
	VintagePort(const VintagePort &vp);
	~VintagePort();

	VintagePort& operator=(const VintagePort& vp);
	void Show() const;
	friend ostream & operator<<(ostream& os, const VintagePort & p);
};


#endif //EX13_04_PORT_H_
/*****************************
Show()和operator= 重新定义是因为派生类要执行的内容和基类不同 


Port &operator+=(int b);
Port &operator-=(int b);
不用重新定义是因为派生类可以直接用基类的方法

赋值运算符和友元函数不能定义为虚函数

*******************************/