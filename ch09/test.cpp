/********************************************
newplace.cpp :常规new和定位new运算符的示例代码：

********************************************/


#include <iostream>
#include <new>
using namespace std;

const int BUF = 512;
const int N = 5;

char buffer[BUF];

int main(void)
{
	double *pd1, *pd2;
	int i;
	cout<<"test of new:"<<endl;

	pd1 = new  double [N];
	pd2 = new (buffer) double[N];

	for(i=0;i<N;i++)
	{
		pd2[i] = pd1[i] = 1000+20.0*i;
	}

	cout<<"momory address of heap:"<<pd1<<endl;
	cout<<"momory address of static buffer:"<<pd2<<endl;

	for(i=0;i<N;i++)
	{
		cout<<pd1[i] <<" at :"<<&pd1[i]<<"     ";
		cout<<pd2[i] <<" at :"<<&pd2[i]<<endl;
	}
	

	double *pd3, *pd4;
	pd3 = new  double [N];
	pd4 = new (buffer) double[N];

	for(i=0;i<N;i++)
	{
		pd4[i] = pd3[i] = 1000+20.0*i;
	}

	cout<<"momory address of heap:"<<pd3<<endl;
	cout<<"momory address of static buffer:"<<pd4<<endl;  //相同的地址

	for(i=0;i<N;i++)
	{
		cout<<pd3[i] <<" at :"<<&pd3[i]<<"     ";
		cout<<pd4[i] <<" at :"<<&pd4[i]<<endl;
	}

	delete [] pd1;
	delete [] pd3;


	pd1 = new  double [N];
	pd2 = new (buffer+N*sizeof(double)) double[N];

	for(i=0;i<N;i++)
	{
		pd1[i] = pd2[i] = 1000+20.0*i;
	}

	cout<<"momory address of heap:"<<pd1<<endl;
	cout<<"momory address of static buffer:"<<pd2<<endl;  //相同的地址加偏移位

	for(i=0;i<N;i++)
	{
		cout<<pd1[i] <<" at :"<<&pd1[i]<<"     ";
		cout<<pd2[i] <<" at :"<<&pd2[i]<<endl;
	}

	double *doubleOfbuffer;
	doubleOfbuffer = (double *)buffer;//把内存强转为对应类型去提取数据
	double *doubleOfbuffer1;
	doubleOfbuffer1 = (double *)(buffer+N*sizeof(double));
	cout<<"doubleOfbuffer:"<<*doubleOfbuffer<<endl;
	cout<<"doubleOfbuffer1:"<<*doubleOfbuffer1<<endl;
	cout<<"pd2:"<<*pd2<<endl;
	delete [] pd1;
	return 0;
}