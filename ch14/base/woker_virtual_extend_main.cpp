#include <iostream>
#include <cstring>
#include "woker_virtual_extend.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker *lolas[SIZE];
	int ct;
	for(ct =0; ct<SIZE; ct++)
	{
		char choice;
		cout<<"Enter the employee category: \n"
			<<"\t w: waiter    s:singer \n"
			<<"\t t:singing waiter q:quit\n";
		cin>>choice;
		while(strchr("wstq",choice) == NULL) //TODO strchr
		{
			cout<<"Please enter a w, s ,t or q:";
			cin>>choice;
		}

		if(choice == 'q')
			break;
 
		switch(choice)
		{
			case 'w':	lolas[ct] = new Waiter;
						break;
			case 's':   lolas[ct] = new Singer;
						break;
			case 't':	lolas[ct] = new SingingWaiter;
						break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout<<"\n Here is your staff: \n";
	for(int i=0;i<ct;i++)
	{
		cout<<endl;
		lolas[i]->Show();
	}
	for(int i=0;i<ct;i++)
	{
		delete lolas[i];
	}
	cout<<"Bye. \n";
	return 0;
}