/*************************************
创建一个queueQt并用worker队列测试

*************************************/

#include <iostream>
#include <cstring>
#include "./base/woker_virtual_extend.h"
// #include "ex14_03_queue.h"
#include "ex14_03_queue_good.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	// using std::strchr;


	queueTp<int> lolasQueueInt;

	int ct;
	for(ct =0; ct<SIZE; ct++)
	{
		lolasQueueInt.push(ct);
	}

	int i;
	for(ct =0; ct<SIZE; ct++)
	{
		lolasQueueInt.pop(i);
		std::cout<<i<<std::endl;
	}
	queueTp<Worker *> lolasQueueTp;

	
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
 		
 		Worker *lolas;
		switch(choice)
		{
			case 'w':	lolas = new Waiter;
						break;
			case 's':   lolas = new Singer;
						break;
			case 't':	lolas= new SingingWaiter;
						break;
		}
		cin.get();
		lolas->Set();
		lolasQueueTp.push(lolas);
	}

	cout<<"\n Here is your staff: \n";

	while(!lolasQueueTp.isempty())
	{
		Worker *lolas;
		lolasQueueTp.pop(lolas);
		lolas->Show();
		delete lolas;
	}
	cout<<"Bye. \n";
	return 0;
}