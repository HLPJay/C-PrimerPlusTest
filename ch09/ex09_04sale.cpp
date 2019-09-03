	#include <iostream>
	#include "ex09_04sale.h"
	
	// using namespace SALES;//TODO   如果这种用法，在main函数中是找不到定义的？？？  真正的定义没有在命名空间中

namespace SALES
{
	//copies the lesser of 4 or n items from the array ar to the sales  number of s and computes and stores the average,maxinum, and mininum values of the entered items.remaining elements of sales,if any, set to 0
	void setSales(Sales & s, const double ar[], int n)
	{
		//将数组4项或者n项较小的数据存储到sales中,否则塞0
		if(QUARTERS>=n)
		{
			for(int i=0;i<n;i++)
			{
				s.sales[i] = ar[i];
			}
			for(int i=n;i<QUARTERS;i++)
			{
				s.sales[i] = 0;
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
				s.sales[i] = temp;
				latterofar=temp;
				std::cout<<"temp:"<<temp<<std::endl;
			}
		}
		double max,min,sum,average;
		max = min = s.sales[0];
		sum = s.sales[0];
		for(int i=1;i<QUARTERS;i++)
		{
			if(max<s.sales[i])
			{
				max = s.sales[i];
			}
			if(min>s.sales[i])
			{
				min = s.sales[i];
			}
			sum += s.sales[i];
		}
		average= sum/QUARTERS;
		s.average = average;
		s.max = max;
		s.min = min;

	}

	//gathers sales for 4 quarters interactively,stores them in the 
	//sales member of s and conputes and stores the average maxinum, and mininum values
	void setSales(Sales & s)
	{
		using namespace std;
		cout<<"Enter four quarters sales:";//TODO 应该对输入做保护
		double max,min,sum,average;
		for(int i=0;i<QUARTERS;i++)
		{
			cin>>s.sales[i];
		}

		max = min = s.sales[0];
		sum = s.sales[0];
		for(int i=1;i<QUARTERS;i++)
		{
			if(max<s.sales[i])
			{
				max = s.sales[i];
			}
			if(min>s.sales[i])
			{
				min = s.sales[i];
			}
			sum += s.sales[i];
		}
		average= sum/QUARTERS;
		s.average = average;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales& s )
	{
		using namespace std;
		for(int i=0;i<QUARTERS;i++)
		{
			cout<<"sales ["<<i<<"] = "<<s.sales[i]<<endl;
		}
		cout<<"average:"<<s.average<<endl;
		cout<<"max:"<<s.max<<endl;
		cout<<"min:"<<s.min<<endl;
	}
};