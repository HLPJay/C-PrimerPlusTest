/**********************
编程6习题，把信息存在文件中，从文件中读取
***********************/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct DonationStruct {
	string peopleName;
	double donationMoney;
};

const string fileName = "donation.txt";
int main(void)
{

	//录入信息
	const int num = 4;
	DonationStruct people[4] = {
		{"Sam Stone",2000},
		{"Freida Flass",100500},
		{"Tammy Tubbs",5000},
		{"Rich Raptor",55000}
	};

	ofstream outFile;
	outFile.open(fileName);
	outFile<<num<<endl;
	for(int i=0;i<num;i++)
	{
		outFile<<people[i].peopleName<<endl;
		outFile<<people[i].donationMoney<<endl;
	}
	outFile.close();

	ifstream inFile;
	inFile.open(fileName);

	if(!inFile.is_open())
	{
		cout<<"can not open this file:"<<fileName<<" ."<<endl;;
		exit(EXIT_FAILURE);
	}
	int fileNum;
	DonationStruct filePeople[4];
	inFile>>fileNum;
	inFile.get();
	for(int i=0;i<fileNum;i++)
	{
		// inFile>>filePeople[i].peopleName; //这个只能读一个单词，要读一整行用getline（）
		// inFile.get();
		getline(inFile, filePeople[i].peopleName);
		inFile>>filePeople[i].donationMoney;
		inFile.get();
	}
	
	cout<<"form file num:"<<fileNum<<endl;
	for(int i=0;i<fileNum;i++)
	{
		cout<<"form file name:"<<filePeople[i].peopleName;
		cout<<" money:"<<filePeople[i].donationMoney<<endl;
	}

	if(inFile.eof())
	{
		cout<<"end of file success."<<endl;
	}else if(inFile.fail())
	{
		cout<<"failed!"<<endl;
	}
	else
	{
		cout<<"other failed!"<<endl;
	}

	cout<<"Grand Patrons:"<<endl;
	int number = 0;
	for(int i=0;i<fileNum;i++)
	{
		if(filePeople[i].donationMoney >10000)
		{
			++number;
			cout<<"Grand Patrons name:"<<filePeople[i].peopleName;
			cout<<"\t\tGrand Patrons money:"<<filePeople[i].donationMoney<<endl;
		}
	}
	if(number == 0 )
	{
		cout<<"\t \t none"<<endl;
	}
	//显示 Patrons
	cout<<" Patrons:"<<endl;
	number = 0;
	for(int i=0;i<fileNum;i++)
	{
		if(filePeople[i].donationMoney <10000)
		{
			++number;
			cout<<"Patrons name:"<<filePeople[i].peopleName;
			cout<<"\t\t Patrons money:"<<filePeople[i].donationMoney<<endl;
		}
	}
	if(number == 0 )
	{
		cout<<"\t \t none"<<endl;
	}

	inFile.close();
	return 0;
}