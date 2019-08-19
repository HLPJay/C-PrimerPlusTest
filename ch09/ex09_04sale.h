/*************************************************
基于下面的命名空间编写一个由3个文件组成的程序
**************************************************/
#ifndef  EX09_04_SALE_H_
#define  EX09_04_SALE_H_

namespace SALES
{

	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales & s, const double ar[], int n);
	void setSales(Sales & s);
	void showSales(const Sales& s );

}
#endif //EX09_04_SALE_H_