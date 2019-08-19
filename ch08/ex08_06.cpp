/***************************************
模板函数 maxn()  一个数组和一个长度 返回数组中最大元素

***************************************/

template <class T1, class T2>
auto maxn(T1 *myArray, T2 size) ->T1;

template <> char* maxn(char **arr, int n);

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int testInt [] = {1,2,3};
	double testDouble [] = {1.1, 2.2, 3.3, 4.4, 5.5};
	cout<<"int max:"<<maxn(testInt, 3)<<endl;
	cout<<"double max:"<<maxn(testDouble, 5)<<endl;

	char * str[] = {"mytest", "myarray", "mystring", "mystrinp"};
	cout<<"char** max length string:"<<maxn(str,4)<<endl;
	cout<<"char** max length address:"<<maxn(str,4)<<endl;
	return 0;
}

template <class T1, class T2>
auto maxn(T1 *myArray, T2 size) ->T1
{
	T1 temp;
	temp = myArray[0];
	for(int i=0;i<size;i++)
	{
		if(temp<myArray[i])
		{
			temp = myArray[i];
		}
	}
	return temp;
}

template <> char* maxn(char **arr, int n)
{
	int maxLen = strlen(arr[0]);
	int tempLen;
	int Subscript;

	for(int i =0; i<n;i++)
	{
		tempLen = strlen(arr[i]);
		if(tempLen > maxLen)
		{
			maxLen = tempLen;
			Subscript = i;
		}
	}
	return arr[Subscript];
};
