/****************************
重新编写time类，使用友元来实现重载运算符
****************************/

#include <iostream>
#include "ex11_04_time.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout<<"aida and tosca:"<<endl;
	cout<<"aida:" <<aida <<" tosca:"<<tosca<<endl;
	temp = aida + tosca;
	cout<<"aida + tosca :"<<temp<<endl;
	temp = aida*17;
	cout<<"aida*17 :"<<temp<<endl;
	cout<<"10.0 * tosca :"<<10.0 * tosca<<endl;
	return 0;
}