/*************************
cout
	dec 十进制
	hex 十六进制
	oct 八进制
	widtch 调整字节宽度
	fill 填充字符
*************************/

#include <iostream>
using namespace std;

int main()
{
	int i = 13;
	cout.fill('*');

	cout.width(3);//只影响下一个 右对齐
	cout<<i;
	cout.width(8);
	cout<<i*i<<endl;

	cout<<hex;  //TODO 这里的原型
	cout.width(3);
	cout<<i;
	cout.width(8);
	cout<<i*i<<endl;

	cout<<oct;
	cout.width(3);
	cout<<i;
	cout.width(8);
	cout<<i*i<<endl;

	dec(cout);
	cout.width(3);
	cout<<i;
	cout.width(8);
	cout<<i*i<<endl;


	return 0;
}