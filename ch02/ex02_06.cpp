#include <iostream>

using namespace std;
//使用double进行存储

int main()
{
	cout<<"Enter the number of the light year:";
	double lightYear;
	cin>>lightYear;
	double GetAstronomicalUnits(double ligtYear);
	cout<<lightYear<<" light year = "<<GetAstronomicalUnits(lightYear)<<" astronomical units"<<endl;
	return 0;
}

double GetAstronomicalUnits(double ligtYear)
{
	return 63240*ligtYear;
}
