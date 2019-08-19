/********************************

输入：几英尺几英寸 几磅
1英尺 = 12英寸
1英寸 = 0.0254米
1千克 = 2.2磅
输出：BMI = 体重(kg)/身高的平方(m)

********************************/

#include <iostream>

const double feet_to_inch = 12.0;
const double inch_to_meter = 0.0254;
const double kg_to_pound = 2.2;

int main()
{
	using namespace std;

	double feet_heght;
	double inch_height;
	double Pound_weight;

	cout<<"Please input your hegit of feet:";
	cin >> feet_heght;
	cout<<"Please input your hegit of inch:";
	cin >> inch_height;
	cout<<"Please input your weight of pound:";
	cin >> Pound_weight;

	double meter_height;
	double kg_weight;
	meter_height = (feet_heght*feet_to_inch + inch_height) *inch_to_meter;
	kg_weight = Pound_weight/kg_to_pound;

	double BMI;
	BMI = kg_weight/(meter_height*meter_height);

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout<<"Your BMI is :"<<BMI<<endl;
	return 0;

} 