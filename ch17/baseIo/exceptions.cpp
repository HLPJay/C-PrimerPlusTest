/*************************
exceptions 来控制io异常
ios::base::failure 由exception派生而来，包含what方法

内部用到clear 将当前状态与exceptions状态比较

isspace(cin.get()) cctype
错误输入时舍弃
if(cin.fail() && !cin.eof()) //判断标志位
{
	cin.clear();
	while(!isspace(cin.get()))
	{
		continue;
	}
}else
{
	cout<<"other error";
	exit(1)
}
*************************/

#include <iostream>
#include <exception> //TODO

int main()
{
	using namespace std;

	cin.exceptions(ios_base::failbit); //总共三个标志为，默认为goodbit

	cout<<"Enter number:";
	int sum =0;
	int in;
	try
	{
		while(cin>>in)
		{
			sum+=in;
		}
	}catch(ios_base::failure &bf)
	{
		cout<<bf.what()<<endl;
		cout<<"O! the horror! \n";
	}

	cout<<"Last value Enter= "<<in<<endl;
	cout<<"sum="<<sum<<endl;
	return 0;
}