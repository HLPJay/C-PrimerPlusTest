
#include <iostream>
using namespace std;

#include <cstring>

struct stringy{
	char *str;
	int ct;
};

void set(stringy& stry, char *str);
void show(const stringy & str, int n = 1);
void show(const string & str, int n = 1);
int main(void)
{
	stringy beany;
	char test[] = "Reality isn‘t what is used to be.";
	set(beany, test);
	cout<<"show(beany):\n";
	show(beany);
	cout<<"show(beany,2):\n";
	show(beany,2);

	test[0] = 'D';
	test[0] = 'u';
	cout<<"show(test):\n";
	show(test);
	cout<<"show(test,3):\n";
	show(test,3);
	show("Done!");
	if(beany.str!=nullptr)
	{
		delete []beany.str;
		beany.str = nullptr;
	}
	return 0;
}

void set(stringy& stry, char *str)
{
	int len = strlen(str);
	stry.str = new char [len];
	strcpy(stry.str, str);
	stry.ct = len;
	return;
}

void show(const stringy & str, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<str.str<<endl;
	}
}

void show(const string & str, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<str<<endl;
	}
}