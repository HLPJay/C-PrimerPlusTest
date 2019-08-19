#include <cstring>
#include "ex12_string.h"

using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()//TODO static成员函数
{
	return num_strings;
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str,s);
	num_strings++;
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}


// String::String()
// {
// 	len = 0;
// 	str = n;// with C++11 str = nullptr
// }
String::String(const String &st)//复制构造
{
	num_strings++;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete [] str;
}

String String::operator= (const String &st) //赋值构造
{
	if(this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
	return *this;
}

String String::operator= (const char *s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)
{
	return str[i];//char数组的存储方式来取
}

const char &String::operator[](int i) const //TODO const成员函数
{
	return str[i];
}

bool operator<(const String &st, const String &st2)
{
	return (std::strcmp(st.str, st2.str)<0);
}

bool operator>(const String &st, const String &st2)
{
	return st2<st;
}

bool operator==(const String &st, const String &st2)
{
	return (std::strcmp(st.str, st2.str) == 0);
}
ostream & operator <<(ostream & os, const String &st)
{
	os<<st.str;
	return os;
}

istream & operator>>(istream & is, String &st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);//TODO get使用方法
	if (is)
	{
		st = temp;
	}
		
	while(is && is.get()!='\n')
	{
		continue;
	}
	return is;
}

// if(!cin||temp[0]=='\0')  检测空行