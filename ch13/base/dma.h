#ifndef EX13_03_ABC_
#define EX13_03_ABC_

#include <iostream>  //std::ostream

class BassDMA
{
private:
	char* label;
	int rating;

public:
	BassDMA(const char* l= "null", int r= 0);
	BassDMA(const BassDMA &rs);
	virtual ~BassDMA();

	BassDMA &operator=(const BassDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const BassDMA &rs);
};

class LacksDMA:public BassDMA //TODO  默认析构函数
{
private:
	enum{ COL_LEN = 40};
	char color[COL_LEN];
public:
	LacksDMA(const char* c = "blank", const char* l = "null", int r= 0);
	LacksDMA(const char* c, const BassDMA & rs);
	friend std::ostream & operator<<(std::ostream &os, const LacksDMA &rs);
};

class hasDMA: public BassDMA
{
private:
	char * style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r =0);
	hasDMA(const char* s, const BassDMA& rs);
	hasDMA(const hasDMA &hs);
	~hasDMA();
	hasDMA & operator = (const hasDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const hasDMA &rs);
};


#endif //EX13_03_ABC_