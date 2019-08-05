
#include <iostream>
void OutPutHowManyMice();
void OutPutLook();
int main(void)
{
	OutPutHowManyMice();
	OutPutHowManyMice();
	OutPutLook();
	OutPutLook();
	return 0;
}

void OutPutHowManyMice()
{
	using namespace std;
	cout<<"three blind mice"<<endl;
}

void OutPutLook()
{
	std::cout<<"See how they run"<<std::endl;
}