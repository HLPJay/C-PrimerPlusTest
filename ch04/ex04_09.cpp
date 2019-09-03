/******************
4.6的内容，用new的方式实现


******************/
#include <iostream>
using namespace std;

struct CandyBay {
	string brand;
	float weight;
	int calories;
};

int main(void )
{
	CandyBay *candyBayArray = new(std::nothrow) CandyBay[3];
	if(candyBayArray == nullptr)
	{
		return 1;
	}

	candyBayArray[0] = {"Mocha Munch0", 2.30, 350};
	candyBayArray[1] = {"Mocha Munch1", 2.31, 350};
	candyBayArray[2] = {"Mocha Munch2", 2.32, 350};

	for(int i=0;i<3;i++)
	{
		cout<<"candyBayArray ["<<i <<"]:"<<candyBayArray->brand<<", "<<candyBayArray->weight<<", "<<candyBayArray->calories<<endl;
		candyBayArray++;
	}
	return 0;
}