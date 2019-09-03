/***************************
对数组进行排序，删除重复的值，返回缩减后的元素的个数

模板函数
****************************/
#include <iostream>
#include <cmath>  //TODO
#include <algorithm>  //TODO
#include <string>

template <class T>
int reduce(T ar[], int n);

int main(void)
{
	long arr[10] = {12, 12, 5, 6, 11, 5, 6, 77, 11, 12};
	int size = reduce<long>(arr, 10);
	for(int i =0; i<size; i++)
	{
		std::cout<<i<<"   :"<<arr[i]<<std::endl;
	}

	std::string str[10] = {"yy", "tt", "uu", "aa", "yy", 
							"yy", "tt",  "tt", "aa", "ii"};
	size = reduce<std::string>(str, 10);
	for(int i =0; i<size; i++)
	{
		std::cout<<i<<"   :"<<str[i]<<std::endl;
	}
	return 0;
}

template <class T>
int reduce(T ar[], int n)
{
	//unique() 删除重复元素
	std::sort(ar, ar+n);
	auto end = std::unique(ar, ar+n); //TODO 返回末尾元素
	return end - ar;
}