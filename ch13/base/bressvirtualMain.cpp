#include <iostream>
#include <string>
#include "bress.h"
const int CLIENTS = 4;

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass * p_client[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for(int i =0 ;i <CLIENTS; i++)
	{
		cout<<"Enter client's name:";
		getline(cin, temp);
		cout<<"Enter client account num:";
		cin>>tempnum;
		cout<<"Enter opening balance: $";
		cin>>tempbal;
		cout<<"Enter 1 for Brass Account or"
			<<"2 for BrassPlus Account:";
		while(cin>>kind && (kind !='1'&&kind!='2')) //TODO 输入1或2
			cout<<"Enter 1 or 2:";
		// cin.get();
		if(kind == '1')
		{
			p_client[i] = new Brass(temp, tempnum, tempbal);
		}
		else
		{
			double tmax, trate;
			cout<<"enter the overdraft limit :$";
			cin>>tmax;
			cout<<"Enter ther interest rate"
				<<"as a decimal fraction:";
			cin>>trate;
			p_client[i] = new BrassPlus(temp, tempnum, tempbal,tmax, trate);
		}
		while(cin.get() != '\n') //TODO 有换行结束
			continue;
	}
	cout<<endl;
	for(int i =0 ;i <CLIENTS; i++)
	{
		p_client[i]->ViewAcct();
		cout<<endl;
	}

	for(int i =0 ;i <CLIENTS; i++)
	{
		delete p_client[i];
		
	}
	cout<<"Done \n";

	return 0;
}