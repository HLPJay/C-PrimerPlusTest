/*******************************************
9.1改为对应的类实现的方式
*******************************************/


#ifndef  EX09_01GOLF_H_
#define  EX09_01GOLF_H_

#include <iostream>
#include <cstring>
using namespace std;


namespace EX0_03{
	class Golf
	{
		static const int Len = 40;
	private:
		char fullname[Len];
		int handicap;
	public:
		Golf(const char* name, int hc);
		Golf();
		const Golf &setgolf(const char* name, int hc);
		void showgolf();
	};


	Golf::Golf(const char* name, int hc)
	{
		strcpy(this->fullname, name);
		this->handicap = hc;
	}

	Golf::Golf()
	{
		fullname[0]= '\0';
		handicap = 0;
	}

	const Golf & Golf::setgolf(const char* name, int hc)
	{
		Golf gf = Golf(name, hc);
		*this = gf; //默认赋值构造函数
		return *this;
	}

	void Golf::showgolf()
	{
		cout<<"golf fullname: "<< this->fullname<<endl;
		cout<<"golf handicap: "<< this->handicap<<endl;
	}
}

int main(void)
{
	using namespace EX0_03;
	char name [40] = "mytest of name";
	int num = 2;
	Golf golftest(name, num);
	golftest.showgolf();

	Golf golftest1;  //TODO ：构造函数  默认构造函数  构造函数的各种方式  以及赋值构造函数
	golftest1.showgolf();

	Golf golftest2 = golftest1.setgolf(name, num);
	golftest2.showgolf();
	return 0;
}

#endif
