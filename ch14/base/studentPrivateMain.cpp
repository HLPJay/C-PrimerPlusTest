#include <iostream>
#include "studentPrivate.h"

using std::cout;
using std::cin;
using std::endl;

void set(Student &sa, int n);
const int pupils = 3;
const int quizzes = 5;
int main()
{
	Student ada[pupils] = {Student(quizzes),Student(quizzes),Student(quizzes)};
	for(int i = 0; i<pupils;++i)
	{
		set(ada[i] ,quizzes);
	}

	cout<<"\n Student List: \n";
	for(int i = 0; i<pupils;++i)
	{
		cout<<endl<<ada[i];
		cout<<"average ----->:"<<ada[i].Average() <<endl;
	}
	cout<<"Done \n";

	return 0;
}


void set(Student &sa, int n)
{
	cout<<"Please input student name:";
	getline(cin, sa);
	cout<<"Please input "<<n<<"  quiz scores \n";
	for(int i=0;i<n;i++)
		cin>>sa[i];
	while(cin.get() != '\n')
		continue;
}