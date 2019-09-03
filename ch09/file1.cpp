

#include <iostream>
using namespace std;

void other();
void another(); //TODO ：本文件没有实现，就是编译不过啊！！！！

int x = 10;
int y;

int main()
{
	cout<<x<<endl;
	{
		int x = 4;
		cout<<x<<endl;
		cout<<y<<endl;
	}
	other();
	// another(); //TODO :ERROR
	return 0;
}

void other()
{
	int y = 1;
	cout<<"Other: "<<x<<", "<<y<<endl;
}