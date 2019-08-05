/*******************************************
输入：真实姓名，头衔，秘密姓名，成员偏好。
*******************************************/

#include <iostream>
using namespace std;

const int strSize = 20;
int main(void)
{
	struct BOP {
		char fullname[strSize]; 
		char title[strSize];
		char bopName[strSize];
		int preference;  //0=fullname 1= title 2=bopname
	};

	//定义一个小型数组

	BOP bopInformation[] = {
		{"Wimp Macho","Farmer","bop Wimp",0},
		{"Raki Rhodes","Landlord","bop Raki",1},
		{"Celia Laiter","Chief","bop Celia",1},
		{"Hoppy Hipman","Rich businessman","bop Hoppy",2},
		{"Pat Hand","Farmer","bop Pat",2}
	};
	//设置目录
	cout<<"Benevolent Order of Programmers Report:"<<endl;
	cout<<"a. display by name \t\t"<<"b. display by title"<<endl;
	cout<<"c. display by bopname\t\t"<<"d. display by preference"<<endl;
	cout<<"q. quit"<<endl;

	cout<<"Size:"<< sizeof(bopInformation)/sizeof(bopInformation[0])<<endl;
	cout<<"Enter your choice:";
	char ch;
	cin>>ch;
	while(ch !='q')
	{
		switch(ch)
		{
			case 'a':
				{
					for(int i=0;i<sizeof(bopInformation)/sizeof(bopInformation[0]);i++)
					{
						cout<<bopInformation[i].fullname<<endl;
					}
					break;
				}
			case 'b':
				{
					for(int i=0;i<sizeof(bopInformation)/sizeof(bopInformation[0]);i++)
					{
						cout<<bopInformation[i].title<<endl;
					}
					break;
				}
				
			case 'c':
				{
					for(int i=0;i<sizeof(bopInformation)/sizeof(bopInformation[0]);i++)
					{
						cout<<bopInformation[i].bopName<<endl;
					}
					break;
				}

			case 'd':
				{
					for(int i=0;i<sizeof(bopInformation)/sizeof(bopInformation[0]);i++)
					{
						if(bopInformation[i].preference == 0)
						{
							cout<<" fullname:  "<<bopInformation[i].fullname<<endl;
						}

						if(bopInformation[i].preference == 1)
						{
							cout<<" title:  "<<bopInformation[i].title<<endl;
						}

						if(bopInformation[i].preference == 2)
						{
							cout<<" bopName:  "<<bopInformation[i].bopName<<endl;
						}
					}
					break;
				}
				
			default: 
				cout<<"Pelase Input the a,b,c,d or q:"<<endl; 
				// cout<<"Next Choice:";   //这样子是有问题的，这个分支在a b c d情况下是没法继续下去的，while一直用的第一次的输入
				// cin>>ch;
				break;
		}
		cout<<"Next Choice:";
		cin>>ch;
	}
	cout<<"bye!"<<endl; 

	return 0;
}