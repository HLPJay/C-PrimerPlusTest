	#include <iostream>
	#include "ex09_04sale.h"
	
	using namespace SALES;
	// void setSales(Sales & s, const double ar[], int n);
	// void setSales(Sales & s);
	// void showSales(const Sales& s );
	int main()
	{

		Sales s;
		double ar[] = {1,2,3};
		setSales(s, ar, 3);
		showSales(s);

		Sales s1;
		double ar1[] = {5,3,1,2,3};
		setSales(s1, ar1, 5);
		showSales(s1);

		Sales s2;
		setSales(s2);
		showSales(s2);

		return 0;
	}