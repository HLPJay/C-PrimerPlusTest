/****************************
最多十个高尔夫成绩，使用数组存储，用三个函数实现输入，显示，和求平均值
****************************/
//TODO：求数组实际大小
#include <iostream>
// #include <array>
using namespace std;

const int size = 10;
void setGrade(int grades[],int size);
void showGrade(int grades[],int size);
void getAvg(int grades[],int size);

int main(void)
{
	// array<int,size> gradeArray;
	int grades[size];
	setGrade(grades, size);
	showGrade(grades, size);
	getAvg(grades, size);
	return 0;
}

void setGrade(int grades[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<"number of "<<i<<" grade:";
		cin>>grades[i];
	}
}

void showGrade(int grades[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<"number of "<<i<<" grade:";
		cout<<grades[i]<<"  "<<endl;
	}
	cout<<endl;
}

void getAvg(int grades[],int size)
{
	int sum = 0;
	for(int i=0;i<size;i++)
	{
		sum +=grades[i];
	}
	cout<<"sum: "<<sum<<"    avg:"<<sum/(size*1.0)<<endl;
}