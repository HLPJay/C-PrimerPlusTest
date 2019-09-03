/*************************************
编写10.7和10.8的代码
*************************************/

//默认赋值和复制构造函数    
#include <iostream>
#include "ex12_03_stock.h"

const int SIZE = 4;

int main()
{
	//赋值构造
	// Stock stocks [SIZE] = {
	// 	Stock("NanoSmart",12,20.0),
	// 	Stock("Boffo ObJects", 200,2.0),
	// 	Stock("MNonolithic Obelisks", 130, 3.25),
	// 	Stock("Fleep EnterPrises", 60, 6.5)
	// };
	//TODO  直接构造
	Stock stocks [SIZE] = {
		{"NanoSmart",12,20.0},
		{"Boffo ObJects", 200,2.0},
		{"MNonolithic Obelisks", 130, 3.25},
		{"Fleep EnterPrises", 60, 6.5}
	};

	std::cout<<"Stock holding: \n";
	int st;
	for(st = 0; st<SIZE; st++)
		// stocks[st].show();
		std::cout<<stocks[st];

	const Stock *top = &stocks[0];
	for(st = 1; st<SIZE; st++)
		top = &top->topval(stocks[st]);
	std::cout<<"\n Most valuable holding:\n";
	// top->show();
	std::cout<<*top;
	return 0;
}