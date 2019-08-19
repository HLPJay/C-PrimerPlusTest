#include "ex11_01_vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan; //知道正切值 求弧度
using std::atan2;
using std::cout;
//TODO :极坐标   以及atan
namespace VECTOR
{
	const double Rad_to_deg = 45.0/atan(1.0);
	Vector::Vector()
	{
		// x = y = mag = ang = 0.0;
		x = y = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if(form = RECT)
		{
			x = n1;
			y = n2;
			// set_mag();
			// set_ang();
		}
		else if(form = POL)
		{
			x = n1;
			y = n2/Rad_to_deg;
			// set_mag();
			// set_ang();
		}
		else
		{
			cout<<"Incorrect 3th argument to Vector() --";
			cout<<"vector set to 0 \n";
			// x = y = mag = ang = 0.0;
			x = y = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{

	}

	// void Vector::set_mag()
	// {
	// 	mag = sqrt(x*x+y*y);
	// }

	// void Vector::set_ang()
	// {
	// 	if(x == 0.0&& y == 0.0)
	// 	{
	// 		ang = 0.0;
	// 	}
	// 	else
	// 	{
	// 		ang = atan2(x, y); 
	// 	}
	// }

	// void Vector::set_x()
	// {
	// 	x = mag* cos(ang); 
	// }

	// void Vector::set_y()
	// {
	// 	y = mag* sin(ang);
	// }

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if(form = RECT)
		{
			x = n1;
			y = n2;
			// set_mag();
			// set_ang();
		}
		else if(form = POL)
		{
			x = n1;
			y = n2/Rad_to_deg;
			// set_mag();
			// set_ang();
		}
		else
		{
			cout<<"Incorrect 3th argument to Vector() --";
			cout<<"vector set to 0 \n";
			// x = y = mag = ang = 0.0;
			x = y = 0.0;
			mode = RECT;
		}
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(b.x+x, b.y+y);
	}

	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x-b.x, y-b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(x*n, y*n);
	}

	Vector operator*(double n, const Vector &a)
	{
		return a*n;
	}

	std::ostream & operator<<(std::ostream &os, const Vector &v)
	{
		if(v.mode == Vector::RECT)
		{
			os<<"(x,y) = ("<< v.x <<" , "<<v.y<<")";
		}
		else if(v.mode == Vector::POL)
		{
			// os<<"(m,a) = ("<< v.mag << ",  "<<v.ang*Rad_to_deg<<")";
			os<<"(m,a) = ("<< v.magval() << ",  "<<v.magval()*Rad_to_deg<<")";
		}
		else
			os<<"Vector object mode is invalid.";
		return os;
	}
} //end namespace VECTOR

			