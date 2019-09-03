#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>  //TODO
//使用read()和write（）完成
using namespace std;

void ShowStr(const string & str)
{
	std::cout<<str<<"\n";
}

void GetStrs(std::ifstream& fin, vector<string> & vistor);

//函数符，重载()使能像函数那样使用
class Store{
private:
	std::ofstream& os;  //TODO 类对象中传递引用  禁止赋值构造函数
public:
	Store(std::ofstream &fout):os(fout){};
	void operator()(const string & str);
};

void Store::operator()(const string & str)
{
	int len = str.length();
	os.write((char*)&len, sizeof(std::size_t));
	os.write(str.data(), len);
}
int main()
{
	vector<string> vostr;
	string temp;

	cout<<"Enter a string(empty line to quit)";
	while(getline(cin,temp) && temp[0]!='\0')
	{
		vostr.push_back(temp);
	}
	cout<<"Here is your input:"<<endl;
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("string.bat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistor;
	ifstream fin("string.bat", ios_base::in | ios_base::binary);
	if(!fin.is_open())
	{
		cerr<<"Can't not open string.bat for output\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistor);
	cout<<"Here are the string from the file: \n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	return 0;
}


void GetStrs(std::ifstream& fin, vector<string> & vistor)
{
	int len;
	fin.read((char*)&len, sizeof(std::size_t));//TODO size_t
	string temp;
	char ch;
	for(int i=0; i<len; i++)
	{
		fin>>ch;
		temp.push_back(ch);
	}
	vistor.push_back(temp);
}
