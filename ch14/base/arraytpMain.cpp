#include <iostream>
#include "arraytp.h"

int main(void)
{

	using std::cout;
	using std::endl;
	using std::cin;

	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int , 5>, 10> twodee; //递归使用模板

	int i,j;
	for(i =0; i<10;i++)
	{
		sums[i] = 0;
		for(j =0;j<5;j++)
		{
			twodee[i][j] = (i+1)*(j+1);
			sums[i]+= twodee[i][j];
		}
		aves[i] = (double) sums[i]/10;
	}

	for(i=0; i<10; i++)
	{
		for(j =0;j<5;j++)
		{
			cout.width(2);
			cout<< twodee[i][j]<<" ";
		}
		cout<<": sums =";
		cout.width(3);  //TODO  ??
		cout<< sums[i] <<",averages = "<<aves[i] <<endl;
	}
	cout<< "Done. \n";
	return 0;
}