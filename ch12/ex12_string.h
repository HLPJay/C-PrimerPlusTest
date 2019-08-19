#ifndef EX12_01_STRING_H_
#define EX12_01_STRING_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	//TODO  使用深度复制的方法构造复制构造函数和赋值构造函数
	String(const char* s);
	String();
	String(const String &);
	~String();

	int length() const
	{
		return len;
	}
	String operator= (const String &);
	String operator= (const char *);
	char & operator[](int i);
	const char &operator[](int i) const;//TODO const成员函数

	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator <<(ostream & os, const String &st);
	friend istream & operator >>(istream & is, String &st);

	static int HowMany();//TODO static成员函数

};

#endif