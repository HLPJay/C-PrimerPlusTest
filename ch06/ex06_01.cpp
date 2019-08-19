/***********************
输入：一直输入，遇到@为止
输出：显示输入，数字除外，大写转为小写，小写转为大写 ctypes

************************/

#include <iostream>
#include <ctype.h>
using namespace std;

int main(void)
{

	char ch;
	cout<<"Please Input the ch:";
	while((ch = cin.get())!='@')
	{
		if(isupper(ch))
		{
			ch = tolower(ch);
		}else if(islower(ch))
		{
			ch = toupper(ch);
		}

		if(!isdigit(ch))
		{
			cout<<" "<<ch;
		}
	}
	cout<<endl;
	return 0;
}