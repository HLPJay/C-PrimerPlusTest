/*************************


**************************/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string firstName,lastName;
	char grade;
	int age;
	cout<<"What is your first name:";
	getline(cin,firstName); //TODO:getline的用法，string和char数组的差异
	cout<<"What is your last name:";
	getline(cin,lastName);
	cout<<"What latter grade do you deserve:";
	cin>>grade;
	cout<<"What is your age:";
	cin>>age;

	cout<<"name: "<<lastName<<", "<<firstName<<endl;
	cout<<"Grade: "<<(char)(grade+1)<<endl;
	cout<<"Age: "<<age<<endl;
	return 0;

}