
/**************************
输入：欧洲风格，100公里使用的汽油量(升)。（燃料/距离）
输出：转换为美国风格耗油，每加仑多少英里(距离/燃料)
100公里 = 62.14英里
1加仑 = 3.875升

**************************/

#include <iostream>
using namespace std;

const float KilometerToMile = 62.14;
const float gallonToRise = 3.875;
int main(void)
{
	cout<<"Enter the Europe 100 Kilometer of fuel consumption:";
	double europe_fuel;
	cin>>europe_fuel;
	cout<<"Europe:"<<europe_fuel/100 <<"fuel/Kilometer"<<endl;
	cout<<"US:"<<100*KilometerToMile/(europe_fuel/gallonToRise)<<endl;

	return 0;
}