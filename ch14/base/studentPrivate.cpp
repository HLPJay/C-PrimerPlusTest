
#include "studentPrivate.h"

using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::cin;
using std::string;

std::ostream & Student::arr_out(std::ostream &os) const
{
	int i;
	int lim = ArrayDb::size();
	if(lim >0)
	{
		for(i = 0; i<lim; i++)
		{
			os<<ArrayDb::operator[](i)<<" ";
			if(i%5 == 4)
				os<<endl;
		}
		if(i%5 != 0)
			os<<endl;
	}
	else
		os<<"empty array.";
	return os;
}

double Student::Average() const
{
	if(ArrayDb::size() > 0)
		return ArrayDb::sum()/ArrayDb::size();
	else
		return 0;
}

double  & Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

const std::string & Student::Name() const
{
	return (const std::string &) *this;
}

//TODO 访问基类的友元函数
std::istream & operator>>(std::istream & is, Student &stu)
{
	is>>(std::string &)stu;//强制类型转换赋值和取值
	return is;
}

std::istream & getline(std::istream & is, Student &stu)
{
	getline(is, (std::string &)stu);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Student &stu)
{
	os<<"Scores for "<<(std::string &)stu<<" is: \n";
	stu.arr_out(os);
	return os;
}