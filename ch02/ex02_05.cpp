#include <iostream>
double GetFahrenheit(double Celsius);

int main()
{
	using namespace std;
	cout<<"Please enter a Celsius value :";
	double CelsiusNum;
	cin>>CelsiusNum;
	cout<<CelsiusNum<<" degress celsius is "<<GetFahrenheit(CelsiusNum)<<" degress Fahrenheit"<<endl;
	return 0;
}

double GetFahrenheit(double Celsius)
{
	return 1.8*Celsius+32.0;
}