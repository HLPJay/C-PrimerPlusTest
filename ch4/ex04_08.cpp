/******************
输入：公司，披萨的直径，披萨的重量。
输出：显示这些信息,
用new的方式

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
	Pizza *pizza = new(std::nothrow) Pizza;
	if(pizza == nullptr)
	{
		return 1;
	}

	cout<<"please enter the diameter of Pizza:";
	cin>>pizza->diameter;
	cin.get();
	cout<<"please enter the company of Pizza:";
	getline(cin, pizza->company);
	cout<<"please enter the weight of Pizza:";
	cin>>pizza->weight;

	cout<<"The company of Pizza:"<<pizza->company<<endl;
	cout<<"The diameter of Pizza:"<<pizza->diameter<<endl;
	cout<<"The weight of Pizza:"<<(*pizza).weight<<endl;

	delete pizza;
	pizza = nullptr;
	return 0;

}