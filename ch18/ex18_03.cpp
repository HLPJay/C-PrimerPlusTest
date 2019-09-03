#include <iostream>
//TODO 可变参数模板 https://www.cnblogs.com/qicosmos/p/4325949.html
using namespace std; 

template <typename T>
T sum_value(T t)
{
	return t;
}

template <typename T, typename ... Args>
long double sum_value(T first, Args... args) //其实是第归调用
{

	return  first +sum_value<long double>(args...);
};

int main()
{
	cout<<"sum = "<<sum_value(1,2,3,4)<<endl;
	cout<<"sum = "<<sum_value(1,2.1,3,4)<<endl;
	return 0;
}
