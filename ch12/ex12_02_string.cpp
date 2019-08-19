#include <cstring>
#include <cctype>  //ctype.h
#include "ex12_02_string.h"

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


String String::operator+(const String & st)//TODO  活用构造函数
{
	int len = std::strlen(str)+ std::strlen(st.str);
	char *str_num = new char[len+1];
	strcpy(str_num, str);
	strcat(str_num, st.str);

	String temp;
	temp = str_num;
	return temp;
}

String String::operator+(const char * c) //这种类型的要注意用friend适当类型
{
	String temp= c;
	String sum = *this+temp;
	return sum;
}

String operator+(const char * c, String &st )
{
	return st+c;
}

bool String::StringLow()
{
	for(int i=0;i<len;i++)
	{
		if(std::isupper(str[i])) //TODO 需要整理相关的转换函数
		{
			str[i] = std::tolower(str[i]);
		}
	}
}

bool String::ToUpper()
{
	for(int i=0;i<len;i++)
	{
		if(std::islower(str[i]))
		{
			str[i] = std::toupper(str[i]);
		}
	}
}

int String::GetCharNum(char c)
{
	int sum = 0;;
	for(int i=0;i<len;i++)
	{
		if(str[i] == c)
		{
			++sum;
		}
	}
	return sum;
}