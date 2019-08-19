#include <cstring>
#include "dma.h"

BassDMA::BassDMA(const char* l, int r)
{
	label = new char [std::strlen(l)+1];
	std::strcpy(label, l);
	rating = r;
}

BassDMA::BassDMA(const BassDMA &rs)
{
	label = new char [std::strlen(rs.label)+1];
	std::strcpy(label, rs.label);//  TODO 作用域在std中
	rating = rs.rating;
}

BassDMA::~BassDMA()
{
	delete [] label;
}

BassDMA & BassDMA::operator=(const BassDMA &rs)
{
	if(this == &rs)
	{
		return *this;
	}
	delete [] label;
	label = new char [std::strlen(rs.label)+1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream &os, const BassDMA &rs)
{
	os<<"Label: "<< rs.label <<std::endl;
	os<<"rating: "<< rs.rating <<std::endl;
	return os;
}

LacksDMA::LacksDMA(const char* c , const char* l , int r)
	:BassDMA(l , r)
{
	std::strncpy(color, c , 39); //TODO   拷贝到字符数组中
	color[39] = '\0';
}

LacksDMA::LacksDMA(const char* c, const BassDMA & rs)
	:BassDMA(rs)
{
	std::strncpy(color, c , COL_LEN-1);
	color[COL_LEN-1] = '\0';
}

std::ostream & operator<<(std::ostream &os, const LacksDMA &rs)
{
	os<<(const BassDMA &) rs;
	os<<" color:"<<rs.color<<std::endl;
	return os;
}


hasDMA::hasDMA(const char* s , const char* l, int r)
	:BassDMA(l,r)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const BassDMA& rs)
	:BassDMA(rs)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs)
	:BassDMA(hs)
{
	style = new char[std::strlen(hs.style)+1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator = (const hasDMA &rs)
{
	if(this == &rs)
	{
		return *this;
	}
	BassDMA::operator = (rs);
	delete [] style;
	style = new char[std::strlen(rs.style)+1];
	std::strcpy(style, rs.style);
	return *this;

}

std::ostream & operator<<(std::ostream &os, const hasDMA &rs)
{
	os<<(const BassDMA &) rs;
	os<<" style:"<<rs.style<<std::endl;
	return os;
}