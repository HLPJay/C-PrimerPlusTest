
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// const int ArSize = 20;
	// char name[ArSize];
	// char dessert[ArSize];

	// cout<<"Enter your name:\n";
	// cin.getline(name,ArSize); //读取一行
	// cout<<"Enter your favorite dessert:";
	// cin.getline(dessert,ArSize);
	// cout<<"I have some delicious "<<dessert;
	// cout<<" for you, "<<name<<" . "<<endl;


	string name,dessert;
	cout<<"Enter your name:\n";
	getline(cin,name); //读取一行 TODO:了解getline的原型
	cout<<"Enter your favorite dessert:";
	getline(cin,dessert);
	cout<<"I have some delicious "<<dessert;
	cout<<" for you, "<<name<<" . "<<endl;
	return 0;
}