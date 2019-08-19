/***************************************
模板函数 max5()  返回数组中最大元素
***************************************/

const int arSize = 5;

template <class T>
T max5(T myArray [])
{
	T temp;
	temp = myArray[0];
	for(int i=0;i<arSize;i++)
	{
		if(temp<myArray[i])
		{
			temp = myArray[i];
		}
	}
	return temp;
}


#include <iostream>
using namespace std;

int main(void)
{
	int testInt [] ={1,2,3,4,5};
	double testDouble [] = {1.1, 2.2, 3.3, 4.4, 5.5};
	cout<<"int max:"<<max5(testInt)<<endl;
	cout<<"double max:"<<max5(testDouble)<<endl;
	return 0;
}