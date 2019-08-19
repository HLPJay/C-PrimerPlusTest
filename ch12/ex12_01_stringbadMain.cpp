#include <iostream>
#include "ex12_stringbad.h"

using std::cout;

void callme1(StringBad & rsb);
void callme2(StringBad sb);

int main()
{
	using std::endl;
	{
		cout<<"Start an inner block:"<<endl;
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuc Prey");
		StringBad sports("Spinach Leavs Bowl for Dollars");
		cout<<"headline1:"<<headline1<<endl;
		cout<<"headline2:"<<headline2<<endl;
		cout<<"sports:"<<sports<<endl;
		callme1(headline1);
		cout<<"headline1:"<<headline1<<endl;
		callme2(headline2); //TODO 同一个地址，进去已经释放了
		cout<<"headline2:"<<headline2<<endl; //获取异常，计数异常
		StringBad sailor = sports;
		cout<<"sailor:"<<sailor<<endl;
		StringBad knot;
		knot = headline1;
		cout<<"knot:"<<knot<<endl;
	}
	cout<<"Done \n";
}

void callme1(StringBad & rsb)
{
	cout<<"callme1:"<<rsb<<std::endl;
}
void callme2(StringBad sb)
{
	cout<<"callme2:"<<sb<<std::endl;
}