#include "ex11_04_time.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes/60;
	minutes %= minutes%60;
}

void Time::AddHr(int h)
{
	hours+=h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

// Time Time::operator+( const Time & t) const
// {
// 	Time sum;
// 	sum.minutes = minutes + t.minutes;
// 	sum.hours = hours + t.hours + sum.minutes/60;
// 	sum.minutes = sum.minutes%60;
// 	return sum;
// }

// Time Time::operator-( const Time & t) const
// {
// 	Time diff;
// 	int tot1, tot2;
// 	tot1 = t.minutes + 60*t.hours;
// 	tot2 = minutes + 60*hours;
// 	diff.minutes = (tot2 - tot1) % 60;
// 	diff.hours = (tot2 - tot1)/ 60;
// 	return diff;
// }

Time operator+( const Time & t, const Time & ti)
{
	Time sum;
	sum.minutes = ti.minutes + t.minutes;
	sum.hours = ti.hours + t.hours + sum.minutes/60;
	sum.minutes = sum.minutes%60;
	return sum;
}
Time operator-( const Time & t, const Time & ti)
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60*t.hours;
	tot2 = ti.minutes + 60*ti.hours;
	diff.minutes = (tot1 - tot2) % 60;
	diff.hours = (tot1 - tot2)/ 60;
	return diff;
}


// Time Time::operator*( double n) const
// {
// 	Time result;
// 	long totalminutes = hours*n*60 + minutes*n;
// 	result.minutes = totalminutes%60;
// 	result.hours = totalminutes/60;
// 	return result;
// }

// Time operator*( double m, const Time & t)
// {
// 	return t*m;
// }
Time operator*( double m, const Time & t)
{
	Time result;
	long totalminutes = t.hours*m*60 + t.minutes*m;
	result.minutes = totalminutes%60;
	result.hours = totalminutes/60;
	return result;
}

Time operator*( const Time & t, double m)
{
	return m* t;
}

std::ostream & operator<<(std::ostream &os, const Time &t)
{
	os<<t.hours<<"  hours, "<<t.minutes<<"  minutes";
	return os;
}