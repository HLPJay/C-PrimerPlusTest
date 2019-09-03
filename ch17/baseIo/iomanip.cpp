/*************************
访问数学库  一般要在g++编译时加 -lm
iomanip提供了一些控制符 设置精度 填充字符 和字符宽度

     N    sqort root   fourth root
****10       3.162        1.7783
****20       4.472        2.1147
****30       5.477        2.3403
****40       6.325        2.5149
****50       7.071        2.6591
****60       7.746        2.7832
****70       8.367        2.8925
****80       8.944        2.9907
****90       9.487        3.0801


*************************/

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	using namespace std;
	cout<<fixed<<right;
	cout<<setw(6)<<"N"<<setw(14)<<"sqort root"<<setw(15)<<"fourth root\n";
	double root;
	for(int i=10; i <100; i+=10)
	{
		root = sqrt(double(i));
		cout<<setw(6)<<setfill('*')<<i<<setfill(' ')
			<<setw(12)<<setprecision(3)<<root
			<<setw(14)<<setprecision(4)<<sqrt(root)
			<<endl;

	}
	return 0;
}