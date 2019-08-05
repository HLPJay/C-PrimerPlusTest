/*****************************
输入：整数的方式输入秒数
输出：天，小时，分钟，秒。
******************************/

#include <iostream>
using namespace std;

const int days_to_hours =24;
const int hours_to_minutes = 60;
const int minutes_to_seconds = 60;

int main(void)
{
	long long seconds;
	cout<<"Enter the number of seconds:";
	cin>>seconds;

	int days,hours,minutes,result_seconds;

	result_seconds = seconds % minutes_to_seconds;
	hours = seconds%(days_to_hours*hours_to_minutes*minutes_to_seconds)/(hours_to_minutes*minutes_to_seconds);
	minutes = seconds%(minutes_to_seconds*minutes_to_seconds)/minutes_to_seconds;
	days = seconds/(days_to_hours*hours_to_minutes*minutes_to_seconds);
	cout<<seconds<<" seconds = " << days <<" days,"<<hours<<" hours," << minutes<<" minutes,"<< result_seconds << " seconds." <<endl;
	return 0;
}