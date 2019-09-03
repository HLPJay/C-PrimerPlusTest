/***************************
对数组进行排序，删除重复的值，返回缩减后的元素的个数

****************************/
#include <iostream>
#include <cmath>  //TODO
#include <algorithm>  //TODO

int reduce(long ar[], int n);

int main(void)
{
	long arr[10] = {12, 12, 5, 6, 11, 5, 6, 77, 11, 12};
	int size = reduce(arr, 10);
	for(int i =0; i<size; i++)
	{
		std::cout<<i<<"   :"<<arr[i]<<std::endl;
	}
	return 0;
}

int reduce(long ar[], int n)
{
	//unique() 删除重复元素
	std::sort(ar, ar+n);
	long* end = std::unique(ar, ar+n); //TODO 返回末尾元素
	return end - ar;
}