/********************************8
模板类和友元
TODO::模板类的非约束模板友元函数
每个函数的具体化都是每个类的具体化的友元。
*********************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i):item(i) {}
	template <typename C, typename D> friend void show2(C &, D &);
};

template <typename C, typename D> void show2(C & c, D & d)
{
	cout<<c.item<<", "<<d.item<<endl;
}
int main()
{
	ManyFriend<int> hfi0(10);
	ManyFriend<int> hfi1(20);
	ManyFriend<double> hfi2(10.5);
	cout<<"hfi0 hfi1:";
	show2(hfi0, hfi1);
	cout<<"hfi2 hfi1:";
	show2(hfi2, hfi1);
	return 0;
}