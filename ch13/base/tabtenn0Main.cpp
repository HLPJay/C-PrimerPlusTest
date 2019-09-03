#include <iostream>
#include "tabtenn0.h"

int main(void)
{
	using std::cout;
	TableTennisPlayer play1("Chuk", "Blizzard", true);
	TableTennisPlayer play2("Tara", "Boomdea", false);
	play1.Name();

	if(play1.HasTable())
		cout<<": has a table \n";
	else
		cout<<": hasn't a table \n";
	play2.Name();

	if(play2.HasTable())
		cout<<": has a table \n";
	else
		cout<<": hasn't a table \n";


	RatePlayer rplayer(1140, "Mollory", "Duck", true);
	rplayer.Name();
	if(rplayer.HasTable())
		cout<<": has a table \n";
	else
		cout<<": hasn't a table \n";
	cout<<"Name:";
	rplayer.Name();
	cout<<"; Rating:"<<rplayer.Rating()<<endl;

	RatePlayer rplayer1(1112, play1);
	cout<<"Name:";
	rplayer1.Name();
	cout<<"; Rating:"<<rplayer1.Rating()<<endl;
	return 0;
}