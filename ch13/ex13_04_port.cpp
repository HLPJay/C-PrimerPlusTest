
#include "ex13_04_port.h"
#include <cstring>

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[std::strlen(br)+1];
	std::strcpy(brand, br);
	std::strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[std::strlen(p.brand)+1];
	std::strcpy(brand, p.brand);
	std::strncpy(style, p.style, std::strlen(p.style)+1);
	bottles = p.bottles;
}

Port::~Port()
{
	delete [] brand;
}

Port & Port::operator=(const Port &p)
{
	if(this == &p)
	{
		return *this;
	}
	delete [] brand;
	brand = new char[std::strlen(p.brand)+1];
	std::strcpy(brand, p.brand);
	std::strncpy(style, p.style, std::strlen(p.style)+1);
	bottles = p.bottles;
}

Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void Port::Show() const
{
	std::cout<<"Port--->brand :"<<brand<<std::endl;
	std::cout<<"Port--->style :"<<style<<std::endl;
	std::cout<<"Port--->bottles :"<<bottles<<std::endl;
}

ostream & operator<<(ostream& os, const Port & p)
{
	os<<"Port--->brand :"<<p.brand<<endl;
	os<<"Port--->style :"<<p.style<<endl;
	os<<"Port--->bottles :"<<p.bottles<<endl;
	return os;
}

VintagePort::VintagePort()
	:Port()
{
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nm, int y)
	:Port(br, "vintage", b)
{
	nickname = new char[std::strlen(nm)+1];
	std::strcpy(nickname, nm);
	year = y;
}

VintagePort::VintagePort(const VintagePort &vp)
	:Port(vp)
{
	nickname = new char[std::strlen(vp.nickname)+1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort::~VintagePort()
{
	delete [] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if(this == & vp)
	{
		return *this;
	}
	delete [] nickname;
	Port::operator=(vp);
	nickname = new char[std::strlen(vp.nickname)+1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	std::cout<<"VintagePort--->nickname :"<<nickname<<std::endl;
	std::cout<<"VintagePort--->year :"<<year<<std::endl;
}

ostream & operator<<(ostream& os, const VintagePort & p)
{
	os<<(const Port &) p;
	os<<"VintagePort--->nickname :"<<p.nickname<<std::endl;
	os<<"VintagePort--->year :"<<p.year<<std::endl;
	return os;
}