#ifndef EX13_03_ABC_
#define EX13_03_ABC_

#include <iostream>  //std::ostream


/*************************
找三个类共有的接口，之定义初始化 和共有的operator<<
**************************/

class ABC
{
private:
	char* label;
	int rating;
public:
	ABC(const char* l= "null", int r= 0);
	ABC(const ABC &rs);
	virtual ~ABC();  //TODO =0纯虚函数
	virtual void View();
	virtual ABC &operator=(const ABC &rs);
	friend std::ostream & operator<<(std::ostream &os, const ABC &rs);
};

class BassDMA: public ABC
{
private:

public:
	BassDMA(const char* l= "null", int r= 0);
	BassDMA(const BassDMA &rs);
	virtual ~BassDMA();
	// virtual void View(); //直接使用基类的方法
	BassDMA &operator=(const BassDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const BassDMA &rs);
};

class LacksDMA:public ABC //TODO  默认析构函数
{
private:
	enum{ COL_LEN = 40};
	char color[COL_LEN];
public:
	LacksDMA(const char* c = "blank", const char* l = "null", int r= 0);
	LacksDMA(const char* c, const BassDMA & rs);
	virtual ~LacksDMA(){};
	virtual void View(); 
	LacksDMA &operator=(const LacksDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const LacksDMA &rs);
};

class hasDMA: public ABC
{
private:
	char * style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r =0);
	hasDMA(const char* s, const BassDMA& rs);
	hasDMA(const hasDMA &hs);
	virtual ~hasDMA();
	virtual void View(); 
	hasDMA & operator = (const hasDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const hasDMA &rs);
};


#endif //EX13_03_ABC_