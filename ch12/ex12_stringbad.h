#ifndef EX12_01_STRINGBAD_H_
#define EX12_01_STRINGBAD_H_
#include <iostream>

class StringBad
{
private:
	char *str;
	int len;
	static int num_strings;   //静态类成员
public:
	StringBad(const char* s);
	StringBad();
	~StringBad();

	friend std::ostream & operator <<(std::ostream & os, const StringBad &st);

};
#endif