/*************************************
BassDMA-LacksDMA-hasDMA 从-个ABC派生而来

*************************************/

#include <iostream>
#include <string>
#include "ex13_03_ABC.h"

const int CLIENTS = 4;

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	ABC * p_client[CLIENTS];
	std::string label;
	int rate;
	char kind;

	for(int i =0 ;i <CLIENTS; i++)
	{
		cout<<"Enter client's label:";
		getline(cin, label);
		cout<<"Enter client account rate:";
		cin>>rate;
		
		cout<<"Enter 1 for ABC Account or"
			<<"2 for BassDMA Account:"
			<<"3 for LacksDMA Account:"
			<<"4 for hasDMA Account:";
		while(cin>>kind && (kind !='1'&&kind!='2'&&kind!='3'&&kind!='4')) //TODO 输入1或2
			cout<<"Enter 1 or 2 or 3 or 4:";
		// cin.get();
		if(kind == '1')
		{
			p_client[i] = new ABC(label.c_str(), rate);
		}
		else if(kind == '2')
		{
			p_client[i] = new BassDMA(label.c_str(), rate);
		}
		else if(kind == '3')
		{
			std::string color;
			cout<<"please input color:";
			// getline(cin, label); //TODO 这里用getline输入的话，会先执行析构函数 再执行输入
			cin>>color;
			p_client[i] = new LacksDMA(color.c_str(),label.c_str(), rate);
		}
		else
		{
			std::string stytle;
			cout<<"please input stytle:";
			// getline(cin, stytle);
			cin>>stytle;
			p_client[i] = new hasDMA(stytle.c_str(),label.c_str(), rate);
		}
		while(cin.get() != '\n') //TODO 有换行结束
			continue;
	}
	cout<<endl;
	for(int i =0 ;i <CLIENTS; i++)
	{
		p_client[i]->View();
		cout<<endl;
	}

	for(int i =0 ;i <CLIENTS; i++)
	{
		delete p_client[i];
		
	}
	cout<<"Done \n";

	return 0;
}