#include <iostream>
#include <cstring>
using namespace std;

class BatelgeuseanPlorg
{
private:
	char name[19];
	int CI;
public:
	BatelgeuseanPlorg();
	BatelgeuseanPlorg(char * name);
	void ResetCi(int ci);
	void ShowBatelgeuseanPlorg();
};

BatelgeuseanPlorg::BatelgeuseanPlorg()
{
	strcpy(name, "Plorga");
	CI = 50;
}

BatelgeuseanPlorg::BatelgeuseanPlorg(char * name)
{
	if(name[0]!='\0')
	{
		strcpy(this->name, name);
	}
	else
	{
		strcpy(this->name, "Plorga");
	}
	CI = 50;
}

void BatelgeuseanPlorg::ResetCi(int ci)
{
	this->CI = ci;
}

void BatelgeuseanPlorg::ShowBatelgeuseanPlorg()
{
	cout<<"name:"<<this->name<<"\t"<<this->CI<<endl;
}

int main(void)
{
	BatelgeuseanPlorg bp;
	bp.ShowBatelgeuseanPlorg();
	char name[] = {"mytest"};
	BatelgeuseanPlorg bp1(name);
	bp1.ShowBatelgeuseanPlorg();
	bp1.ResetCi(22);
	bp1.ShowBatelgeuseanPlorg();
	return 0;
}