/*************************
检测每个字符可以用get()

字符串的输入可以用getline()  get() ignore
getline()  抽取并丢弃换界符,默认是换行
get()      输入回车,不会丢弃
ignore()   第一个参数指定要读的数字，第二个参数为分界符
*************************/

#include <iostream>
const int Limit = 255;

int main(void)
{
	using namespace std;

	char input[Limit];
	cin.getline(input, Limit, '#');//丢弃了#
	cout<<"TT:"<<input<<endl;

	char ch;
	cin.get(ch);
	cout<<"ch:"<<ch<<endl;

	if(ch!='\n')
		cin.ignore(Limit, '\n');
	cin.get(input, Limit, '#');
	cout<<"TTT:"<<input<<endl;

	cin.get(ch);
	cout<<"ch:"<<ch<<endl;
	return 0;
}
