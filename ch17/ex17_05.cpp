/******************************
两个文件 分别存储着姓名，每行存储一个名字
			存储在容器中，按顺序显示
合并容器内容，删除重复的，存储在第三个个文件中
******************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const string filename = "mat.dat";
const string filename1 = "pat.dat";
const string filenameAll = "matnpat.dat";

int main()
{

	// ifstream fin2(filename1.c_str(), ios_base::in);
	// if(!fin2.is_open())
	// {
	// 	cerr<<"Can't not open "<<filename1<<" for output\n";
	// 	exit(EXIT_FAILURE);
	// }

	// string ss;
	// while(!fin2.eof())
	// {
	// 	getline(fin2, ss,'\n');
	// 	cout<<"ss:"<<ss<<endl;
	// }
	// fin2.close();

	//写入第一个文件
	ofstream fout(filename, ios_base::out);//打开文件  | ios_base::app| ios_base::binary 输入 以二进制追加
	if(!fout.is_open())
	{
		
		cerr<<"Can't not open "<<filename<<" for output\n";
		exit(EXIT_FAILURE);
	}

	fout<<"friend one"<<"\n";
	fout<<"friend two"<<"\n";
	fout<<"friend three one"<<"\n";
	fout<<"friend four test 123"<<"\n";
	fout<<"friend five";
	fout.close();
	//写入第二个文件

	ofstream fout1(filename1, ios_base::out);//| ios_base::app| ios_base::binary打开文件   输入 以二进制追加
	if(!fout1.is_open())
	{
		cerr<<"Can't not open "<<filename1<<" for output\n";
		exit(EXIT_FAILURE);
	}

	fout1<<"friend one 2"<<"\n";
	fout1<<"friend two"<<"\n";
	fout1<<"friend three one"<<"\n";
	fout1<<"friend four test 123 2"<<"\n";
	fout1<<"friend five";
	fout1.close();// 文件分析  这里没有正常关闭  导致后面的fin1不能正常读取


	vector<string> nameOfVectorOne;
	vector<string> nameOfVectorTwo;
	
	ifstream fin(filename.c_str(), ios_base::in);
	ifstream fin1(filename1.c_str(), ios_base::in);
	if(!fin.is_open()|| !fin1.is_open())
	{
		cerr<<"Can't not open "<<filename <<"or"<< filename1<<" for output\n";
		exit(EXIT_FAILURE);
	}
	//读取文件1 并写入容器中 并按顺序打印

	string temp;
	while(!fin.eof())
	{
		// fin>>temp;
		getline(fin, temp, '\n');
		nameOfVectorOne.push_back(temp);
	}
	fin.close();

	//读取文件2 并写入容器中
	while(!fin1.eof())
	{
		// fin1>>temp;
		getline(fin1, temp, '\n');
		nameOfVectorTwo.push_back(temp);
	}
	fin1.close();
	
	cout<<"name of one:"<<endl;
	vector<string>::iterator itr;
	for(itr = nameOfVectorOne.begin(); itr!= nameOfVectorOne.end();itr++)
	{
		cout<<*itr<<endl;
	}

	cout<<"name of two:"<<endl;
	for(itr = nameOfVectorTwo.begin(); itr!= nameOfVectorTwo.end();itr++)
	{
		cout<<*itr<<endl;
	}

	set<string> nameOfSetAll;
	nameOfSetAll.insert(nameOfVectorOne.begin(),nameOfVectorOne.end());
	nameOfSetAll.insert(nameOfVectorTwo.begin(),nameOfVectorTwo.end());

	int i=0;
	for(auto it = nameOfSetAll.begin(); it!= nameOfSetAll.end(); it++)
	{
		cout<<i++<<" "<<*it<<endl;
	}

	ofstream fout2(filenameAll, ios_base::out);//打开文件  | ios_base::app| ios_base::binary 输入 以二进制追加
	if(!fout2.is_open())
	{
		cerr<<"Can't not open "<<filenameAll<<" for output\n";
		exit(EXIT_FAILURE);
	}
	for(auto it = nameOfSetAll.begin(); it!= nameOfSetAll.end(); it++)
	{
		fout2<<*it<<'\n';
	}
	fout2.close();
	return 0;
}