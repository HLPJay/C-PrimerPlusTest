#include "ex11_07_complex.h"
namespace COMPLEX
{
	complex::complex(double r,double i)
	{
		realNumber = r;
		imaginaryNumber = i;
	}
	complex::complex()
	{
		realNumber = 0;
		imaginaryNumber = 0;
	}
	complex complex::operator+(const complex & c) const
	{
		complex sum;
		sum.realNumber = realNumber +c.realNumber;
		sum.imaginaryNumber = imaginaryNumber +c.imaginaryNumber;
		return sum;
	}
	complex complex::operator-(const complex & c) const
	{
		complex diff;
		diff.realNumber = realNumber -c.realNumber;
		diff.imaginaryNumber = realNumber -c.imaginaryNumber;
		return diff;
	}
	complex complex::operator*(const complex & c) const
	{
		complex result;
		result.realNumber = realNumber*c.realNumber - imaginaryNumber*c.imaginaryNumber;
		result.imaginaryNumber = realNumber*c.imaginaryNumber +c.realNumber*imaginaryNumber;
		return result;
	}

	complex complex::operator~() const
	{
		complex negate;
		negate.realNumber = realNumber;
		negate.imaginaryNumber = -imaginaryNumber;
		return negate;
	}
	complex complex::operator*(int i)
	{
		complex result;
		result.realNumber = i*this->realNumber;
		result.imaginaryNumber = i*this->imaginaryNumber;
		return result;
	}

	complex operator*(int i, complex & c)
	{
		return c*i; //TODO :这里c不能const
	}

	//重载输入输出
	std::istream & operator>>(std::istream & is, complex& c)
	{
		std::cout<<"real:";
		is>>c.realNumber;
		std::cout<<"imaginary:";
		is>>c.imaginaryNumber;
		return is;
	}
	std::ostream & operator<<(std::ostream & os,const complex& c)
	{
		os<<"("<<c.realNumber<<","<<c.imaginaryNumber<<"i)"; //默认不输出小数点后面的
		return os;
	}
}