
#include "ex13_01_cd.h"
#include <cstring>
Cd::Cd(const char *s1,const char *s2, int n, double x)
{
	// std::strncpy(performer, s1, 49);
	// performer[49] = '\0';
	// std::strncpy(label, s2, 19);
	// label[19] = '\0';
	performer = new char(std::strlen(s1)+1);
	std::strcpy(performer, s1);
	label = new char(std::strlen(s2)+1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd &d)
{
	// std::strncpy(performer, d.performer, 49); //或者std::strlen(d.performer)
	// performer[49] = '\0';
	// std::strncpy(label, d.label, 19);
	// label[19] = '\0';
	performer = new char(std::strlen(d.performer)+1);
	std::strcpy(performer, d.performer);
	label = new char(std::strlen(d.label)+1);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	// performer[0] = '\0';
	// label[0] = '\0';
	performer = new char[1];
	performer[0] = '\0';   //TODO  performer = 0的区别？
	label = new char[1];
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete [] performer;
	delete [] label;
}

void Cd::Report() const
{
	std::cout<<"performer ----->"<<performer<<std::endl;
	std::cout<<"label ----->"<<label<<std::endl;
	std::cout<<"selections ----->"<<selections<<std::endl;
	std::cout<<"playtime ----->"<<playtime<<std::endl;
}

Cd & Cd::operator=(const Cd &cd)
{
	if(this == &cd)
		return *this;
	// std::strncpy(performer, cd.performer, std::strlen(cd.performer)+1); //或者std::strlen(d.performer)
	// std::strncpy(label, cd.label, std::strlen(cd.label)+1);//TODO  这里加1 的位置

	performer = new char(std::strlen(cd.performer)+1);
	std::strcpy(performer, cd.performer);
	label = new char(std::strlen(cd.label)+1);
	std::strcpy(label, cd.label);
	selections = cd.selections;
	playtime = cd.playtime;
}


classic::classic(const char *s1,const char *s2,const char *s3, int n, double x)
	:Cd(s2,s3,n,x)
{
	mainStr = new char[std::strlen(s1)+1];
	strcpy(mainStr,s1);
}

classic::classic(const classic& c)
	:Cd(c)
{
	mainStr = new char[std::strlen(c.mainStr)+1];
	strcpy(mainStr, c.mainStr);
}

classic::classic()
	:Cd()
{
	mainStr = new char[1];
	mainStr[0] = '\0';
}

classic::~classic()
{
	delete []mainStr;
}

void classic::Report() const
{
	Cd::Report();
	std::cout<<"mainStr ----->"<<mainStr<<std::endl;
}

classic & classic::operator=(const classic &cd)
{
	if(this == &cd)
		return *this;
	Cd::operator=(cd);
	mainStr = new char[std::strlen(cd.mainStr)+1];
	strcpy(mainStr, cd.mainStr);
	return *this;
}