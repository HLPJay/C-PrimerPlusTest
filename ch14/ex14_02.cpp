/******************************
使用私有继承的方式实现第一个练习

******************************/
#include <iostream>
#include "ex14_02_wine.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout<<"Enter your name of wine:";
	char lab[50];
	cin.getline(lab, 50);
	cout<<"Enter size of num:";
	int years;
	cin>>years;
	Wine hoding(lab, years);
	hoding.GetBottles();
	hoding.Show();

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1992};
	int b[YRS] = {40, 60, 72};
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();

	cout<<"label: "<<more.Label()<<" sum:"<<more.sum()<<endl;
	cout<<"Bye! \n";
	return 0;
}