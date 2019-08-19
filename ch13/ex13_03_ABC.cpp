#include <cstring>
#include "ex13_03_ABC.h"


ABC::ABC(const char* l, int r)
{
	label = new char [std::strlen(l)+1];
	std::strcpy(label, l);
	rating = r;
}

ABC::ABC(const ABC &rs)
{
	label = new char [std::strlen(rs.label)+1];
	std::strcpy(label, rs.label);//  TODO 作用域在std中
	rating = rs.rating;
}

ABC::~ABC()  //TODO =0纯虚函数
{
	delete [] label;
}

void ABC::View()
{
	std::cout<<" ABC base:  "<<std::endl;
	std::cout<<" label:  "<<label<<std::endl;
	std::cout<<" rating:  "<<rating<<std::endl;
}

ABC & ABC::operator=(const ABC &rs)
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

std::ostream & operator<<(std::ostream &os, const ABC &rs)
{
	os<<"Label: "<< rs.label <<std::endl;
	os<<"rating: "<< rs.rating <<std::endl;
	return os;
}

//TODO 这里其实就是默认的
BassDMA::BassDMA(const char* l, int r)
	:ABC(l,r)
{}
BassDMA::BassDMA(const BassDMA &rs)
	:ABC(rs)
{}
BassDMA::~BassDMA()
{}

BassDMA &BassDMA::operator=(const BassDMA &rs)
{
	if(this == &rs)
		return *this;
	ABC::operator=(rs);
	return *this;
}

std::ostream & operator<<(std::ostream &os, const BassDMA &rs)
{
	os<<(const ABC&)rs;
	return os;
}


LacksDMA::LacksDMA(const char* c , const char* l , int r)
	:ABC(l , r)
{
	std::strncpy(color, c , 39); //TODO   拷贝到字符数组中
	color[39] = '\0';
}

LacksDMA::LacksDMA(const char* c, const BassDMA & rs)
	:ABC(rs)
{
	std::strncpy(color, c , COL_LEN-1);
	color[COL_LEN-1] = '\0';
}

void LacksDMA::View()
{
	std::cout<<" LacksDMA base:  "<<std::endl;
	ABC::View();
	std::cout<<"color :"<<color<<std::endl;
	return ;
}

LacksDMA &LacksDMA::operator=(const LacksDMA &rs)
{
	if(this == &rs)
		return *this;
	ABC::operator=(rs);
	std::strncpy(color, rs.color , COL_LEN-1);
	color[COL_LEN-1] = '\0';
	return *this;
}

std::ostream & operator<<(std::ostream &os, const LacksDMA &rs)
{
	os<<(const ABC &) rs;
	os<<" color:"<<rs.color<<std::endl;
	return os;
}



hasDMA::hasDMA(const char* s , const char* l, int r)
	:ABC(l,r)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
	std::cout<<"TTTTTTTTTTTTTTTT"<<style<<std::endl;
}

hasDMA::hasDMA(const char* s, const BassDMA& rs)
	:ABC(rs)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs)
	:ABC(hs)
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
	ABC::operator = (rs);
	delete [] style;
	style = new char[std::strlen(rs.style)+1];
	std::strcpy(style, rs.style);
	return *this;
}

void hasDMA::View()
{
	std::cout<<" hasDMA base:  "<<std::endl;
	ABC::View();
	std::cout<<"style :"<<style<<std::endl;
}

std::ostream & operator<<(std::ostream &os, const hasDMA &rs)
{
	os<<(const ABC &) rs;
	os<<" style:"<<rs.style<<std::endl;
	return os;
}