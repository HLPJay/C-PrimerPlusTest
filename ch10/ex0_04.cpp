/*************************************************
基于第九章的编程练习4修改，修改为类的实现方式
**************************************************/
#ifndef  EX10_04_SALE_H_
#define  EX10_04_SALE_H_

#include <iostream>
#include <cstring>
using namespace std;

namespace SALES
{

	class Sales
	{
		static const int QUARTERS = 4;
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales(const double ar[], int n);
		Sales();
		void showSales();
	};

	Sales::Sales(const double ar[], int n)
	{
		if(QUARTERS>=n)
		{
			for(int i=0;i<n;i++)
			{
				this->sales[i] = ar[i];
			}
			for(int i=n;i<QUARTERS;i++)
			{
				this->sales[i] = 0;
			}
		}
		else
		{
			//排序求的最小的四个
			double temp;
			double latterofar;
			for(int i=0;i<QUARTERS;i++)
			{
				temp = ar[0];
				for(int j=0;j<n;j++)
				{
					if(temp > ar[j] && ar[j]>latterofar)
					{
						temp = ar[j];
					}
				}
				this->sales[i] = temp;
				latterofar=temp;
				std::cout<<"temp:"<<temp<<std::endl;
			}
		}
		double max,min,sum,average;
		max = min = this->sales[0];
		sum = this->sales[0];
		for(int i=1;i<QUARTERS;i++)
		{
			if(max<this->sales[i])
			{
				max = this->sales[i];
			}
			if(min>this->sales[i])
			{
				min = this->sales[i];
			}
			sum += this->sales[i];
		}
		average= sum/QUARTERS;
		this->average = average;
		this->max = max;
		this->min = min;
	}

	Sales::Sales()  //默认构造函数输入
	{
		cout<<"Enter four quarters sales:";//TODO 应该对输入做保护
		double max,min,sum,average;
		for(int i=0;i<QUARTERS;i++)
		{
			cin>>this->sales[i];
		}

		max = min = this->sales[0];
		sum = this->sales[0];
		for(int i=1;i<QUARTERS;i++)
		{
			if(max<this->sales[i])
			{
				max = this->sales[i];
			}
			if(min>this->sales[i])
			{
				min = this->sales[i];
			}
			sum += this->sales[i];
		}
		average= sum/QUARTERS;
		this->average = average;
		this->max = max;
		this->min = min;
	}

	void Sales::showSales()
	{
		using namespace std;
		for(int i=0;i<QUARTERS;i++)
		{
			cout<<"sales ["<<i<<"] = "<<this->sales[i]<<endl;
		}
		cout<<"average:"<<this->average<<endl;
		cout<<"max:"<<this->max<<endl;
		cout<<"min:"<<this->min<<endl;
	}
}

int main()
{
	using namespace SALES;

	double ar[] = {1,2,3};
	Sales s(ar, 3);
	s.showSales();

	double ar1[] = {5,3,1,2,3};
	Sales s1(ar1, 5);
	s1.showSales();

	Sales s2;
	s2.showSales();
	return 0;
}
#endif //EX10_04_SALE_H_