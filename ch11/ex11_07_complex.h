#ifndef EX11_07_COMPLEX_H_
#define EX11_07_COMPLEX_H_

#include <iostream>

namespace COMPLEX
{
	class complex
	{
	private:
		double realNumber;
		double imaginaryNumber;
	public:
		complex(double r,double i);
		complex();
		// 重载加减乘
		complex operator+(const complex & c) const;
		complex operator-(const complex & c) const;
		complex operator*(const complex & c) const;
		complex operator~() const;
		complex operator*(int i);
		friend complex operator *(int i, complex & c);
		//重载输入输出
		friend std::istream & operator >>(std::istream & is, complex& c);
		friend std::ostream & operator <<(std::ostream & os, const complex& c);
	};
}
#endif