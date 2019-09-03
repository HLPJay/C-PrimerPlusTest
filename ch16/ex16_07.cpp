/***************************
彩票卡游戏 代编号的圆点
	圆点的个数  随机选择的圆点的个数
****************************/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

vector<int> Lotto(int all, int num);

int main()
{
	vector<int> result;
	result = Lotto(51, 6);
	for(int i=0; i<6; i++)
	{
		std::cout<<"i :"<<result[i]<<std::endl;
	}
	return 0;
}

vector<int> Lotto(int all, int num)
{
	vector<int> v;
	for(int i=0; i<all; i++)
	{
		v.push_back(i); //TODO vector
	}
//TODO random_device mt19937 shuffle
	std::random_device rd;
    std::mt19937 g(rd());
 	
 	std::shuffle(v.begin(), v.end(), g);
 	vector<int> result(v.begin(), v.begin()+num);
 	return result;
}