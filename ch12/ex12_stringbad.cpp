	#include <cstring>
	#include "ex12_stringbad.h"
	using std::cout;
	using std::endl;

	int StringBad::num_strings =0;  //TODO 静态变量的初始化,不能在类声明中初始化静态成员变量
	StringBad::StringBad(const char* s)
	{
		len = std::strlen(s);
		str = new char[len+1];
		std::strcpy(str,s);
		num_strings++;
		cout<<"num_strings::"<<num_strings<<"   str :"<<str<<endl;
	}

	StringBad::StringBad()
	{
		len = 4;
		str = new char[4];
		strcpy(str,"C++");
		num_strings++;
		cout<<"num_strings::"<<num_strings<<"   str :"<<str<<"default be created"<<endl;
	}

	StringBad::~StringBad()
	{
		--num_strings;
		cout<<"~num_strings::"<<num_strings<<"   str :"<<str<<"be delete"<<endl;
		delete [] str;
	}

	std::ostream & operator <<(std::ostream & os, const StringBad &st)
	{
		os<<st.str;
		return os;
	}