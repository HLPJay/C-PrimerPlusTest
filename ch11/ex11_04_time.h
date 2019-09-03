#ifndef EX11_04_TIME_H_
#define EX11_04_TIME_H_

#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m =0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m=0);
	// Time operator+( const Time & t) const;
	// Time operator-( const Time & t) const;
	// Time operator*( double n) const;

	friend Time operator+( const Time & t, const Time & ti);
	friend Time operator-( const Time & t, const Time & ti);
	friend Time operator*( double m, const Time & t);
	friend Time operator*( const Time & t, double m);
	friend std::ostream & operator<<(std::ostream &os, const Time &t);
};
#endif //EX11_04_TIME_H_