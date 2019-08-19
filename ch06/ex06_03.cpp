/*************************
模型：菜单雏形
输入：输入标志
输出：有误重新输入，否则根据菜单进行打印
*************************/

#include <iostream>
using namespace std;

int main(void)
{
	cout<<"Please enter one of the following choices:"<<endl;
	cout<<"c> carnivore "<<endl;
	cout<<"p> pianist "<<endl;
	cout<<"t> tree "<<endl;
	cout<<"g> game "<<endl;

	char ch;
	while(cin>>ch)
	{
		if(ch == 'c'||ch == 'p'||ch == 't'||ch =='g')
		{
			break;
		}
		cout<<"Please enter a c, p, t or g:"; 
	}

	switch(ch)
	{
		case 'c': cout<<"A maple is a carnivore"<<endl; break;
		case 'p': cout<<"A maple is a pianist"<<endl; break;
		case 't': cout<<"A maple is a tree"<<endl; break;
		case 'g': cout<<"A maple is a game"<<endl; break;
		default : break;
	}
	

	return 0;
}