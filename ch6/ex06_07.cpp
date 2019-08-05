/**************************
输入：每次读取一个单词，直到只输入q
输出：指出多少个以元音字母开头，多少个以辅音字母开头
***************************/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main(void)
{
	string word;
	int vowelWord,consonantsWord,othersWord;
	vowelWord = consonantsWord = othersWord = 0;
	cout<<"please input the word,end with q:";
	cin>>word;
	while(word != "q")
	{
		char ch = word[0];
		if(!isalpha(ch))
		{
			othersWord++;
		}else
		{
			switch(ch)
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':vowelWord++;break;
				default:consonantsWord++; break;
			}
		}
		
		cin>>word;
	}
	cout<< vowelWord <<" words beginning with vowels"<<endl;
	cout<< consonantsWord <<" words beginning with consonants"<<endl;
	cout<< othersWord << " others"<<endl;
	return 0;
}