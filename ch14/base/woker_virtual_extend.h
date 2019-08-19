/*********************************
多重继承，使用虚基类来实现
*********************************/
#ifndef WORKER_VIRTUAL_EXTEND_H_
#define WORKER_VIRTUAL_EXTEND_H_

#include <string>

class Worker
{
private:
	std::string fullname;
	long id;
protected: //TODO 保护继承，只有子类可以公共访问，其他类当做私有
	virtual void Data() const;
	virtual void Get();
public:
	Worker() :fullname("no one"), id(0L){}
	Worker(const std::string &s , long n) :fullname(s), id(n){}
	virtual ~Worker() =0;  //TODO 纯虚函数  纯虚函数将产生抽象类——不能实例化的类 即不能创建此类型的对象
	virtual void Set() = 0;
	virtual void Show() const =0;
};

class Waiter :virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter(): Worker(), panache(0){}
	Waiter(const std::string &s , long n, int p =0):Worker(s, n), panache(p){}
	Waiter(const Worker& wk, int p=0):Worker(wk), panache(p){}

	void Set();
	void Show() const;
};

class Singer :virtual public Worker
{
protected:
	enum{other, alto, contralto, soprano, bass, baritone, tenor};
	enum{Vtypes = 7};
	void Data() const;
	void Get();
private:
	static char *pv[Vtypes]; //TODO 静态变量初始化
	int voice;
public:
	Singer() :Worker(),voice(other){}
	Singer(const std::string &s , long n, int v =other) :Worker(s, n),voice(v){}
	Singer(const Worker &s, int v =other) :Worker(s),voice(v){}

	void Set();
	void Show() const;
};

class SingingWaiter : public Waiter, public Singer  //TDOD 虚基类的使用
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter(){}
	SingingWaiter(const std::string &s , long n, int p =0, int v =other)
		:Worker(s, n), Waiter(s,n,p),Singer(s,n,v){} //虚基类 所以要定义基类的Worker
	SingingWaiter(const Worker& wk, int p =0, int v =other)
		:Waiter(wk,p),Singer(wk,v) {}
	SingingWaiter(const Waiter &wt, int v =other)
		:Worker(wt), Waiter(wt), Singer(wt,v) {}
	SingingWaiter(const Singer& ws, int p =0)
		:Worker(ws), Waiter(ws, p), Singer(ws) {}

	void Set();
	void Show() const;

};

#endif //WORKER_VIRTUAL_EXTEND_H_