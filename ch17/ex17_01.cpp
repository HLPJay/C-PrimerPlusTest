#include <iostream>
#include <cstring>
const int Limit = 255;

int main(void)
{
	using namespace std;
	
	char input[Limit];
	cin.get(input, Limit, '$');//get 不会丢弃换界符号 getline会丢弃
	cout<<"TTT:"<<input<<endl;


	cout<<strlen(input)<<endl;
	return 0;
}
