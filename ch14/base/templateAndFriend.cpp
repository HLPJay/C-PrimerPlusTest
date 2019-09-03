/********************************8
模板类和友元
模板类的非模板友元函数
*********************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& t):item(t) {ct++;}
	HasFriend() { ct--;}
	friend void counts() ;
	friend void report(HasFriend<T> &);
};

template <typename T>
int HasFriend<T>::ct = 0; //TODO 要带类型

//TODO   友元函数的访问方式
void counts()
{
	cout<<"int count:"<<HasFriend<int>::ct<<endl;
	cout<<"double count:"<<HasFriend<double>::ct<<endl;
}

void report(HasFriend<int> &t)
{
	cout<<"HasFriend<int>:"<<t.item<<endl;
}

void report(HasFriend<double> &t)
{
	cout<<"HasFriend<double>:"<<t.item<<endl;
}

int main()
{
	cout<<"No object declared:";
	counts(); //友元函数
	HasFriend<int> hfi1(10);
	cout<<"After hfi1 declared:";
	counts(); 

	HasFriend<int> hfi2(20);
	cout<<"After hfi2 declared:";
	counts(); 

	HasFriend<double> hfi3(20.5);
	cout<<"After hfi2 declared:";
	counts(); 

	report(hfi1);
	report(hfi2);
	report(hfi3);
	return 0;
}
