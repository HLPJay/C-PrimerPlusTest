/*************************
put()用以显示字符  输出一个字符，或者写入文件
write()用以显示字符串  输出 无格式输出函数,第一个参数是指针第二个参数是显示字符的个数
*************************/

#include <iostream>
#include <cstring>

int main()
{
	using std::cout;
	using std::endl;

	char ch = 'A';
	cout.put(ch);

	const char* state1 = "Florida";
	const char* state2 = "kansas";
	const char* state3 = "Euphoria";

	int i;
	for(i=1;i<std::strlen(state2);i++)
	{
		cout.write(state2, i)<<endl;
	}
	cout<<"*******************************"<<endl;
	for(i=std::strlen(state2); i>0; i--)
	{
		cout.write(state2, i)<<endl;
	}

	cout<<"验证：";
	cout.write(state2, std::strlen(state2)+5)<<endl;
	return 0;
}