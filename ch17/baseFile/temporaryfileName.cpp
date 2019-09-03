/****************************
char* tmpnam(char * pszName)  指定独一无二的文件名 创建临时文件
两个常量 L_tmpnam 和TMP_MAX
TMP_MAX个文件名
文件名长度不超过L_tmpnam
****************************/

#include <cstdio>
#include <iostream>

int main()
{
	using namespace std;
	cout<<"this system can generate up to"<<TMP_MAX
		<<"temporary names of up to"<<L_tmpnam<<" characters. \n";
	char pszName[ L_tmpnam] = {'\0'};
	cout<<"Here are ten names: \n";
	for(int i=0;i<10;i++)
	{
		tmpnam(pszName);
		cout<<pszName<<endl;
	}
	return 0;
}