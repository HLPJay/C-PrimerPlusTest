#ifndef EX13_01_CD_
#define EX13_01_CD_

#include <iostream>

class Cd
{
private:
	// char performer[50];
	// char label[20];
	char *performer;
	char *label;
	int selections;
	double playtime;
public:
	Cd(const char *s1,const char *s2, int n, double x);
	Cd(const Cd &d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd &operator=(const Cd &cd);

};

class classic: public Cd
{
private:
	char * mainStr;
public:
	//构造函数 复制  赋值
	classic(const char *s1,const char *s2,const char *s3, int n, double x);
	classic(const classic& c);
	classic();
	virtual ~classic();
	virtual void Report() const;
	classic &operator=(const classic &cd);
};
#endif