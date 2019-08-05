/******************
输入：公司，披萨的直径，披萨的重量。
输出：显示这些信息

******************/

#include <iostream>

int main(void)
{
	using namespace std;
	struct Pizza{
		string company;
		float diameter;
		float weight;
	}; 
	Pizza pizza;

	cout<<"please enter the company of Pizza:";
	getline(cin, pizza.company);
	cout<<"please enter the diameter of Pizza:";
	cin>>pizza.diameter;
	cout<<"please enter the weight of Pizza:";
	cin>>pizza.weight;

	cout<<"The company of Pizza:"<<pizza.company<<endl;
	cout<<"The diameter of Pizza:"<<pizza.diameter<<endl;
	cout<<"The weight of Pizza:"<<pizza.weight<<endl;
	return 0;

}