/*********************************
从文化中读取字符串  空格 换行 制标符等分割
*********************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;
const int NUM = 26;

const string wordlist[NUM] = {
	"apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage", "health",
	"insult", "jackal", "keeper", "loaner", "manager", "nonce", "onset", "plaid",
	"quilt", "remote", "stolid", "train", "useful", "valid", "whence", "xenon",
	"yearn", "zippy"
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	using std::tolower;
	std::srand(std::time(0)); //TODO 什么原理

	char play;
	cout<<"will you play a word game?\n";
	cin>>play;
	play = tolower(play);
	while(play == 'y')
	{
		string targe = wordlist[std::rand()%NUM];
		int length = targe.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout<<"Guess my secret word, It has"<<length
			<<"letters, and you guess \n"
			<<"one letter at a time. you get"<<guesses
			<<"wrong guesses \n"<<endl;
		cout<<"your world: "<<attempt<<endl;
		while(guesses >0 && attempt !=targe)
		{
			char letter;
			cout<<"Guess a letter:";
			cin>>letter;
			if(badchars.find(letter)!=string::npos 
				||attempt.find(letter)!= string::npos )
			{
				cout<<"you already guessed that. Try again. \n";
				continue;
			}
			int loc = targe.find(letter);
			if(loc == string::npos)
			{
				cout<<"Oh, bad guess. \n";
				--guesses;
				badchars += letter;
			}
			else
			{
				cout<<"Good guess! \n";
				attempt[loc] = letter;
				loc = targe.find(letter, loc+1);
				while(loc != string::npos)
				{
					attempt[loc] = letter;
					loc = targe.find(letter, loc+1);
				}
			}

			cout<<"your world: "<<attempt<<endl;
			if(attempt != targe)
			{
				if(badchars.length() >0)
				{
					if(badchars.length() >0)
					{
						cout<<"Bad choices:"<<badchars<<endl;
						cout<<guesses<<" bad guesses left \n";
					}
				}
			}
		}
		if(guesses>0)
		{
			cout<<"That's right. \n";
		}
		else
		{
			cout<<"Sorry, the world is "<<targe<<"\n";
			cout<<"will you play another? <y/n>:";
			cin>>play;
			play= tolower(play);
		}
	}
	cout<<"Bye !\n";
	return 0;
}