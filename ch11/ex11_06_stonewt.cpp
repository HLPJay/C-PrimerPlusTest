#include <iostream>
#include "ex11_06_stonewt.h"
using std::cout;

Stonewt::Stonewt(double lbs, Flag falg)
{
	stone = int(lbs) /Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	flag = falg;
}

Stonewt::Stonewt(int stn, double lbs, Flag falg)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn*Lbs_per_stn + lbs;
	flag = falg;
}

Stonewt::Stonewt()
{
	stone = pds_left = pounds = 0;
	flag = STONE;
}

Stonewt::~Stonewt()
{

}


Stonewt::operator int() const
{
	return int(pounds+0.5);
}

Stonewt::operator double() const
{
	return pounds;
}

std::ostream & operator<<(std::ostream &os, const Stonewt &t)
{
	if(t.flag == Stonewt::STONE)
	{
		os<<t.stone<<" stone, "<<t.pds_left <<"  pounds\n";
	}else if(t.flag == Stonewt::INT_FORMAT)
	{
		os<<"Convert to int => "<<int(t.pounds+0.5)<<"  pounds\n";
	}else if(t.flag == Stonewt::DOUBLE_FORMAT)
	{
		os<<"Convert to double => "<<t.pounds<<"  pounds\n";
	}else
	{
		os<<"ERROR of flag";
	}
	return os;
}