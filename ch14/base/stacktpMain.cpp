#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Stack<std::string> st;   //TODO   如果用指针char*测试
	char ch;
	std::string po;
	cout<<"Please enter A to add a purchase order, \n"
		<<"P to process a PO or Q to Quit."<<endl;

	while(cin>>ch && std::toupper(ch)!='Q')
	{
		while(cin.get()!='\n')
			continue;
		if(!std::isalpha(ch))
		{
			cout<<"\a";
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':
				cout<<"Enter a PO number to add";
				cin>>po;
				if(st.isfull())
				{
					cout<<"stack has alreadly full"<<endl;
				}
				else
					st.push(po);
				break;
			case 'p':
			case 'P':
				if(st.isempty())
					cout<<"stack alreadly empty."<<endl;
				else
				{
					st.pop(po);
					cout<<"PO #"<<po<<" popped \n";
					break;
				}

		}
		cout<<"Please enter A to add a purchase order, \n"
		<<"P to process a PO or Q to Quit."<<endl;
	}
	cout<<"Done. \n";
	return 0;
}