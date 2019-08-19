//1英尺(ft)=12英寸(in) Feet in inches

#include <iostream>

const double ft_per_in = 12.0;

int main(void)
{
	using namespace std;
	cout << "Please input your height:";
	double inches_heght;
	cin>>inches_heght;
	cout << "The inches heigh is:" << inches_heght << endl;
	double feet_height;
	feet_height = inches_heght/ft_per_in;
	cout <<"The feet height is:" << feet_height <<endl;
	return 0;
}