#include <iostream>
#include <string>
using namespace std;


string ToUpper(string & s);

int main()
{
	string s{"abc123XYZ78an"};
	cout<<ToUpper(s)<<endl;
	return 0;
}

string ToUpper(string & s)
{
	string temp =s;
	for(int i=0;i<s.length(); i++)
	{
		if(temp[i] >= 'a' && temp[i] <= 'z')
		{
			temp[i] = std::toupper(temp[i]);
		}
	}
	return temp;
}