
#include <iostream>
#include <string>
#include "templateQueueTp.h"

using namespace std;
int main(void)
{
	QueueTp<string> cs(5);

	string temp;
	while(!cs.isfull())
	{
		cout<<"Please enter your name. you will be "
		      "server in the order of arrival \n"
		      "name :";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout<<"The queue is full Process begin: \n";
	while(!cs.isempty())
	{
		cs.dequeue(temp);
		cout<<"Now processing "<<temp<<"...\n";
	}
	return 0;
}