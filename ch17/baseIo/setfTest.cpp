/*************************
precision（） 控制浮点数的显示精度

setf设置重载显示格式
*************************/

#include <iostream>
using namespace std;

int main()
{
	float pricel = 24.10;
	cout<<pricel<<endl;

	cout.setf(ios_base::showpoint);//其他一些显示格式参考刻本
	cout<<pricel<<endl;

	cout.precision(3);//连着小数点后面一直3位 不显示0
	cout.setf(ios_base::showpoint);//TODO  这里有问题 precision设置～～～
	cout<<pricel<<endl;

	cout<<hex;
	cout.setf(ios_base::uppercase);
	cout<<pricel<<endl;

	return 0;
}