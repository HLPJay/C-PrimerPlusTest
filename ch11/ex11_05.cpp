/*********************************
增加一个状态位控制 如何显示
重载<<,+,-,*,运算符
*********************************/


#include <iostream>
#include "ex11_05_stonewt.h"

int main(void)
{
	using std::cout;
	using std::endl;
	Stonewt poppins(9, 2.8);
	double p_wt = poppins;
	cout<<"Convert to double =>";
	cout<<"poppins :"<<p_wt<<"  pounds\n";
	cout<<"Convert to int =>";
	cout<<"poppins: "<<int(poppins)<<"  pounds\n";

	poppins.int_mode();
	cout<<"one:"<<poppins;
	poppins.double_mode();
	cout<<"two:"<<poppins;
	poppins.stone_mode();
	cout<<"three:"<<poppins;
	return 0;
}
