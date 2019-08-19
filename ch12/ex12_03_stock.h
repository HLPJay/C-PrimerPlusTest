#ifndef EX12_03_STOCK_H_
#define EX12_03_STOCK_H_

#include <iostream>
class Stock
{
private:
	char *str;
	int shares;
	double share_val;
	double total_val;
	void set_tot()
	{
		total_val = shares *share_val;
	}
public:
	Stock();
	Stock(const char * c, long n=0, double pr = 0.0);
	~Stock();
	//TODO 禁止复制和赋值构造函数
	Stock(const Stock &)=delete;
	Stock& operator= (const Stock &)=delete ;

	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock & topval(const Stock& s) const;
	friend std::ostream & operator<<(std::ostream & os, const Stock & s);//TODO ostream属于std
};
#endif