/****************************
输入：三次40米的成绩
输出：显示次数和平均时间，使用array
（假设成绩以s为单位）
****************************/

#include <iostream>
#include <array>

int main(void)
{
	using namespace std;
	array<int,3> myArray;
	int sum = 0;   //TODO :必须赋初始值
	float averageGrade;
	cout<<"Enter three  grade:";
	for(int i=0;i<3;i++)
	{
		cin>>myArray[i];
		sum+= myArray[i];
	}

	averageGrade = sum/3.0;

	for(int i=0;i<3;i++)
	{
		cout<< " the "<< i << "of grade is "<<myArray[i]<<endl;
	}
	cout<<"averageGrade:"<<averageGrade<<endl;
	return 0;
}