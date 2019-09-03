/***************************
要把名字输入在容器中 排序显示  合并
****************************/

#include <iostream>
#include <string>
#include <set>

using namespace std;

void SetName(set<string> & allName);
void ShowName(const set<string> & allName);

int main(void)
{
	set<string> name1;
	SetName(name1);
	ShowName(name1);

	set<string> name2;
	SetName(name2);
	ShowName(name2);

	name1.insert(name2.begin(), name2.end());
	ShowName(name1);
	return 0;
}

void SetName(set<string> & nameList)
{
	string name;
	cout<<"Please Input Name <q to quit>:";
	getline(cin, name);

	while(name != "q")
	{
		nameList.insert(name);
		cout<<"Please Input Name <q to quit>:";
		getline(cin, name);
	}
}

void ShowName(const set<string> & nameList)
{
	set<string>::iterator itr;
	for(itr = nameList.begin(); itr != nameList.end(); itr++)
	{
		cout<<"   :"<<*itr<<endl;
	}
}