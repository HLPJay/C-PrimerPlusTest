/****************************
使用私有继承的方法实现 has-a关系
私有继承练习
****************************/

#ifndef STUDENT_PRIVATE_H_
#define STUDENT_PRIVATE_H_

#include <string>
#include <iostream>
#include <valarray>

class Student : private std::string , private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream & arr_out(std::ostream &os) const;
public:
	Student(): std::string("null student"), ArrayDb(){}
	explicit Student(const std::string & s):std::string(s), ArrayDb(){}
	explicit Student(int n):std::string("Nully"), ArrayDb(n){}
	Student(const std::string & s, int n):std::string(s), ArrayDb(){}
	Student(const std::string & s, ArrayDb& a):std::string(s), ArrayDb(a){}
	Student(const char* str, const double *pd, int n): std::string(str), ArrayDb(pd, n){}
	~Student() {};

	double Average() const;
	double  & operator[](int i);
	double operator[](int i) const;
	const std::string & Name() const;

	friend std::istream & operator>>(std::istream & is, Student &stu);
	friend std::istream & getline(std::istream & is, Student &stu);
	friend std::ostream & operator<<(std::ostream & os, const Student &stu);
};

#endif