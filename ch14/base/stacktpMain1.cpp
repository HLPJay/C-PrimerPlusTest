/*****************************
使用rand() srand() 和 time() 生成随机数0或者1，模拟硬币
*****************************/

#include <iostream>
#include <cstdlib> //srand() rand()
#include <ctime>
#include "stacktp1.h"
const int Num =10;

int main(void)
{
	std::srand(std::time(0));
	std::cout<<"Please enter stack size:";
	int stacksize;
	std::cin>>stacksize;
	Stack<const char *> st(stacksize); //TODO  char*存的是地址吧
	const char* in[Num] = {
		"1:Hank Gilgamesh", "2:Kiki Ishtar",
		"3:Betty Rocker", "4:Ian Flagranti",
		"5:WolfGang Kibble", "6:Protia Koop",
		"7:Joy Almondo", "8:Xaverue Paprika",
		"9:Juan Moore", "10:Misha Mache"
	};
	const char* out[Num];
	int proccessed = 0;
	int nextin = 0;
	while(proccessed<Num)
	{	
		if(st.isempty())
		{
			st.push(in[nextin++]);
			// std::cout<<"isempty :"<<nextin<<std::endl;
		}
		else if(st.isfull())
		{
			st.pop(out[proccessed++]);
		}
		else if(std::rand()%2 && nextin <Num)
		{
			st.push(in[nextin++]);
			// std::cout<<"rand :"<<nextin<<std::endl;
		}
		else
			st.pop(out[proccessed++]);
	}

	for(int i=0;i<Num;i++)
		std::cout<<out[i]<<std::endl;
	// std::cout<<"isempty():"<<st.isempty()<<std::endl;
	std::cout<<"Bye \n";
	return 0;
}