/**********************************
输入：(品牌，重量，卡路里)
输出：

**********************************/

#include <iostream>

int main(void)
{
	using namespace std;
	struct CandyBay {
		string brand;
		float weight;
		int calories;
	};
	CandyBay snack = {"Mocha Munch", 2.3, 350};
	cout<<"CandyBay:"<<snack.brand<<" , "<<snack.weight<<" , "<<snack.calories<<endl;
	return 0;
}