/******************************************
输入 :char*数组或者string字符串数组进行月份存储及提示
     int数组存储输入的销售额
输出：求和及这年的销售情况
*******************************************/

#include <iostream>
using namespace std;

int main(void)
{
	//TODO：char*的初始化要用malloc去初始化
	//char* months[12] = {"January","February", "March", "April", "May", "June",
	//			 "July", "August", "September", "October", "November", "December"};

	string months[12] = {"January","February", "March", "April", "May", "June",
				 "July", "August", "September", "October", "November", "December"};
	int number[12];
	int sum = 0;
	for(int i=0;i<12;i++)
	{
		cout<<"Please input "<<months[i]<< " number:"<<endl;
		cin>>number[i];
		sum += number[i];
	}
	cout<<"sum: "<<sum<<endl;
	return 0;
}