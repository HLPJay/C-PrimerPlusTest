#include <iostream>
#include "friendClassTv1.h"

bool Tv::volup()
{
	if(volume <MaxVal)
	{
		volume++;
		return true;
	}
	return true;
}

bool Tv::voldown()
{
	if(volume <MinVal)
	{
		volume--;
		return true;
	}
	return true;
}

void Tv::chanup()
{
	if(channel <maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 1;
	}
}

void Tv::chandown()
{
	if(channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;
	}
}

void Tv::settings() const
{
	std::cout<<"TV is "<<(state == Off?"off":"on")<<std::endl;
	if(state == On)
	{
		std::cout<<"volume settings: "<< volume<<std::endl;
		std::cout<<"channel settings: "<< channel<<std::endl;
		std::cout<<"Mode = "<< (mode == Antenna? "Antenna" :"Cable")<<std::endl;
		std::cout<<"Input = "<< (input==TV? "TV": "DVD")<<std::endl;
	}
}