
#include <iostream>
using namespace std;

struct CandyBay {
	string brand;
	float weight;
	int calories;
};

int main(void )
{
	CandyBay candyBayArray [3] =  {
		{"Mocha Munch0", 2.30, 350},
		{"Mocha Munch1", 2.31, 350},
		{"Mocha Munch2", 2.32, 350}
	};
	for(int i=0;i<3;i++)
	{
		cout<<"candyBayArray ["<<i <<"]:"<<candyBayArray[i].brand<<", "<<candyBayArray[i].weight<<", "<<candyBayArray[i].calories<<endl;
	}
	return 0;
}