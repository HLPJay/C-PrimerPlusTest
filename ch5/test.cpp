//创建延时循环
//c++中ctime中提供了而一个常量CLOCKS_PER_SEC(该常量×秒数 得到以系统为单位的时间),
//clock()返回值为clock_t为单位的系统时间。


// #include <iostream>
// #include <unistd.h>
// #include <ctime>
// using namespace std;

// int main(void)
// {
// 	cout<<"Please Input The delay time:";
// 	int secs;
// 	cin >> secs;
// 	clock_t delay = secs * CLOCKS_PER_SEC;//CLOCKS_PER_SEC系统以s为单位的周期数
// 	cout << "Starting..." << endl;

// 	clock_t start = clock();//时间单位为单位

//     int i = 0;
// 	while(clock() - start < delay)
// 	{

// 		cout<<"i:"<<i<<" start:"<<start<<" now:"<<clock()<<" delay:"<<delay<<endl;
// 		i++;
// 		sleep(1);
// 	}
// 	cout<<"done!"<<endl;
// 	return 0;
// }

//1 2 4 8 16 32 64
#include <iostream>
using namespace std;
int main(void)
{
	const int multiple = 2;
	int number = 1;
	do{
		cout<<number<<" ";
		number *= multiple;
	}while(number<=64);
	cout<<endl;
	return 0;
}