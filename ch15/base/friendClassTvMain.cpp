#include <iostream>
#include "friendClassTv1.h"

int main(void)
{
	Tv s42;
	std::cout<<"initial setting for 42 TV: \n";
	s42.settings();
	s42.onoff();
	s42.chanup();

	std::cout<<"\nAdjusted setting for 42 TV: \n";
	s42.chanup();
	std::cout<<"\nAdjusted setting for 42 TV: \n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	std::cout<<"\nsetting after for 42 TV by Remote: \n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 42);
	std::cout<<"\n\n 58 settings: \n";
	s58.settings();
	return 0;
}