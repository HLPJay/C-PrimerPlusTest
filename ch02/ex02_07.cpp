#include <iostream>
using namespace std;
void OutPutTime(int hours, int minutes);

int main()
{
	int hours,minutes;
	cout<<"Enter ther number of hours:";
	cin >> hours;
	cout<<"Enter the number of minutes:";
	cin >> minutes;
	OutPutTime(hours, minutes);
	return 0;
}

void OutPutTime(int hours, int minutes)
{

	cout<<"Timers: "<<hours<<":"<<minutes<<endl;
	return;
}