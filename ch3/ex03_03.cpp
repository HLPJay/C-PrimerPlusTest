/***********************************
输入：纬度，（度，分，秒） 
	1度 = 60 分
	1分 = 60 秒
输出：以度为单位表示输出

************************************/

#include <iostream>
using namespace std;

const int degrees_to_minute = 60;
const int min_to_second = 60;

int main(void)
{
	float degrees;
	float minutes;
	float seconds;
	float result_degrees;

	cout<<"Enter a latitude in degrees, minutes, and seconds"<<endl;
	cout<<"First, enter the degrees:";
	cin >> degrees;
	cout<<"Nect, enter the minutes of arc:";
	cin >> minutes;
	cout<<"Finally, enter the seconds of arc:";
	cin >> seconds;
	result_degrees = (seconds/min_to_second+minutes)/degrees_to_minute + degrees;
	cout<<degrees<<" degrees，"<<minutes <<" minutes," <<seconds<<" seconds, = "<<result_degrees<<" degrees."<<endl;
	return 0;
}