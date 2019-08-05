/******************************************
输入 :char数组和循环每次读入一个单词 直到用户输入down为止，指出输入多少个
*******************************************/

#include <iostream>
#include <cstring>
using namespace std;


const int number = 100;
int main(void)
{
	cout<<"please input world, stop with done:"<< endl;
	char word[number];
	cin>>word;
	int num = 0;
	while(strcmp(word, "done"))
	{
		num++;
		cin>>word;
	}
	cout << "you have enter a total of "<< num<<" word."<<endl;
	return 0;
}