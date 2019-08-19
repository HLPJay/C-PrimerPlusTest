/**********************
将模板用作参数
*********************/

#include <iostream>
#include "stacktp.h"
//template<typename T> class Things
//TODO   将模板用做参数
template <template <typename T> class Things>
class Crab
{
private:
	Things<int> s1;
	Things<double> s2;
public:
	Crab(){};
	bool push(int a,double b) {return s1.push(a) && s2.push(b); }
	bool pop(int &a, double & b) { return s1.pop(a) && s2.pop(b) ;}
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	Crab<Stack> Cr;
	int ni;
	double nb;
	while(cin>>ni>>nb && ni>0&& nb>0)
	{
		if(!Cr.push(ni,nb))
			break;
	}
	while(Cr.pop(ni,nb))
	{
		cout<<ni<<","<<nb<<endl;
	}
	cout<<"Done"<<endl;
	return 0;
}

