#include <iostream>
#include "ex12_04_stack.h"
using namespace std;

int main(void)
{
	Stack stck(5);
	cout<<"isempty:"<<stck.isempty()<<endl;
	cout<<"isfull:"<<stck.isfull()<<endl;
	// Item db [] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	Item db [] = {1, 2, 3, 4, 5, 6};
	for(int i =0 ;i<sizeof(db)/sizeof(Item);i++)
	{
		if(stck.push(db[i]))
		{
			cout<<"success of "<<i <<"  is "<<db[i]<<endl;
		}
		else
		{
			cout<<"fail of "<<i <<"  is "<<db[i]<<endl;
		}
	}
	stck.show();

	Stack stck1(stck);
	cout<<"isfull:"<<stck1.isfull()<<endl;

	Stack stck2;
	stck2 = stck1;
	cout<<"isfull:"<<stck2.isfull()<<endl;

	Item it;
	for(int i=0;i<5;i++)
	{
		stck2.pop(it);
		cout<<"pop of "<<i<<" is "<<it<<endl;
	}
	cout<<"isempty:"<<stck2.isempty()<<endl;
	return 0;
}