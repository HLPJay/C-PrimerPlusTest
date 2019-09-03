/**************************
输入：用户驱车里程（英里），使用汽油量（加仑）
输出：汽车耗油为1加仑的里程

**************************/


#include <iostream>
using namespace std;

int main()
{
	double driving_mileage;
	double fuel_consumption;
	cout<<"Enter the driving_mileage:";
	cin>>driving_mileage;
	cout<<"Enter the fuel_consumption:";
	cin>>fuel_consumption;

	cout<<"Miles per gallon is "<<driving_mileage/fuel_consumption<<" mileage/gallon."<<endl;
}